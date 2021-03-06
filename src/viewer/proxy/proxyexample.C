// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <ViewerProxy.h>
#include <ViewerMethods.h>
#include <ViewerState.h>

#include <ObserverToCallback.h>
#include <PluginManagerAttributes.h>
#include <SyncAttributes.h>
#include <Connection.h>
#include <PlotPluginManager.h>
#include <OperatorPluginManager.h>
#include <DebugStream.h>

// ****************************************************************************
// Class: VisItClient
//
// Purpose:
//   Base class for C++ programs that want to set up visualizations in VisIt.
//
// Notes:      
//  1. We're using scripting plugins, which require the app to be linked
//     with the Python library. We'd like to avoid this but the alternative
//     gui or viewer plugins are less desireable. Of course, you could always
//     extend the XML tools to generate a new class of plugin for your 
//     application. However, you'd also have to extend the plot and operator
//     plugin managers.
//
//  2. You can't directly use the plugin attributes state objects because
//     you'd have to link them into your program. Instead, use the provided
//     PluginAttributesAccessor class to get/set values in your Work() function.
//     Embedded AttributeSubjects in the plugin attributes are not currently
//     accessible with the PluginAttributesAccessor but you could extend it.
//
//  3. If you call Execute on an instance of this class, it will return. You
//     could then use the object inside an event based application such as a 
//     GUI. You could periodically call Synchronize to pick up new state from
//     the viewer. If you want to implement a non-polling read from the viewer,
//     you can expose the viewer proxy's write connection and get the socket
//     id for use in your own code. When the socket needs to be read, call
//     ViewerProxy::ProcessInput() to read the socket and update the state 
//     objects.
//
// Programmer: Brad Whitlock
// Creation:   Thu Mar 13 11:21:35 PDT 2008
//
// Modifications:
//   Brad Whitlock, Tue Jun 24 14:30:50 PDT 2008
//   Get the plugin managers from the viewer proxy. Load the plugin info.
//
//   Brad Whitlock, Thu Feb 24 16:43:44 PST 2011
//   I added a -dir command line argument.
//
// ****************************************************************************

class VisItClient
{
public:
    // Constructor
    VisItClient()
    {
        viewer = 0;
        loadPlugins = 0;
        loadedPlugins = false;
        syncTag = 100;
    }

    // Destructor
    virtual ~VisItClient()
    {
        delete viewer;
        delete loadPlugins;
    }

    // Starts the viewer and executes your Work function
    void Execute(int *argc, char ***argv)
    {
        std::string visitProgram("visit");

        if(viewer != 0)
            return;

        // Let the user override the program we use for VisIt on the command line.
        for(int i = 0; i < *argc; ++i)
        {
            char **argv2 = *argv;
            if(strcmp(argv2[i], "-dir") == 0 && (i+1) < *argc)
            {
                visitProgram = std::string(argv2[i+1]) + "/bin/visit";
                ++i;
            }
        }

        // Create the viewer proxy and launch the viewer.
        viewer = new ViewerProxy;
        viewer->InitializePlugins(PluginManager::Scripting);
        viewer->Create(visitProgram.c_str(), argc, argv);

        // Set up an observer that will call our LoadPlugins method
        // when the plugin manager attributes come from the viewer.
        loadPlugins = new ObserverToCallback(
            viewer->GetViewerState()->GetPluginManagerAttributes(),
            LoadPlugins,
            (void*)this);

        // Wait for synchronization
        Synchronize();

        // Show the viewer windows.
        viewer->GetViewerMethods()->ShowAllWindows();

        // Call the user's Work method.
        Work();
    }

    static const int INVALID_PLUGIN_INDEX;

protected:
    // Override this methd to create a program that does something.
    virtual void Work() { };

    typedef struct {int syncTag; bool waitForSync; } sync_data;

