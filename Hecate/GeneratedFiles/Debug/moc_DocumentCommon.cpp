/****************************************************************************
** Meta object code from reading C++ file 'DocumentCommon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DocumentCommon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DocumentCommon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DocumentCommon_t {
    QByteArrayData data[16];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocumentCommon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocumentCommon_t qt_meta_stringdata_DocumentCommon = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DocumentCommon"
QT_MOC_LITERAL(1, 15, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "sendCloseDocument"
QT_MOC_LITERAL(4, 51, 15), // "DocumentCommon*"
QT_MOC_LITERAL(5, 67, 11), // "onCloseView"
QT_MOC_LITERAL(6, 79, 10), // "MDIWindow*"
QT_MOC_LITERAL(7, 90, 15), // "onCreateNewView"
QT_MOC_LITERAL(8, 106, 10), // "onMaterial"
QT_MOC_LITERAL(9, 117, 8), // "onDelete"
QT_MOC_LITERAL(10, 126, 11), // "onWireframe"
QT_MOC_LITERAL(11, 138, 9), // "onShading"
QT_MOC_LITERAL(12, 148, 7), // "onColor"
QT_MOC_LITERAL(13, 156, 14), // "onTransparency"
QT_MOC_LITERAL(14, 171, 15), // "onImportSTPFile"
QT_MOC_LITERAL(15, 187, 15) // "onSelectedModel"

    },
    "DocumentCommon\0selectionChanged\0\0"
    "sendCloseDocument\0DocumentCommon*\0"
    "onCloseView\0MDIWindow*\0onCreateNewView\0"
    "onMaterial\0onDelete\0onWireframe\0"
    "onShading\0onColor\0onTransparency\0"
    "onImportSTPFile\0onSelectedModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocumentCommon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   88,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       8,    1,   93,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DocumentCommon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DocumentCommon *_t = static_cast<DocumentCommon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->sendCloseDocument((*reinterpret_cast< DocumentCommon*(*)>(_a[1]))); break;
        case 2: _t->onCloseView((*reinterpret_cast< MDIWindow*(*)>(_a[1]))); break;
        case 3: _t->onCreateNewView(); break;
        case 4: _t->onMaterial(); break;
        case 5: _t->onMaterial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onDelete(); break;
        case 7: _t->onWireframe(); break;
        case 8: _t->onShading(); break;
        case 9: _t->onColor(); break;
        case 10: _t->onTransparency(); break;
        case 11: _t->onTransparency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->onImportSTPFile(); break;
        case 13: _t->onSelectedModel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DocumentCommon* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MDIWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DocumentCommon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocumentCommon::selectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DocumentCommon::*_t)(DocumentCommon * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocumentCommon::sendCloseDocument)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DocumentCommon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DocumentCommon.data,
      qt_meta_data_DocumentCommon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DocumentCommon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocumentCommon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentCommon.stringdata0))
        return static_cast<void*>(const_cast< DocumentCommon*>(this));
    return QObject::qt_metacast(_clname);
}

int DocumentCommon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void DocumentCommon::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DocumentCommon::sendCloseDocument(DocumentCommon * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
