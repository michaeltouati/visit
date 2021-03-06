// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                           FileDoesNotExistException.C                     //
// ************************************************************************* //

#include <stdio.h>                  // for sprintf
#include <FileDoesNotExistException.h>


// ****************************************************************************
//  Method: FileDoesNotExistException constructor
//
//  Arguments:
//      filename    The name of a file that does not exist.
//
//  Programmer: Brad Whitlock
//  Creation:   Fri Jul 26 11:16:13 PDT 2002
//
// ****************************************************************************

FileDoesNotExistException::FileDoesNotExistException(const char *filename)
{
    char str[1024];
    sprintf(str, "The file \"%s\" does not exist.", filename);

    msg = str;
}