    // This method causes the code to block until the viewer has 
    // caught up with the client.
    void Synchronize()
    {
        GetViewerState()->GetSyncAttributes()->SetSyncTag(syncTag);
        GetViewerState()->GetSyncAttributes()->Notify();

        sync_data s;
        s.syncTag = syncTag;
        s.waitForSync = true;
        ObserverToCallback *sync = new ObserverToCallback(
            GetViewerState()->GetSyncAttributes(),
            CheckSync,
            (void*)&s);

        // An event loop
        while(s.waitForSync)
        {
            if(viewer->GetWriteConnection()->NeedsRead(true))
                viewer->ProcessInput();
        }

        delete sync;
        ++syncTag;
    }

    // This method enters an event loop in case you want to keep
    // VisIt around after your Work() function is done.
    void EventLoop()
    {
        while(true)
        {
            if(viewer->GetWriteConnection()->NeedsRead(true))
                viewer->ProcessInput();
        }
    }

    // Return the viewer methods object, which contains the methods
    // that you can call on the viewer.
    ViewerMethods *GetViewerMethods() { return viewer->GetViewerMethods(); }

    // Return the viewer state object, where you'll find the state
    // objects that you can use to modify the viewer's state.
    ViewerState   *GetViewerState()   { return viewer->GetViewerState(); }

    // Converts a plot plugin name to an index that you can pass to
    // functions such as AddPlot
    int PlotIndex(const std::string &name) const
    {
        return PluginIndex(viewer->GetPlotPluginManager(), name);
    }

    // Converts an operator plugin name to an index that you can pass to
    // functions such as AddOperator.
    int OperatorIndex(const std::string &name) const
    {
        return PluginIndex(viewer->GetOperatorPluginManager(), name);
    }

    // The viewer proxy object that you use to control the viewer.
    ViewerProxy   *viewer;
private:
    // Private callback function for loading plugins
    static void LoadPlugins(Subject *subj, void *data)
    {
        VisItClient *This = (VisItClient *)data;

        // We've received plugin attributes
        if(!This->loadedPlugins)
        {
            This->viewer->LoadPlugins();
            This->loadedPlugins = true;
        }
    }

    // Private callback function for synchronization
    static void CheckSync(Subject *subj, void *data)
    {
        SyncAttributes *s = (SyncAttributes *)subj;
        sync_data *sd = (sync_data*)data;
        if(s->GetSyncTag() == sd->syncTag)
            sd->waitForSync = false;
    }

    // Private helper function for turning plugin name to index.
    int PluginIndex(PluginManager *mgr, const std::string &name) const
    {
        for(int i = 0; i < mgr->GetNEnabledPlugins(); ++i)
        {
            if(mgr->GetPluginName(mgr->GetEnabledID(i)) == name)
                return i;
        }
        return INVALID_PLUGIN_INDEX;
    }

    ObserverToCallback *loadPlugins;
    bool                loadedPlugins;
    int                 syncTag;
};

const int VisItClient::INVALID_PLUGIN_INDEX = -1;

// ****************************************************************************
// Class: PseudocolorVis
//
// Purpose:
//   Implements a Work() function that sets up a Pseudocolor plot and saves
//   an image.
//
// Notes:      
//
// Programmer: Brad Whitlock
// Creation:   Thu Mar 13 11:26:48 PDT 2008
//
// Modifications:
//   Brad Whitlock, Wed Aug 20 11:11:14 PDT 2008
//   Removed PluginAttributesAccessor since the SetValue methods that it
//   provided have now been moved into the AttributeGroup class.
//
// ****************************************************************************

