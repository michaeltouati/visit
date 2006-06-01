/*****************************************************************************
*
* Copyright (c) 2000 - 2006, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef PLOTQUERYINFO_H
#define PLOTQUERYINFO_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: PlotQueryInfo
//
// Purpose:
//    This class is a .
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Tue Feb 1 16:17:22 PST 2005
//
// Modifications:
//   
// ****************************************************************************

class STATE_API PlotQueryInfo : public AttributeSubject
{
public:
    enum ChangeType
    {
        None,
        Database,
        VarName,
        AddOp,
        OpAtts,
        PlotAtts,
        MoveOperator,
        RemoveOperator,
        RemoveAll,
        RemoveLast,
        CacheIndex
    };

    PlotQueryInfo();
    PlotQueryInfo(const PlotQueryInfo &obj);
    virtual ~PlotQueryInfo();

    virtual PlotQueryInfo& operator = (const PlotQueryInfo &obj);
    virtual bool operator == (const PlotQueryInfo &obj) const;
    virtual bool operator != (const PlotQueryInfo &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetChangeType(ChangeType changeType_);
    void SetOldFrameIndex(int oldFrameIndex_);
    void SetNewFrameIndex(int newFrameIndex_);

    // Property getting methods
    ChangeType GetChangeType() const;
    int GetOldFrameIndex() const;
    int GetNewFrameIndex() const;

    // Enum conversion functions
    static std::string ChangeType_ToString(ChangeType);
    static bool ChangeType_FromString(const std::string &, ChangeType &);
protected:
    static std::string ChangeType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    int changeType;
    int oldFrameIndex;
    int newFrameIndex;
};

#endif
