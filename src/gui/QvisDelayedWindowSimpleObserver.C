// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <QvisDelayedWindowSimpleObserver.h>

// ****************************************************************************
// Method: QvisDelayedWindowSimpleObserver::QvisDelayedWindowSimpleObserver
//
// Purpose:
//   This is the constructor for the QvisDelayedWindowSimpleObserver class.
//
// Arguments:
//   caption : The name of the window.
//
// Programmer: Brad Whitlock
// Creation:   Mon Aug 27 12:42:10 PDT 2001
//
// Modifications:
//   Brad Whitlock, Mon Sep 30 07:50:41 PDT 2002
//   I added window flags.
//
//   Brad Whitlock, Wed Apr  9 10:31:03 PDT 2008
//   Changed ctor args.
//
//    Cyrus Harrison, Tue Jun 24 11:15:28 PDT 2008
//    Initial Qt4 Port.
//
// **************************************************************************** 

QvisDelayedWindowSimpleObserver::QvisDelayedWindowSimpleObserver(
    const QString &caption, Qt::WindowFlags f) : QvisDelayedWindow(caption, f),
    SimpleObserver()
{
    selectedSubject = 0;
}

// ****************************************************************************
// Method: QvisDelayedWindowSimpleObserver::~QvisDelayedWindowSimpleObserver
//
// Purpose:
//   The destructor for the QvisDelayedWindowSimpleObserver class.
//
// Programmer: Brad Whitlock
// Creation:   Mon Aug 27 12:42:10 PDT 2001
//
// Modifications:
//
// **************************************************************************** 

QvisDelayedWindowSimpleObserver::~QvisDelayedWindowSimpleObserver()
{
    // nothing here.
}

// ****************************************************************************
// Method: QvisDelayedWindowSimpleObserver::Udpate
//
// Purpose:
//   Updates the window when one of its subjects is updated.
//
// Programmer: Brad Whitlock
// Creation:   Mon Aug 27 12:42:10 PDT 2001
//
// Modifications:
//   Brad Whitlock, Thu Sep 12 12:15:24 PDT 2002
//   I added the selectedSubject member.
//
// **************************************************************************** 

void
QvisDelayedWindowSimpleObserver::Update(Subject *subj)
{
    // This is what derived types will query to determine which subject
    // was modified.
    selectedSubject = subj;

    if(isCreated)
        UpdateWindow(false);
}

// ****************************************************************************
// Method: QvisDelayedWindowSimpleObserver::SubjectRemoved
//
// Purpose: 
//   This method is called when one of the Window's subjects is deleted.
//
// Arguments:
//   TheRemovedSubject : A pointer to the subject being removed.
//
// Programmer: Brad Whitlock
// Creation:   Thu Sep 12 12:17:41 PDT 2002
//
// Modifications:
//   
// ****************************************************************************

void
QvisDelayedWindowSimpleObserver::SubjectRemoved(Subject *TheRemovedSubject)
{
    // nothing here.
}

// ****************************************************************************
// Method: QvisDelayedWindowSimpleObserver::SelectedSubject
//
// Purpose:
//   Returns which subject is currently being updated.
//
// Programmer: Brad Whitlock
// Creation:   Mon Aug 27 12:42:10 PDT 2001
//
// Modifications:
//
// **************************************************************************** 

Subject *
QvisDelayedWindowSimpleObserver::SelectedSubject()
{
    return selectedSubject;
}
