/****************************************************************************
** Meta object code from reading C++ file 'sketchchild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sketchchild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sketchchild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SketchChild_t {
    QByteArrayData data[14];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SketchChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SketchChild_t qt_meta_stringdata_SketchChild = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SketchChild"
QT_MOC_LITERAL(1, 12, 15), // "selectionAction"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "lineAction"
QT_MOC_LITERAL(4, 40, 15), // "rectangleAction"
QT_MOC_LITERAL(5, 56, 12), // "circleAction"
QT_MOC_LITERAL(6, 69, 13), // "ellipseAction"
QT_MOC_LITERAL(7, 83, 12), // "stateChanged"
QT_MOC_LITERAL(8, 96, 2), // "st"
QT_MOC_LITERAL(9, 99, 12), // "createObject"
QT_MOC_LITERAL(10, 112, 12), // "cyclicalTool"
QT_MOC_LITERAL(11, 125, 8), // "showGrid"
QT_MOC_LITERAL(12, 134, 8), // "stepGrid"
QT_MOC_LITERAL(13, 143, 19) // "documentWasModified"

    },
    "SketchChild\0selectionAction\0\0lineAction\0"
    "rectangleAction\0circleAction\0ellipseAction\0"
    "stateChanged\0st\0createObject\0cyclicalTool\0"
    "showGrid\0stepGrid\0documentWasModified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SketchChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

       0        // eod
};

void SketchChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SketchChild *_t = static_cast<SketchChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionAction(); break;
        case 1: _t->lineAction(); break;
        case 2: _t->rectangleAction(); break;
        case 3: _t->circleAction(); break;
        case 4: _t->ellipseAction(); break;
        case 5: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->createObject(); break;
        case 7: _t->cyclicalTool(); break;
        case 8: _t->showGrid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->stepGrid((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->documentWasModified(); break;
        default: ;
        }
    }
}

const QMetaObject SketchChild::staticMetaObject = {
    { &QAbstractScrollArea::staticMetaObject, qt_meta_stringdata_SketchChild.data,
      qt_meta_data_SketchChild,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SketchChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SketchChild::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SketchChild.stringdata0))
        return static_cast<void*>(const_cast< SketchChild*>(this));
    if (!strcmp(_clname, "ChildInterface"))
        return static_cast< ChildInterface*>(const_cast< SketchChild*>(this));
    if (!strcmp(_clname, "com.qtitan.ribbonmdisample.ChildInterface"))
        return static_cast< ChildInterface*>(const_cast< SketchChild*>(this));
    return QAbstractScrollArea::qt_metacast(_clname);
}

int SketchChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
