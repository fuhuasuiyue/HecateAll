/****************************************************************************
** Meta object code from reading C++ file 'QtnMainWindowDsgnPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtnMainWindowDsgnPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnMainWindowDsgnPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__MainWindowDsgnPlugin_t {
    QByteArrayData data[4];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__MainWindowDsgnPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__MainWindowDsgnPlugin_t qt_meta_stringdata_Qtitan__MainWindowDsgnPlugin = {
    {
QT_MOC_LITERAL(0, 0, 28), // "Qtitan::MainWindowDsgnPlugin"
QT_MOC_LITERAL(1, 29, 15), // "fileNameChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 8) // "fileName"

    },
    "Qtitan::MainWindowDsgnPlugin\0"
    "fileNameChanged\0\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__MainWindowDsgnPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void Qtitan::MainWindowDsgnPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowDsgnPlugin *_t = static_cast<MainWindowDsgnPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Qtitan::MainWindowDsgnPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__MainWindowDsgnPlugin.data,
      qt_meta_data_Qtitan__MainWindowDsgnPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::MainWindowDsgnPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::MainWindowDsgnPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__MainWindowDsgnPlugin.stringdata0))
        return static_cast<void*>(const_cast< MainWindowDsgnPlugin*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< MainWindowDsgnPlugin*>(this));
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< MainWindowDsgnPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::MainWindowDsgnPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
