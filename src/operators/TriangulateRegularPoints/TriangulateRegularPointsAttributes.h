// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef TRIANGULATEREGULARPOINTSATTRIBUTES_H
#define TRIANGULATEREGULARPOINTSATTRIBUTES_H
#include <AttributeSubject.h>


// ****************************************************************************
// Class: TriangulateRegularPointsAttributes
//
// Purpose:
//    Attributes for the triangulate regular points operator
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

class TriangulateRegularPointsAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    TriangulateRegularPointsAttributes();
    TriangulateRegularPointsAttributes(const TriangulateRegularPointsAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    TriangulateRegularPointsAttributes(private_tmfs_t tmfs);
    TriangulateRegularPointsAttributes(const TriangulateRegularPointsAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~TriangulateRegularPointsAttributes();

    virtual TriangulateRegularPointsAttributes& operator = (const TriangulateRegularPointsAttributes &obj);
    virtual bool operator == (const TriangulateRegularPointsAttributes &obj) const;
    virtual bool operator != (const TriangulateRegularPointsAttributes &obj) const;
private:
    void Init();
    void Copy(const TriangulateRegularPointsAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetUseXGridSpacing(bool useXGridSpacing_);
    void SetXGridSpacing(double xGridSpacing_);
    void SetUseYGridSpacing(bool useYGridSpacing_);
    void SetYGridSpacing(double yGridSpacing_);

    // Property getting methods
    bool   GetUseXGridSpacing() const;
    double GetXGridSpacing() const;
    bool   GetUseYGridSpacing() const;
    double GetYGridSpacing() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_useXGridSpacing = 0,
        ID_xGridSpacing,
        ID_useYGridSpacing,
        ID_yGridSpacing,
        ID__LAST
    };

private:
    bool   useXGridSpacing;
    double xGridSpacing;
    bool   useYGridSpacing;
    double yGridSpacing;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define TRIANGULATEREGULARPOINTSATTRIBUTES_TMFS "bdbd"

#endif
