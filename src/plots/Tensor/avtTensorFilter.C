// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                             avtTensorFilter.C                             //
// ************************************************************************* //

#include <avtTensorFilter.h>

#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkTensorReduceFilter.h>
#include <vtkVertexFilter.h>

// ****************************************************************************
//  Method: avtTensorFilter constructor
//
//  Arguments:
//      us      A boolean indicating if you should use the stride (true) or
//              stick with a fixed number of tensors (false).
//      red     The reduction factor, the stride of number of tensors depending
//              on us.
//
//  Programmer: Hank Childs
//  Creation:   September 23, 2003
//
//  Modifications:
//    Kathleen Bonnell, Tue Aug 30 15:11:01 PDT 2005
//    Added keepNodeZone.
//
//    David Camp, Thu May 23 12:52:53 PDT 2013
//    Removed the reduce and vertex variables from the class. They are now 
//    created in the exectue method. This was done for threading VisIt.
//
// ****************************************************************************

avtTensorFilter::avtTensorFilter(bool us, int red)
{
    if (us)
    {
        SetStride(red);
    }
    else
    {
        SetNTensors(red);
    }

    keepNodeZone = false;
}


// ****************************************************************************
//  Method: avtTensorFilter destructor
//
//  Programmer: Hank Childs
//  Creation:   September 23, 2003
//
//  Modifications:
//
//    Hank Childs, Thu Aug 30 17:30:48 PDT 2001
//    Added vertex filter.
//
//    David Camp, Thu May 23 12:52:53 PDT 2013
//    Removed the reduce and vertex variables from the class. They are now 
//    created in the exectue method. This was done for threading VisIt.
//
// ****************************************************************************

avtTensorFilter::~avtTensorFilter()
{
}


// ****************************************************************************
//  Method: avtTensorFilter::SetStride
//
//  Purpose:
//      Sets the stride of reduction for the vector.
//
//  Programmer: Hank Childs
//  Creation:   March 23, 2001
//
//  Modifications:
//    David Camp, Thu May 23 12:52:53 PDT 2013
//    Removed the reduce and vertex variables from the class. They are now 
//    created in the exectue method. This was done for threading VisIt.
//
// ****************************************************************************

void
avtTensorFilter::SetStride(int s)
{
    useStride = true;
    stride    = s;
    nTensors  = -1;
}


// ****************************************************************************
//  Method: avtTensorFilter::SetNTensors
//
//  Purpose:
//      Sets the number of vectors the filter should try to output.
//
//  Programmer: Hank Childs
//  Creation:   March 23, 2001
//
//  Modifications:
//    David Camp, Thu May 23 12:52:53 PDT 2013
//    Removed the reduce and vertex variables from the class. They are now 
//    created in the exectue method. This was done for threading VisIt.
//
// ****************************************************************************

void
avtTensorFilter::SetNTensors(int n)
{
    useStride = false;
    stride    = -1;
    nTensors  = n;
}

// ****************************************************************************
//  Method: avtTensorFilter::ExecuteData
//
//  Purpose:
//      Takes in an input dataset and creates the vector poly data.
//
//  Arguments:
//      inDR      The input data representation.
//
//  Returns:      The output data representation.
//
//  Programmer:   Hank Childs
//  Creation:     September 23, 2003
//
//  Modifications:
//    
//    Kathleen Bonnell, Tue Apr 10 11:51:18 PDT 2001
//    Renamed method as ExecuteData from ExecuteDomain.
//
//    Hank Childs, Thu Aug 30 17:30:48 PDT 2001
//    Added vertex filter.
//
//    Hank Childs, Wed Sep 11 08:53:50 PDT 2002
//    Fixed memory leak.
//
//    David Camp, Thu May 23 12:52:53 PDT 2013
//    Removed the reduce and vertex variables from the class. They are now 
//    created in the exectue method. This was done for threading VisIt.
//
//    Eric Brugger, Tue Aug 19 11:28:49 PDT 2014
//    Modified the class to work with avtDataRepresentation.
//
// ****************************************************************************