class PseudocolorVis : public VisItClient
{
public:
    PseudocolorVis() { }
    virtual ~PseudocolorVis() { }
protected:
    virtual void Work()
    {
        // Open a database
        GetViewerMethods()->InvertBackgroundColor();
        GetViewerMethods()->OpenDatabase("/usr/gapps/visit/data/noise.silo");
        Synchronize();

        // Create a plot and draw it.
        int plotType = PlotIndex("Pseudocolor");
        if(plotType != INVALID_PLUGIN_INDEX)
        {
            debug1 << "Plot type = " << plotType << endl;
            GetViewerMethods()->AddPlot(plotType, "hardyglobal");
      
            int threeSlice = OperatorIndex("ThreeSlice");
            if(threeSlice != INVALID_PLUGIN_INDEX)
                GetViewerMethods()->AddOperator(threeSlice);
            GetViewerMethods()->DrawPlots();
        }
        Synchronize();

        // Save an image.
        GetViewerMethods()->SaveWindow();

        // Set some pseudocolor plot attributes using the base class'
        // SetValue methods.
        AttributeSubject *pcAtts = GetViewerState()->GetPlotAttributes(plotType);
        if(pcAtts != 0)
        {
            pcAtts->SetValue("min", 1.5);
            pcAtts->SetValue("minFlag", true);
            pcAtts->SetValue("max", 4.5);
            pcAtts->SetValue("maxFlag", true);
            pcAtts->SetValue("colorTableName", "calewhite");
            pcAtts->Notify();
            GetViewerMethods()->SetPlotOptions(plotType);
        }

        // Save an image.
        GetViewerMethods()->SaveWindow();

        // Enter an event loop so the program keeps running and we can
        // interact with the viewer.
        EventLoop();
    }
};

///////////////////////////////////////////////////////////////////////////////
#include <VisItInit.h>
#include <VisItException.h>

// ****************************************************************************
// Method: main
//
// Purpose: 
//   Main function for the program.
//
// Programmer: Brad Whitlock
// Creation:   Thu Mar 13 11:27:19 PDT 2008
//
// Modifications:
//    Mark C. Miller, Thu Apr  3 14:36:48 PDT 2008
//    Moved setting of component name to before Initialize
//
//    Brad Whitlock, Wed Jun 25 13:37:20 PST 2008
//    Plugin managers are now part of ViewerProxy.
//
// ****************************************************************************

int
main(int argc, char *argv[])
{
    // Step 1: Initialize error logging.
    VisItInit::SetComponentName("proxyexample");
    VisItInit::Initialize(argc, argv, 0, 1, false);

    // Step 2: Create the object and enter its Execute method.
    PseudocolorVis vis;
    TRY
    {
        vis.Execute(&argc, &argv);
    }
    CATCH(VisItException)
    {
    }
    ENDTRY

    // Step 3: Finalize to close error logging, etc.
    VisItInit::Finalize();
}

///////////////////////////////////////////////////////////////////////////////
// Building:
//   To build this program, just type "make proxyexample" in the viewer/proxy
//   directory inside VisIt's source tree. This will cause the proxyexample
//   program to build and be put into the ../../exe directory.
//
//   If you want to build an example of your own based on an installed version
//   of VisIt, here are some flags that you can adapt for your Makefile:
//
//   CPPFLAGS=-I/path/to/visit/version/platform/include/visit
//   LD_FLAGS=-L/path/to/visit/version/platform/lib
//   LIBS=-lvisitcommon -lviewerproxy -lpython2.6
//
// Running:
//   Your program needs to know where to pick up VisIt's libraries. You can use
//   -rpath when building your application on Linux or you can specify the
//   directory containing the VisIt libraries at runtime with LD_LIBRARY_PATH 
//   (DYLD_LIBRARYPATH on MacOS X). In addition, VisIt requires the VISITPLUGINDIR
//   environment variable to be set.
//
//   env LD_LIBRARY_PATH=/path/to/visit/version/platform/lib VISITPLUGINDIR=/path/to/visit/version/platform/plugins proxyexample
//
//   (Command from visit's bin dir)
//   env DYLD_LIBRARY_PATH=../lib VISITPLUGINDIR=../plugins ../exe/proxyexample
//   
///////////////////////////////////////////////////////////////////////////////
