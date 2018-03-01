#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(HCMOTIONCALCULATOR_LIB)
#  define HCMOTIONCALCULATOR_EXPORT Q_DECL_EXPORT
# else
#  define HCMOTIONCALCULATOR_EXPORT Q_DECL_IMPORT
# endif
#else
# define HCMOTIONCALCULATOR_EXPORT
#endif
