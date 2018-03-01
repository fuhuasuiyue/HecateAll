/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MdiArea_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MdiArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MdiArea_t qt_meta_stringdata_MdiArea = {
    {
QT_MOC_LITERAL(0, 0, 7) // "MdiArea"

    },
    "MdiArea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MdiArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MdiArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MdiArea::staticMetaObject = {
    { &QMdiArea::staticMetaObject, qt_meta_stringdata_MdiArea.data,
      qt_meta_data_MdiArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MdiArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MdiArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MdiArea.stringdata0))
        return static_cast<void*>(const_cast< MdiArea*>(this));
    return QMdiArea::qt_metacast(_clname);
}

int MdiArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiArea::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[31];
    char stringdata0[396];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "newTextFile"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "newSketchFile"
QT_MOC_LITERAL(4, 38, 4), // "open"
QT_MOC_LITERAL(5, 43, 4), // "save"
QT_MOC_LITERAL(6, 48, 6), // "saveAs"
QT_MOC_LITERAL(7, 55, 3), // "cut"
QT_MOC_LITERAL(8, 59, 4), // "copy"
QT_MOC_LITERAL(9, 64, 5), // "paste"
QT_MOC_LITERAL(10, 70, 11), // "updateMenus"
QT_MOC_LITERAL(11, 82, 16), // "updateWindowMenu"
QT_MOC_LITERAL(12, 99, 18), // "createMdiTextChild"
QT_MOC_LITERAL(13, 118, 14), // "TextEditChild*"
QT_MOC_LITERAL(14, 133, 17), // "createSketchChild"
QT_MOC_LITERAL(15, 151, 12), // "SketchChild*"
QT_MOC_LITERAL(16, 164, 21), // "switchLayoutDirection"
QT_MOC_LITERAL(17, 186, 18), // "setActiveSubWindow"
QT_MOC_LITERAL(18, 205, 8), // "QWidget*"
QT_MOC_LITERAL(19, 214, 6), // "window"
QT_MOC_LITERAL(20, 221, 13), // "hideStatusBar"
QT_MOC_LITERAL(21, 235, 14), // "switchViewMode"
QT_MOC_LITERAL(22, 250, 16), // "switchFrameTheme"
QT_MOC_LITERAL(23, 267, 18), // "setTabPositionLeft"
QT_MOC_LITERAL(24, 286, 5), // "state"
QT_MOC_LITERAL(25, 292, 17), // "setTabPositionTop"
QT_MOC_LITERAL(26, 310, 20), // "setTabPositionBottom"
QT_MOC_LITERAL(27, 331, 19), // "setTabPositionRight"
QT_MOC_LITERAL(28, 351, 18), // "subWindowActivated"
QT_MOC_LITERAL(29, 370, 14), // "QMdiSubWindow*"
QT_MOC_LITERAL(30, 385, 10) // "fullScreen"

    },
    "MainWindow\0newTextFile\0\0newSketchFile\0"
    "open\0save\0saveAs\0cut\0copy\0paste\0"
    "updateMenus\0updateWindowMenu\0"
    "createMdiTextChild\0TextEditChild*\0"
    "createSketchChild\0SketchChild*\0"
    "switchLayoutDirection\0setActiveSubWindow\0"
    "QWidget*\0window\0hideStatusBar\0"
    "switchViewMode\0switchFrameTheme\0"
    "setTabPositionLeft\0state\0setTabPositionTop\0"
    "setTabPositionBottom\0setTabPositionRight\0"
    "subWindowActivated\0QMdiSubWindow*\0"
    "fullScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x08 /* Private */,
       3,    0,  130,    2, 0x08 /* Private */,
       4,    0,  131,    2, 0x08 /* Private */,
       5,    0,  132,    2, 0x08 /* Private */,
       6,    0,  133,    2, 0x08 /* Private */,
       7,    0,  134,    2, 0x08 /* Private */,
       8,    0,  135,    2, 0x08 /* Private */,
       9,    0,  136,    2, 0x08 /* Private */,
      10,    0,  137,    2, 0x08 /* Private */,
      11,    0,  138,    2, 0x08 /* Private */,
      12,    0,  139,    2, 0x08 /* Private */,
      14,    0,  140,    2, 0x08 /* Private */,
      16,    0,  141,    2, 0x08 /* Private */,
      17,    1,  142,    2, 0x08 /* Private */,
      20,    1,  145,    2, 0x08 /* Private */,
      21,    1,  148,    2, 0x08 /* Private */,
      22,    1,  151,    2, 0x08 /* Private */,
      23,    1,  154,    2, 0x08 /* Private */,
      25,    1,  157,    2, 0x08 /* Private */,
      26,    1,  160,    2, 0x08 /* Private */,
      27,    1,  163,    2, 0x08 /* Private */,
      28,    1,  166,    2, 0x08 /* Private */,
      30,    1,  169,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 13,
    0x80000000 | 15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, 0x80000000 | 29,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newTextFile(); break;
        case 1: _t->newSketchFile(); break;
        case 2: _t->open(); break;
        case 3: _t->save(); break;
        case 4: _t->saveAs(); break;
        case 5: _t->cut(); break;
        case 6: _t->copy(); break;
        case 7: _t->paste(); break;
        case 8: _t->updateMenus(); break;
        case 9: _t->updateWindowMenu(); break;
        case 10: { TextEditChild* _r = _t->createMdiTextChild();
            if (_a[0]) *reinterpret_cast< TextEditChild**>(_a[0]) = std::move(_r); }  break;
        case 11: { SketchChild* _r = _t->createSketchChild();
            if (_a[0]) *reinterpret_cast< SketchChild**>(_a[0]) = std::move(_r); }  break;
        case 12: _t->switchLayoutDirection(); break;
        case 13: _t->setActiveSubWindow((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 14: _t->hideStatusBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->switchViewMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->switchFrameTheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setTabPositionLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setTabPositionTop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->setTabPositionBottom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->setTabPositionRight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->subWindowActivated((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 22: _t->fullScreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &RibbonWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return RibbonWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RibbonWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
