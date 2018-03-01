/****************************************************************************
** Meta object code from reading C++ file 'QtnRibbonStyleDsgnPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtnRibbonStyleDsgnPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnRibbonStyleDsgnPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__DesignerStyleInput_t {
    QByteArrayData data[3];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DesignerStyleInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DesignerStyleInput_t qt_meta_stringdata_Qtitan__DesignerStyleInput = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Qtitan::DesignerStyleInput"
QT_MOC_LITERAL(1, 27, 11), // "removeStyle"
QT_MOC_LITERAL(2, 39, 0) // ""

    },
    "Qtitan::DesignerStyleInput\0removeStyle\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DesignerStyleInput[] = {

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
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Qtitan::DesignerStyleInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DesignerStyleInput *_t = static_cast<DesignerStyleInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeStyle(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DesignerStyleInput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__DesignerStyleInput.data,
      qt_meta_data_Qtitan__DesignerStyleInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DesignerStyleInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DesignerStyleInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DesignerStyleInput.stringdata0))
        return static_cast<void*>(const_cast< DesignerStyleInput*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::DesignerStyleInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_Qtitan__DsgnRibbonStyleWidget_t {
    QByteArrayData data[1];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnRibbonStyleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnRibbonStyleWidget_t qt_meta_stringdata_Qtitan__DsgnRibbonStyleWidget = {
    {
QT_MOC_LITERAL(0, 0, 29) // "Qtitan::DsgnRibbonStyleWidget"

    },
    "Qtitan::DsgnRibbonStyleWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnRibbonStyleWidget[] = {

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

void Qtitan::DsgnRibbonStyleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DsgnRibbonStyleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnRibbonStyleWidget.data,
      qt_meta_data_Qtitan__DsgnRibbonStyleWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnRibbonStyleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnRibbonStyleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnRibbonStyleWidget.stringdata0))
        return static_cast<void*>(const_cast< DsgnRibbonStyleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Qtitan::DsgnRibbonStyleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Qtitan__DsgnOfficeStyleWidget_t {
    QByteArrayData data[1];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DsgnOfficeStyleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DsgnOfficeStyleWidget_t qt_meta_stringdata_Qtitan__DsgnOfficeStyleWidget = {
    {
QT_MOC_LITERAL(0, 0, 29) // "Qtitan::DsgnOfficeStyleWidget"

    },
    "Qtitan::DsgnOfficeStyleWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DsgnOfficeStyleWidget[] = {

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

void Qtitan::DsgnOfficeStyleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DsgnOfficeStyleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Qtitan__DsgnOfficeStyleWidget.data,
      qt_meta_data_Qtitan__DsgnOfficeStyleWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DsgnOfficeStyleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DsgnOfficeStyleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DsgnOfficeStyleWidget.stringdata0))
        return static_cast<void*>(const_cast< DsgnOfficeStyleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Qtitan::DsgnOfficeStyleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Qtitan__ExtensionManagerWrapper_t {
    QByteArrayData data[1];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__ExtensionManagerWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__ExtensionManagerWrapper_t qt_meta_stringdata_Qtitan__ExtensionManagerWrapper = {
    {
QT_MOC_LITERAL(0, 0, 31) // "Qtitan::ExtensionManagerWrapper"

    },
    "Qtitan::ExtensionManagerWrapper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__ExtensionManagerWrapper[] = {

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

void Qtitan::ExtensionManagerWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::ExtensionManagerWrapper::staticMetaObject = {
    { &QExtensionManager::staticMetaObject, qt_meta_stringdata_Qtitan__ExtensionManagerWrapper.data,
      qt_meta_data_Qtitan__ExtensionManagerWrapper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::ExtensionManagerWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::ExtensionManagerWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__ExtensionManagerWrapper.stringdata0))
        return static_cast<void*>(const_cast< ExtensionManagerWrapper*>(this));
    if (!strcmp(_clname, "org.qt-project.Qt.QAbstractExtensionManager"))
        return static_cast< QAbstractExtensionManager*>(const_cast< ExtensionManagerWrapper*>(this));
    return QExtensionManager::qt_metacast(_clname);
}

int Qtitan::ExtensionManagerWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QExtensionManager::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainer_t {
    QByteArrayData data[1];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainer_t qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainer = {
    {
QT_MOC_LITERAL(0, 0, 40) // "Qtitan::DesignerMainWindowSty..."

    },
    "Qtitan::DesignerMainWindowStyleContainer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DesignerMainWindowStyleContainer[] = {

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

void Qtitan::DesignerMainWindowStyleContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DesignerMainWindowStyleContainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainer.data,
      qt_meta_data_Qtitan__DesignerMainWindowStyleContainer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DesignerMainWindowStyleContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DesignerMainWindowStyleContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainer.stringdata0))
        return static_cast<void*>(const_cast< DesignerMainWindowStyleContainer*>(this));
    if (!strcmp(_clname, "QDesignerContainerExtension"))
        return static_cast< QDesignerContainerExtension*>(const_cast< DesignerMainWindowStyleContainer*>(this));
    if (!strcmp(_clname, "org.qt-project.Qt.Designer.Container"))
        return static_cast< QDesignerContainerExtension*>(const_cast< DesignerMainWindowStyleContainer*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::DesignerMainWindowStyleContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainerFactory_t {
    QByteArrayData data[1];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainerFactory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainerFactory_t qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainerFactory = {
    {
QT_MOC_LITERAL(0, 0, 47) // "Qtitan::DesignerMainWindowSty..."

    },
    "Qtitan::DesignerMainWindowStyleContainerFactory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__DesignerMainWindowStyleContainerFactory[] = {

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

void Qtitan::DesignerMainWindowStyleContainerFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::DesignerMainWindowStyleContainerFactory::staticMetaObject = {
    { &QExtensionFactory::staticMetaObject, qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainerFactory.data,
      qt_meta_data_Qtitan__DesignerMainWindowStyleContainerFactory,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::DesignerMainWindowStyleContainerFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::DesignerMainWindowStyleContainerFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__DesignerMainWindowStyleContainerFactory.stringdata0))
        return static_cast<void*>(const_cast< DesignerMainWindowStyleContainerFactory*>(this));
    return QExtensionFactory::qt_metacast(_clname);
}

int Qtitan::DesignerMainWindowStyleContainerFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QExtensionFactory::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Qtitan__OfficeStyleDsgnPlugin_t {
    QByteArrayData data[9];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__OfficeStyleDsgnPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__OfficeStyleDsgnPlugin_t qt_meta_stringdata_Qtitan__OfficeStyleDsgnPlugin = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Qtitan::OfficeStyleDsgnPlugin"
QT_MOC_LITERAL(1, 30, 15), // "formWindowAdded"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 29), // "QDesignerFormWindowInterface*"
QT_MOC_LITERAL(4, 77, 10), // "formWindow"
QT_MOC_LITERAL(5, 88, 17), // "formWindowRemoved"
QT_MOC_LITERAL(6, 106, 13), // "widgetManaged"
QT_MOC_LITERAL(7, 120, 8), // "QWidget*"
QT_MOC_LITERAL(8, 129, 6) // "widget"

    },
    "Qtitan::OfficeStyleDsgnPlugin\0"
    "formWindowAdded\0\0QDesignerFormWindowInterface*\0"
    "formWindow\0formWindowRemoved\0widgetManaged\0"
    "QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__OfficeStyleDsgnPlugin[] = {

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

void Qtitan::OfficeStyleDsgnPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OfficeStyleDsgnPlugin *_t = static_cast<OfficeStyleDsgnPlugin *>(_o);
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

const QMetaObject Qtitan::OfficeStyleDsgnPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__OfficeStyleDsgnPlugin.data,
      qt_meta_data_Qtitan__OfficeStyleDsgnPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::OfficeStyleDsgnPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::OfficeStyleDsgnPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__OfficeStyleDsgnPlugin.stringdata0))
        return static_cast<void*>(const_cast< OfficeStyleDsgnPlugin*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< OfficeStyleDsgnPlugin*>(this));
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< OfficeStyleDsgnPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::OfficeStyleDsgnPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_Qtitan__RibbonStyleDsgnPlugin_t {
    QByteArrayData data[9];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__RibbonStyleDsgnPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__RibbonStyleDsgnPlugin_t qt_meta_stringdata_Qtitan__RibbonStyleDsgnPlugin = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Qtitan::RibbonStyleDsgnPlugin"
QT_MOC_LITERAL(1, 30, 15), // "formWindowAdded"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 29), // "QDesignerFormWindowInterface*"
QT_MOC_LITERAL(4, 77, 10), // "formWindow"
QT_MOC_LITERAL(5, 88, 17), // "formWindowRemoved"
QT_MOC_LITERAL(6, 106, 13), // "widgetManaged"
QT_MOC_LITERAL(7, 120, 8), // "QWidget*"
QT_MOC_LITERAL(8, 129, 6) // "widget"

    },
    "Qtitan::RibbonStyleDsgnPlugin\0"
    "formWindowAdded\0\0QDesignerFormWindowInterface*\0"
    "formWindow\0formWindowRemoved\0widgetManaged\0"
    "QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__RibbonStyleDsgnPlugin[] = {

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

void Qtitan::RibbonStyleDsgnPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RibbonStyleDsgnPlugin *_t = static_cast<RibbonStyleDsgnPlugin *>(_o);
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

const QMetaObject Qtitan::RibbonStyleDsgnPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__RibbonStyleDsgnPlugin.data,
      qt_meta_data_Qtitan__RibbonStyleDsgnPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::RibbonStyleDsgnPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::RibbonStyleDsgnPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__RibbonStyleDsgnPlugin.stringdata0))
        return static_cast<void*>(const_cast< RibbonStyleDsgnPlugin*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< RibbonStyleDsgnPlugin*>(this));
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< RibbonStyleDsgnPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::RibbonStyleDsgnPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
