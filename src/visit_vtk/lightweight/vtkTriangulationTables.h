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

#ifndef VTK_TRIANGULATION_TABLES_H
#define VTK_TRIANGULATION_TABLES_H
#include <visit_vtk_light_exports.h>

// ************************************************************************* //
//                         vtkTriangulationTables.h                          //
// ************************************************************************* //


extern VISIT_VTK_LIGHT_API int tetTriangulationTable[16][7];
extern VISIT_VTK_LIGHT_API int tetVerticesFromEdges[6][2];
extern VISIT_VTK_LIGHT_API int tetTriangleFaces[4][3];

extern VISIT_VTK_LIGHT_API int pyramidTriangulationTable[32][13];
extern VISIT_VTK_LIGHT_API int pyramidVerticesFromEdges[8][2];
extern VISIT_VTK_LIGHT_API int pyramidTriangleFaces[4][3];
extern VISIT_VTK_LIGHT_API int pyramidQuadFaces[1][4];

extern VISIT_VTK_LIGHT_API int wedgeTriangulationTable[64][13];
extern VISIT_VTK_LIGHT_API int wedgeVerticesFromEdges[9][2];
extern VISIT_VTK_LIGHT_API int wedgeTriangleFaces[2][3];
extern VISIT_VTK_LIGHT_API int wedgeQuadFaces[3][4];

extern VISIT_VTK_LIGHT_API int hexTriangulationTable[256][16];
extern VISIT_VTK_LIGHT_API int hexVerticesFromEdges[12][2];
extern VISIT_VTK_LIGHT_API int hexQuadFaces[6][4];

extern VISIT_VTK_LIGHT_API int voxTriangulationTable[256][16];
extern VISIT_VTK_LIGHT_API int voxVerticesFromEdges[12][2];
extern VISIT_VTK_LIGHT_API int voxQuadFaces[6][4];

extern VISIT_VTK_LIGHT_API int triVerticesFromEdges[3][2];
extern VISIT_VTK_LIGHT_API int quadVerticesFromEdges[4][2];
extern VISIT_VTK_LIGHT_API int pixelVerticesFromEdges[4][2];

#endif
