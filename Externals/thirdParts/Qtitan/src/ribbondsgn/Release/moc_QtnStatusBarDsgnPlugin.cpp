/****************************************************************************
** Meta object code from reading C++ file 'QtnStatusBarDsgnPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtnStatusBarDsgnPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnStatusBarDsgnPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__DsgnRibbonStatusBarPlugin_t {
    QByteArrayData data[9];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnRibbonStatusBarPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnRibbonStatusBarPlugin_t qt_meta_stringdata_Qtitan__DsgnRibbonStatusBarPlugin = {
    {
QT_MOC_LITERAL(0, 0, 33), // "Qtitan::DsgnRibbonStatusBarPl..."
QT_MOC_LITERAL(1, 34, 15), // "formWindowAdded"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 29), // "QDesignerFormWindowInterface*"
QT_MOC_LITERAL(4, 81, 10), // "formWindow"
QT_MOC_LITERAL(5, 92, 17), // "formWindowRemoved"
QT_MOC_LITERAL(6, 110, 13), // "widgetManaged"
QT_MOC_LITERAL(7, 124, 8), // "QWidget*"
QT_MOC_LITERAL(8, 133, 6) // "widget"

    },
    "Qtitan::DsgnRibbonStatusBarPlugin\0"
    "formWindowAdded\0\0QDesignerFormWindowInterface*\0"
    "formWindow\0formWindowRemoved\0widgetManaged\0"
    "QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnRibbonStatusBarPlugin[] = {

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
       1,    1,   29,    2, 0x08 /* Private */,
       5,    1,   32,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void Qtitan::DsgnRibbonStatusBarPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DsgnRibbonStatusBarPlugin *_t = static_cast<DsgnRibbonStatusBarPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->formWindowAdded((*reinterpret_cast< QDesignerFormWindowInterface*(*)>(_a[1]))); break;
        case 1: _t->formWindowRemoved((*reinterpret_cast< QDesignerFormWindowInterface*(*)>(_a[1]))); break;
        case 2: _t->widgetManaged((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDesignerFormWindowInterface* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDesignerFormWindowInterface* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Qtitan::DsgnRibbonStatusBarPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnRibbonStatusBarPlugin.data,
      qt_meta_data_Qtitan__DsgnRibbonStatusBarPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnRibbonStatusBarPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnRibbonStatusBarPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnRibbonStatusBarPlugin.stringdata0))
        return static_cast<void*>(const_cast< DsgnRibbonStatusBarPlugin*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< DsgnRibbonStatusBarPlugin*>(this));
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< DsgnRibbonStatusBarPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::DsgnRibbonStatusBarPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
