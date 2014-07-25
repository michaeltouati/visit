/*****************************************************************************
*
* Copyright (c) 2000 - 2013, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
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
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef RADIALRESAMPLEATTRIBUTES_H
#define RADIALRESAMPLEATTRIBUTES_H
#include <AttributeSubject.h>


// ****************************************************************************
// Class: RadialResampleAttributes
//
// Purpose:
//    
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class RadialResampleAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    RadialResampleAttributes();
    RadialResampleAttributes(const RadialResampleAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    RadialResampleAttributes(private_tmfs_t tmfs);
    RadialResampleAttributes(const RadialResampleAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~RadialResampleAttributes();

    virtual RadialResampleAttributes& operator = (const RadialResampleAttributes &obj);
    virtual bool operator == (const RadialResampleAttributes &obj) const;
    virtual bool operator != (const RadialResampleAttributes &obj) const;
private:
    void Init();
    void Copy(const RadialResampleAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectCenter();

    // Property setting methods
    void SetIsFast(bool isFast_);
    void SetMinTheta(float minTheta_);
    void SetMaxTheta(float maxTheta_);
    void SetDeltaTheta(float deltaTheta_);
    void SetRadius(float radius_);
    void SetDeltaRadius(float deltaRadius_);
    void SetCenter(const float *center_);
    void SetIs3D(bool is3D_);
    void SetMinAzimuth(float minAzimuth_);
    void SetMaxAzimuth(float maxAzimuth_);
    void SetDeltaAzimuth(float deltaAzimuth_);

    // Property getting methods
    bool        GetIsFast() const;
    float       GetMinTheta() const;
    float       GetMaxTheta() const;
    float       GetDeltaTheta() const;
    float       GetRadius() const;
    float       GetDeltaRadius() const;
    const float *GetCenter() const;
          float *GetCenter();
    bool        GetIs3D() const;
    float       GetMinAzimuth() const;
    float       GetMaxAzimuth() const;
    float       GetDeltaAzimuth() const;

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
        ID_isFast = 0,
        ID_minTheta,
        ID_maxTheta,
        ID_deltaTheta,
        ID_radius,
        ID_deltaRadius,
        ID_center,
        ID_is3D,
        ID_minAzimuth,
        ID_maxAzimuth,
        ID_deltaAzimuth,
        ID__LAST
    };

private:
    bool  isFast;
    float minTheta;
    float maxTheta;
    float deltaTheta;
    float radius;
    float deltaRadius;
    float center[3];
    bool  is3D;
    float minAzimuth;
    float maxAzimuth;
    float deltaAzimuth;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define RADIALRESAMPLEATTRIBUTES_TMFS "bfffffFbfff"

#endif
