// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: RevolveGUIPluginInfo.C
// ****************************************************************************

#include <RevolvePluginInfo.h>
#include <RevolveAttributes.h>
#include <QApplication>
#include <QvisRevolveWindow.h>

VISIT_OPERATOR_PLUGIN_ENTRY(Revolve,GUI)

// ****************************************************************************
//  Method: RevolveGUIPluginInfo::GetMenuName
//
//  Purpose:
//    Return a pointer to the name to use in the GUI menu.
//
//  Returns:    A pointer to the name to use in the GUI menu.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QString *
RevolveGUIPluginInfo::GetMenuName() const
{
    return new QString(qApp->translate("OperatorNames", "Revolve"));
}


// ****************************************************************************
//  Method: RevolveGUIPluginInfo::CreatePluginWindow
//
//  Purpose:
//    Return a pointer to an operator's attribute window.
//
//  Arguments:
//    type      The type of the operator.
//    attr      The attribute subject for the operator.
//    notepad   The notepad to use for posting the window.
//
//  Returns:    A pointer to the operator's attribute window.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QvisPostableWindowObserver *
RevolveGUIPluginInfo::CreatePluginWindow(int type, AttributeSubject *attr,
    const QString &caption, const QString &shortName, QvisNotepadArea *notepad)
{
    return new QvisRevolveWindow(type, (RevolveAttributes *)attr,
        caption, shortName, notepad);
}

// ****************************************************************************
//  Method: RevolveGUIPluginInfo::XPMIconData
//
//  Purpose:
//    Return a pointer to the icon data.
//
//  Returns:    A pointer to the icon data.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

#include <Revolve.xpm>
const char **
RevolveGUIPluginInfo::XPMIconData() const
{
    return Revolve_xpm;
}

