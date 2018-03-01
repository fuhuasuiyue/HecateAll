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
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "updateRecentFileActions"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "files"
QT_MOC_LITERAL(4, 42, 4), // "open"
QT_MOC_LITERAL(5, 47, 4), // "save"
QT_MOC_LITERAL(6, 52, 14), // "openRecentFile"
QT_MOC_LITERAL(7, 67, 4), // "file"
QT_MOC_LITERAL(8, 72, 5), // "print"
QT_MOC_LITERAL(9, 78, 10), // "printSetup"
QT_MOC_LITERAL(10, 89, 13), // "hideStatusBar"
QT_MOC_LITERAL(11, 103, 5), // "state"
QT_MOC_LITERAL(12, 109, 11), // "pressButton"
QT_MOC_LITERAL(13, 121, 13), // "showBackstage"
QT_MOC_LITERAL(14, 135, 13), // "hideBackstage"
QT_MOC_LITERAL(15, 149, 13) // "setDPIToggled"

    },
    "MainWindow\0updateRecentFileActions\0\0"
    "files\0open\0save\0openRecentFile\0file\0"
    "print\0printSetup\0hideStatusBar\0state\0"
    "pressButton\0showBackstage\0hideBackstage\0"
    "setDPIToggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   72,    2, 0x09 /* Protected */,
       5,    0,   73,    2, 0x09 /* Protected */,
       6,    1,   74,    2, 0x09 /* Protected */,
       8,    0,   77,    2, 0x09 /* Protected */,
       9,    0,   78,    2, 0x09 /* Protected */,
      10,    1,   79,    2, 0x09 /* Protected */,
      12,    0,   82,    2, 0x09 /* Protected */,
      13,    0,   83,    2, 0x09 /* Protected */,
      14,    0,   84,    2, 0x09 /* Protected */,
      15,    1,   85,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRecentFileActions((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->open(); break;
        case 2: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->openRecentFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->print(); break;
        case 5: _t->printSetup(); break;
        case 6: _t->hideStatusBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->pressButton(); break;
        case 8: _t->showBackstage(); break;
        case 9: _t->hideBackstage(); break;
        case 10: _t->setDPIToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::updateRecentFileActions)) {
                *result = 0;
                return;
            }
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

// SIGNAL 0
void MainWindow::updateRecentFileActions(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
