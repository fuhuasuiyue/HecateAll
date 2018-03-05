#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(HCPROJECTDATA_LIB)
#  define HCPROJECTDATA_EXPORT Q_DECL_EXPORT
# else
#  define HCPROJECTDATA_EXPORT Q_DECL_IMPORT
# endif
#else
# define HCPROJECTDATA_EXPORT
#endif