avtDataRepresentation *
avtTensorFilter::ExecuteData(avtDataRepresentation *inDR)
{
    //
    // Get the VTK data set.
    //
    vtkDataSet *inDS = inDR->GetDataVTK();

    vtkTensorReduceFilter *reduce = vtkTensorReduceFilter::New();
    vtkVertexFilter *vertex = vtkVertexFilter::New();

    if (useStride)
    {
        reduce->SetStride(stride);
    }
    else
    {
        reduce->SetNumberOfElements(nTensors);
    }

    if (inDS->GetPointData()->GetTensors() != NULL)
    {
        vertex->VertexAtPointsOn();
    }
    else
    {
        vertex->VertexAtPointsOff();
    }

    vertex->SetInputData(inDS);
    reduce->SetInputConnection(vertex->GetOutputPort());
    reduce->Update();
    vtkPolyData *outPD = reduce->GetOutput();

    avtDataRepresentation *outDR = new avtDataRepresentation(outPD,
        inDR->GetDomain(), inDR->GetLabel());

    reduce->Delete();
    vertex->Delete();

    return outDR;
}


// ****************************************************************************
//  Method: avtTensorFilter::UpdateDataObjectInfo
//
//  Purpose:
//      Indicate that the vector are of dimension 0.
//
//  Programmer: Hank Childs
//  Creation:   June 12, 2001
//
//  Modifications:
//
//    Hank Childs, Tue Sep  4 16:14:49 PDT 2001
//    Reflect new interface for avtDataAttributes.
//
//    Hank Childs, Wed Apr  9 13:53:09 PDT 2003
//    Do not calculate normals of these points.
//
//    Kathleen Bonnell, Tue Aug 30 15:11:01 PDT 2005
//    Added keepNodeZone.
//
//    Kathleen Biagas, Thu Mar 14 12:58:39 PDT 2013
//    Allow normals calculation.  The TensorGlyph filter now does a good job
//    copying, and also reversing inside-out normals. But they must be present.
//
// ****************************************************************************

void
avtTensorFilter::UpdateDataObjectInfo(void)
{
    GetOutput()->GetInfo().GetValidity().InvalidateZones();
    GetOutput()->GetInfo().GetAttributes().SetTopologicalDimension(0);
    GetOutput()->GetInfo().GetAttributes().SetKeepNodeZoneArrays(keepNodeZone);
}


// ****************************************************************************
//  Method: avtTensorFilter::ReleaseData
//
//  Purpose:
//      Releases all problem size data associated with this filter.
//
//  Programmer: Hank Childs
//  Creation:   September 10, 2002
//
//  Modifications:
//
//    Hank Childs, Fri Mar  4 08:12:25 PST 2005
//    Do not set outputs of filters to NULL, since this will prevent them
//    from re-executing correctly in DLB-mode.
//
//    Kathleen Bonnell, Wed May 18 15:07:05 PDT 2005 
//    Fix memory leak. 
//
//    David Camp, Thu May 23 12:52:53 PDT 2013
//    Removed the reduce and vertex variables from the class. They are now 
//    created in the exectue method. This was done for threading VisIt.
//
// ****************************************************************************

void
avtTensorFilter::ReleaseData(void)
{
    avtDataTreeIterator::ReleaseData();
}


// ****************************************************************************
//  Method: avtTensorFilter::ModifyContract
//
//  Purpose:  
//    Request original nodes/zones when appropriate. 
// 
//  Programmer: Kathleen Bonnell 
//  Creation:   August 30, 2005 
//
//  Modifications:
//
// ****************************************************************************

avtContract_p
avtTensorFilter::ModifyContract(avtContract_p contract)
{
    avtContract_p rv = contract;

    if (contract->GetDataRequest()->MayRequireZones() || 
        contract->GetDataRequest()->MayRequireNodes())
    {
        avtDataAttributes &data = GetInput()->GetInfo().GetAttributes();
        keepNodeZone = true;
        if (data.ValidActiveVariable())
        {
            if (data.GetCentering() == AVT_NODECENT)
            {
                rv->GetDataRequest()->TurnNodeNumbersOn();
            }
            else if (data.GetCentering() == AVT_ZONECENT)
            {
                rv->GetDataRequest()->TurnZoneNumbersOn();
            }
        }
        else 
        {
            // canot determine variable centering, so turn on both
            // node numbers and zone numbers.
            rv->GetDataRequest()->TurnNodeNumbersOn();
            rv->GetDataRequest()->TurnZoneNumbersOn();
        }
    }
    else
    {
        keepNodeZone = false;
    }

    return rv;
}



