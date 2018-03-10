#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(HCLOG_LIB)
#  define HCLOG_EXPORT Q_DECL_EXPORT
# else
#  define HCLOG_EXPORT Q_DECL_IMPORT
# endif
#else
# define HCLOG_EXPORT
#endif
