/****************************************************************************
** Meta object code from reading C++ file 'QtnRibbonDsgnPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtnRibbonDsgnPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnRibbonDsgnPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__RibbonEventFilter_t {
    QByteArrayData data[5];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__RibbonEventFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__RibbonEventFilter_t qt_meta_stringdata_Qtitan__RibbonEventFilter = {
    {
QT_MOC_LITERAL(0, 0, 25), // "Qtitan::RibbonEventFilter"
QT_MOC_LITERAL(1, 26, 19), // "slotRemoveRibbonBar"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 14), // "slotAddNewPage"
QT_MOC_LITERAL(4, 62, 21) // "slotRemoveCurrentPage"

    },
    "Qtitan::RibbonEventFilter\0slotRemoveRibbonBar\0"
    "\0slotAddNewPage\0slotRemoveCurrentPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__RibbonEventFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Qtitan::RibbonEventFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RibbonEventFilter *_t = static_cast<RibbonEventFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRemoveRibbonBar(); break;
        case 1: _t->slotAddNewPage(); break;
        case 2: _t->slotRemoveCurrentPage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::RibbonEventFilter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__RibbonEventFilter.data,
      qt_meta_data_Qtitan__RibbonEventFilter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::RibbonEventFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::RibbonEventFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__RibbonEventFilter.stringdata0))
        return static_cast<void*>(const_cast< RibbonEventFilter*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::RibbonEventFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_Qtitan__DsgnRibbonBarPlugin_t {
    QByteArrayData data[11];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnRibbonBarPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnRibbonBarPlugin_t qt_meta_stringdata_Qtitan__DsgnRibbonBarPlugin = {
    {
QT_MOC_LITERAL(0, 0, 27), // "Qtitan::DsgnRibbonBarPlugin"
QT_MOC_LITERAL(1, 28, 18), // "currentPageChanged"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 5), // "index"
QT_MOC_LITERAL(4, 54, 15), // "formWindowAdded"
QT_MOC_LITERAL(5, 70, 29), // "QDesignerFormWindowInterface*"
QT_MOC_LITERAL(6, 100, 10), // "formWindow"
QT_MOC_LITERAL(7, 111, 17), // "formWindowRemoved"
QT_MOC_LITERAL(8, 129, 13), // "widgetManaged"
QT_MOC_LITERAL(9, 143, 8), // "QWidget*"
QT_MOC_LITERAL(10, 152, 6) // "widget"

    },
    "Qtitan::DsgnRibbonBarPlugin\0"
    "currentPageChanged\0\0index\0formWindowAdded\0"
    "QDesignerFormWindowInterface*\0formWindow\0"
    "formWindowRemoved\0widgetManaged\0"
    "QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnRibbonBarPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
       8,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Qtitan::DsgnRibbonBarPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DsgnRibbonBarPlugin *_t = static_cast<DsgnRibbonBarPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentPageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->formWindowAdded((*reinterpret_cast< QDesignerFormWindowInterface*(*)>(_a[1]))); break;
        case 2: _t->formWindowRemoved((*reinterpret_cast< QDesignerFormWindowInterface*(*)>(_a[1]))); break;
        case 3: _t->widgetManaged((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Qtitan::DsgnRibbonBarPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnRibbonBarPlugin.data,
      qt_meta_data_Qtitan__DsgnRibbonBarPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnRibbonBarPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnRibbonBarPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnRibbonBarPlugin.stringdata0))
        return static_cast<void*>(const_cast< DsgnRibbonBarPlugin*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< DsgnRibbonBarPlugin*>(this));
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< DsgnRibbonBarPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::DsgnRibbonBarPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
