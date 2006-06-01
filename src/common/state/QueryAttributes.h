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

#ifndef QUERYATTRIBUTES_H
#define QUERYATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>
#include <visitstream.h>

// ****************************************************************************
// Class: QueryAttributes
//
// Purpose:
//    This class contains attributes used for query.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Fri Mar 17 14:49:49 PST 2006
//
// Modifications:
//   
// ****************************************************************************

class STATE_API QueryAttributes : public AttributeSubject
{
public:
    enum ElementType
    {
        Zone,
        Node
    };
    enum VarType
    {
        Mesh,
        Scalar,
        Vector,
        Tensor,
        Symmetric_Tensor,
        Array,
        Label,
        Material,
        Species,
        Curve,
        Unknown
    };
    enum DataType
    {
        ActualData,
        OriginalData
    };

    QueryAttributes();
    QueryAttributes(const QueryAttributes &obj);
    virtual ~QueryAttributes();

    virtual QueryAttributes& operator = (const QueryAttributes &obj);
    virtual bool operator == (const QueryAttributes &obj) const;
    virtual bool operator != (const QueryAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectName();
    void SelectVariables();
    void SelectResultsMessage();
    void SelectWorldPoint();
    void SelectResultsValue();
    void SelectVarTypes();
    void SelectXUnits();
    void SelectYUnits();

    // Property setting methods
    void SetName(const std::string &name_);
    void SetVariables(const stringVector &variables_);
    void SetResultsMessage(const std::string &resultsMessage_);
    void SetWorldPoint(const double *worldPoint_);
    void SetDomain(int domain_);
    void SetElement(int element_);
    void SetResultsValue(const doubleVector &resultsValue_);
    void SetElementType(ElementType elementType_);
    void SetTimeStep(int timeStep_);
    void SetVarTypes(const intVector &varTypes_);
    void SetDataType(DataType dataType_);
    void SetPipeIndex(int pipeIndex_);
    void SetUseGlobalId(bool useGlobalId_);
    void SetXUnits(const std::string &xUnits_);
    void SetYUnits(const std::string &yUnits_);

    // Property getting methods
    const std::string  &GetName() const;
          std::string  &GetName();
    const stringVector &GetVariables() const;
          stringVector &GetVariables();
    const std::string  &GetResultsMessage() const;
          std::string  &GetResultsMessage();
    const double       *GetWorldPoint() const;
          double       *GetWorldPoint();
    int                GetDomain() const;
    int                GetElement() const;
    const doubleVector &GetResultsValue() const;
          doubleVector &GetResultsValue();
    ElementType        GetElementType() const;
    int                GetTimeStep() const;
    const intVector    &GetVarTypes() const;
          intVector    &GetVarTypes();
    DataType           GetDataType() const;
    int                GetPipeIndex() const;
    bool               GetUseGlobalId() const;
    const std::string  &GetXUnits() const;
          std::string  &GetXUnits();
    const std::string  &GetYUnits() const;
          std::string  &GetYUnits();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string ElementType_ToString(ElementType);
    static bool ElementType_FromString(const std::string &, ElementType &);
protected:
    static std::string ElementType_ToString(int);
public:
    static std::string VarType_ToString(VarType);
    static bool VarType_FromString(const std::string &, VarType &);
protected:
    static std::string VarType_ToString(int);
public:
    static std::string DataType_ToString(DataType);
    static bool DataType_FromString(const std::string &, DataType &);
protected:
    static std::string DataType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void Reset();
    void PrintSelf(ostream &os);
    void SetResultsValue(const double);
    void SetResultsValues(const double*, const int);
private:
    std::string  name;
    stringVector variables;
    std::string  resultsMessage;
    double       worldPoint[3];
    int          domain;
    int          element;
    doubleVector resultsValue;
    int          elementType;
    int          timeStep;
    intVector    varTypes;
    int          dataType;
    int          pipeIndex;
    bool         useGlobalId;
    std::string  xUnits;
    std::string  yUnits;
};

#endif
