// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef GUI_EXPORTS_H
#define GUI_EXPORTS_H

#if defined(_WIN32)
#if defined(GUI_EXPORTS) || defined(gui_EXPORTS)
#define GUI_API __declspec(dllexport)
#else
#define GUI_API __declspec(dllimport)
#endif
#if defined(_MSC_VER)
// Turn off warning about lack of DLL interface
#pragma warning(disable:4251)
// Turn off warning non-dll class is base for dll-interface class.
#pragma warning(disable:4275)
// Turn off warning about identifier truncation
#pragma warning(disable:4786)
#endif
#else
# if __GNUC__ >= 4 && (defined(GUI_EXPORTS) || defined(gui_EXPORTS))
#   define GUI_API __attribute__ ((visibility("default")))
# else
#   define GUI_API /* hidden by default */
# endif
#endif

#endif
