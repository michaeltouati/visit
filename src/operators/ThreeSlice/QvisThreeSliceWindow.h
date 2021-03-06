// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef QVISTHREESLICEWINDOW_H
#define QVISTHREESLICEWINDOW_H

#include <QvisOperatorWindow.h>
#include <AttributeSubject.h>

class ThreeSliceAttributes;
class QLabel;
class QCheckBox;
class QLineEdit;

// ****************************************************************************
// Class: QvisThreeSliceWindow
//
// Purpose:
//    Defines QvisThreeSliceWindow class.
//
// Notes:      Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class QvisThreeSliceWindow : public QvisOperatorWindow
{
    Q_OBJECT
  public:
    QvisThreeSliceWindow(const int type,
                         ThreeSliceAttributes *subj,
                         const QString &caption = QString::null,
                         const QString &shortName = QString::null,
                         QvisNotepadArea *notepad = 0);
    virtual ~QvisThreeSliceWindow();
    virtual void CreateWindowContents();
  protected:
    void UpdateWindow(bool doAll);
    virtual void GetCurrentValues(int which_widget);
  private slots:
    void xProcessText();
    void yProcessText();
    void zProcessText();
    void interactiveChanged(bool val);
  private:
    QLineEdit *x;
    QLineEdit *y;
    QLineEdit *z;
    QCheckBox *interactive;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *zLabel;

    ThreeSliceAttributes *atts;
};



#endif
