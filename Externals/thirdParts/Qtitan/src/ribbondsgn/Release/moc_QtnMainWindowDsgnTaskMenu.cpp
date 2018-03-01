/****************************************************************************
** Meta object code from reading C++ file 'QtnMainWindowDsgnTaskMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtnMainWindowDsgnTaskMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnMainWindowDsgnTaskMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__MainWindowDsgnTaskMenu_t {
    QByteArrayData data[3];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__MainWindowDsgnTaskMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__MainWindowDsgnTaskMenu_t qt_meta_stringdata_Qtitan__MainWindowDsgnTaskMenu = {
    {
QT_MOC_LITERAL(0, 0, 30), // "Qtitan::MainWindowDsgnTaskMenu"
QT_MOC_LITERAL(1, 31, 15), // "createRibbonBar"
QT_MOC_LITERAL(2, 47, 0) // ""

    },
    "Qtitan::MainWindowDsgnTaskMenu\0"
    "createRibbonBar\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__MainWindowDsgnTaskMenu[] = {

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
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Qtitan::MainWindowDsgnTaskMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowDsgnTaskMenu *_t = static_cast<MainWindowDsgnTaskMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createRibbonBar(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::MainWindowDsgnTaskMenu::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qtitan__MainWindowDsgnTaskMenu.data,
      qt_meta_data_Qtitan__MainWindowDsgnTaskMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::MainWindowDsgnTaskMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::MainWindowDsgnTaskMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__MainWindowDsgnTaskMenu.stringdata0))
        return static_cast<void*>(const_cast< MainWindowDsgnTaskMenu*>(this));
    if (!strcmp(_clname, "QDesignerTaskMenuExtension"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< MainWindowDsgnTaskMenu*>(this));
    if (!strcmp(_clname, "org.qt-project.Qt.Designer.TaskMenu"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< MainWindowDsgnTaskMenu*>(this));
    return QObject::qt_metacast(_clname);
}

int Qtitan::MainWindowDsgnTaskMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_Qtitan__MainWindowMenuExFactory_t {
    QByteArrayData data[1];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__MainWindowMenuExFactory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__MainWindowMenuExFactory_t qt_meta_stringdata_Qtitan__MainWindowMenuExFactory = {
    {
QT_MOC_LITERAL(0, 0, 31) // "Qtitan::MainWindowMenuExFactory"

    },
    "Qtitan::MainWindowMenuExFactory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__MainWindowMenuExFactory[] = {

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

void Qtitan::MainWindowMenuExFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Qtitan::MainWindowMenuExFactory::staticMetaObject = {
    { &QExtensionFactory::staticMetaObject, qt_meta_stringdata_Qtitan__MainWindowMenuExFactory.data,
      qt_meta_data_Qtitan__MainWindowMenuExFactory,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtitan::MainWindowMenuExFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::MainWindowMenuExFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__MainWindowMenuExFactory.stringdata0))
        return static_cast<void*>(const_cast< MainWindowMenuExFactory*>(this));
    return QExtensionFactory::qt_metacast(_clname);
}

int Qtitan::MainWindowMenuExFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QExtensionFactory::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
