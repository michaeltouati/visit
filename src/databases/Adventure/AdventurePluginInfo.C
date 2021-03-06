// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: AdventurePluginInfo.C
// ****************************************************************************

#include <AdventurePluginInfo.h>

#include <visit-config.h>
VISIT_PLUGIN_VERSION(Adventure,DBP_EXPORT)

VISIT_DATABASE_PLUGIN_ENTRY(Adventure,General)

// ****************************************************************************
//  Method: AdventureGeneralPluginInfo::GetName
//
//  Purpose:
//    Return the name of the database plugin.
//
//  Returns:    A pointer to the name of the database plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
AdventureGeneralPluginInfo::GetName() const
{
    return "Adventure";
}

// ****************************************************************************
//  Method: AdventureGeneralPluginInfo::GetVersion
//
//  Purpose:
//    Return the version of the database plugin.
//
//  Returns:    A pointer to the version of the database plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
AdventureGeneralPluginInfo::GetVersion() const
{
    return "1.0";
}

// ****************************************************************************
//  Method: AdventureGeneralPluginInfo::GetID
//
//  Purpose:
//    Return the id of the database plugin.
//
//  Returns:    A pointer to the id of the database plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
AdventureGeneralPluginInfo::GetID() const
{
    return "Adventure_1.0";
}
// ****************************************************************************
//  Method: AdventureGeneralPluginInfo::EnabledByDefault
//
//  Purpose:
//    Return true if this plugin should be enabled by default; false otherwise.
//
//  Returns:    true/false
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

bool
AdventureGeneralPluginInfo::EnabledByDefault() const
{
    return true;
}
// ****************************************************************************
//  Method: AdventureGeneralPluginInfo::HasWriter
//
//  Purpose:
//    Return true if this plugin has a database writer.
//
//  Returns:    true/false
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

bool
AdventureGeneralPluginInfo::HasWriter() const
{
    return false;
}
// ****************************************************************************
//  Method:  AdventureGeneralPluginInfo::GetDefaultFilePatterns
//
//  Purpose:
//    Returns the default patterns for a Adventure database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
std::vector<std::string>
AdventureGeneralPluginInfo::GetDefaultFilePatterns() const
{
    std::vector<std::string> defaultPatterns;
    defaultPatterns.push_back("*.adv");
    defaultPatterns.push_back("*.inp");
    defaultPatterns.push_back("*.msh");

    return defaultPatterns;
}

// ****************************************************************************
//  Method:  AdventureGeneralPluginInfo::AreDefaultFilePatternsStrict
//
//  Purpose:
//    Returns if the file patterns for a Adventure database are
//    intended to be interpreted strictly by default.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
bool
AdventureGeneralPluginInfo::AreDefaultFilePatternsStrict() const
{
    return false;
}

// ****************************************************************************
//  Method:  AdventureGeneralPluginInfo::OpensWholeDirectory
//
//  Purpose:
//    Returns if the Adventure plugin opens a whole directory name
//    instead of a single file.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
bool
AdventureGeneralPluginInfo::OpensWholeDirectory() const
{
    return false;
}
