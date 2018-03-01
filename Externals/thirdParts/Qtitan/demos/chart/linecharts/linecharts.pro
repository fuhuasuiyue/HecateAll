TEMPLATE = app

QTITANDIR = $$quote($$(QTITANDIR))

include($$QTITANDIR/src/shared/qtitanchart.pri)

DESTDIR = $$QTITANDIR/bin
DESTDIR = $$member(DESTDIR, 0)$$QTITAN_LIB_PREFIX
DESTDIR = "$$DESTDIR"

!debug_and_release|build_pass {
    CONFIG(debug, debug|release) {
        TARGET = $$member(TARGET, 0)d
    }
}

HEADERS = linecharts.h

SOURCES = main.cpp \
          linecharts.cpp

RESOURCES  = linecharts.qrc


include($$QTITANDIR/demos/shared/demomainwindow.pri)
include($$QTITANDIR/demos/chart/shared/chartwindow.pri)

macx {
    CONFIG-=app_bundle
}
