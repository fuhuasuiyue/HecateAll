/****************************************************************************
** Meta object code from reading C++ file 'popupwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../popupwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popupwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PopupDemoDialog_t {
    QByteArrayData data[11];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PopupDemoDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PopupDemoDialog_t qt_meta_stringdata_PopupDemoDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PopupDemoDialog"
QT_MOC_LITERAL(1, 16, 24), // "currentIndexChangedStyle"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "index"
QT_MOC_LITERAL(4, 48, 9), // "showPopup"
QT_MOC_LITERAL(5, 58, 11), // "displayTime"
QT_MOC_LITERAL(6, 70, 14), // "animationSpeed"
QT_MOC_LITERAL(7, 85, 19), // "transparencylSlider"
QT_MOC_LITERAL(8, 105, 9), // "allowMove"
QT_MOC_LITERAL(9, 115, 16), // "aboutToShowPopup"
QT_MOC_LITERAL(10, 132, 16) // "aboutToHidePopup"

    },
    "PopupDemoDialog\0currentIndexChangedStyle\0"
    "\0index\0showPopup\0displayTime\0"
    "animationSpeed\0transparencylSlider\0"
    "allowMove\0aboutToShowPopup\0aboutToHidePopup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PopupDemoDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       6,    1,   61,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PopupDemoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PopupDemoDialog *_t = static_cast<PopupDemoDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentIndexChangedStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->showPopup(); break;
        case 2: _t->displayTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->animationSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->transparencylSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->allowMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->aboutToShowPopup(); break;
        case 7: _t->aboutToHidePopup(); break;
        default: ;
        }
    }
}

const QMetaObject PopupDemoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PopupDemoDialog.data,
      qt_meta_data_PopupDemoDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PopupDemoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PopupDemoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PopupDemoDialog.stringdata0))
        return static_cast<void*>(const_cast< PopupDemoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PopupDemoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
