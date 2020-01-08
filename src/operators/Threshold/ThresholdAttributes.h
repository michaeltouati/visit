// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef THRESHOLDATTRIBUTES_H
#define THRESHOLDATTRIBUTES_H
#include <ThresholdOpAttributes.h>

#include <AxisRestrictionAttributes.h>
#include <DebugStream.h>

// ****************************************************************************
// Class: ThresholdAttributes
//
// Purpose:
//    This class contains attributes for the threshold operator.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

class ThresholdAttributes : public ThresholdOpAttributes
{
public:
    // These constructors are for objects of this class
    ThresholdAttributes();
    ThresholdAttributes(const ThresholdAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    ThresholdAttributes(private_tmfs_t tmfs);
    ThresholdAttributes(const ThresholdAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~ThresholdAttributes();

    virtual ThresholdAttributes& operator = (const ThresholdAttributes &obj);
    virtual bool operator == (const ThresholdAttributes &obj) const;
    virtual bool operator != (const ThresholdAttributes &obj) const;
private:
    void Init();
    void Copy(const ThresholdAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;



private:
    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define THRESHOLDATTRIBUTES_TMFS THRESHOLDOPATTRIBUTES_TMFS ""

#endif
