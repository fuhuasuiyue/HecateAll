/****************************************************************************
** Meta object code from reading C++ file 'QtnRibbonGroupDsgnPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtnRibbonGroupDsgnPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnRibbonGroupDsgnPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__DsgnRibbonGroupPlugin_t {
    QByteArrayData data[4];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnRibbonGroupPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnRibbonGroupPlugin_t qt_meta_stringdata_Qtitan__DsgnRibbonGroupPlugin = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Qtitan::DsgnRibbonGroupPlugin"
QT_MOC_LITERAL(1, 30, 12), // "titleChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5) // "title"

    },
    "Qtitan::DsgnRibbonGroupPlugin\0"
    "titleChanged\0\0title"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnRibbonGroupPlugin[] = {

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

void Qtitan::DsgnRibbonGroupPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DsgnRibbonGroupPlugin *_t = static_cast<DsgnRibbonGroupPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Qtitan::DsgnRibbonGroupPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnRibbonGroupPlugin.data,
      qt_meta_data_Qtitan__DsgnRibbonGroupPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnRibbonGroupPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnRibbonGroupPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnRibbonGroupPlugin.stringdata0))
        return static_cast<void*>(const_cast< DsgnRibbonGroupPlugin*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< DsgnRibbonGroupPlugin*>(this));
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< DsgnRibbonGroupPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::DsgnRibbonGroupPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_Qtitan__DsgnRibbonPageContainer_t {
    QByteArrayData data[1];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnRibbonPageContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnRibbonPageContainer_t qt_meta_stringdata_Qtitan__DsgnRibbonPageContainer = {
    {
QT_MOC_LITERAL(0, 0, 31) // "Qtitan::DsgnRibbonPageContainer"

    },
    "Qtitan::DsgnRibbonPageContainer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnRibbonPageContainer[] = {

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

void Qtitan::DsgnRibbonPageContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DsgnRibbonPageContainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnRibbonPageContainer.data,
      qt_meta_data_Qtitan__DsgnRibbonPageContainer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnRibbonPageContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnRibbonPageContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnRibbonPageContainer.stringdata0))
        return static_cast<void*>(const_cast< DsgnRibbonPageContainer*>(this));
    if (!strcmp(_clname, "QDesignerContainerExtension"))
        return static_cast< QDesignerContainerExtension*>(const_cast< DsgnRibbonPageContainer*>(this));
    if (!strcmp(_clname, "org.qt-project.Qt.Designer.Container"))
        return static_cast< QDesignerContainerExtension*>(const_cast< DsgnRibbonPageContainer*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::DsgnRibbonPageContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Qtitan__DsgnRibbonPageContainerFactory_t {
    QByteArrayData data[1];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnRibbonPageContainerFactory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnRibbonPageContainerFactory_t qt_meta_stringdata_Qtitan__DsgnRibbonPageContainerFactory = {
    {
QT_MOC_LITERAL(0, 0, 38) // "Qtitan::DsgnRibbonPageContain..."

    },
    "Qtitan::DsgnRibbonPageContainerFactory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnRibbonPageContainerFactory[] = {

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

void Qtitan::DsgnRibbonPageContainerFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DsgnRibbonPageContainerFactory::staticMetaObject = {
    { &QExtensionFactory::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnRibbonPageContainerFactory.data,
      qt_meta_data_Qtitan__DsgnRibbonPageContainerFactory,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnRibbonPageContainerFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnRibbonPageContainerFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnRibbonPageContainerFactory.stringdata0))
        return static_cast<void*>(const_cast< DsgnRibbonPageContainerFactory*>(this));
    return QExtensionFactory::qt_metacast(_clname);
}

int Qtitan::DsgnRibbonPageContainerFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QExtensionFactory::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
