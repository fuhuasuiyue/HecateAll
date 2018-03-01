/****************************************************************************
** Meta object code from reading C++ file 'texteditchild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../texteditchild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'texteditchild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEditChild_t {
    QByteArrayData data[24];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEditChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEditChild_t qt_meta_stringdata_TextEditChild = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TextEditChild"
QT_MOC_LITERAL(1, 14, 8), // "textBold"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "textUnderline"
QT_MOC_LITERAL(4, 38, 10), // "textItalic"
QT_MOC_LITERAL(5, 49, 10), // "textFamily"
QT_MOC_LITERAL(6, 60, 1), // "f"
QT_MOC_LITERAL(7, 62, 8), // "textSize"
QT_MOC_LITERAL(8, 71, 1), // "p"
QT_MOC_LITERAL(9, 73, 9), // "textStyle"
QT_MOC_LITERAL(10, 83, 10), // "styleIndex"
QT_MOC_LITERAL(11, 94, 9), // "textColor"
QT_MOC_LITERAL(12, 104, 3), // "col"
QT_MOC_LITERAL(13, 108, 12), // "setColorText"
QT_MOC_LITERAL(14, 121, 9), // "textAlign"
QT_MOC_LITERAL(15, 131, 8), // "QAction*"
QT_MOC_LITERAL(16, 140, 1), // "a"
QT_MOC_LITERAL(17, 142, 9), // "selectAll"
QT_MOC_LITERAL(18, 152, 24), // "currentCharFormatChanged"
QT_MOC_LITERAL(19, 177, 15), // "QTextCharFormat"
QT_MOC_LITERAL(20, 193, 6), // "format"
QT_MOC_LITERAL(21, 200, 21), // "cursorPositionChanged"
QT_MOC_LITERAL(22, 222, 19), // "documentWasModified"
QT_MOC_LITERAL(23, 242, 20) // "clipboardDataChanged"

    },
    "TextEditChild\0textBold\0\0textUnderline\0"
    "textItalic\0textFamily\0f\0textSize\0p\0"
    "textStyle\0styleIndex\0textColor\0col\0"
    "setColorText\0textAlign\0QAction*\0a\0"
    "selectAll\0currentCharFormatChanged\0"
    "QTextCharFormat\0format\0cursorPositionChanged\0"
    "documentWasModified\0clipboardDataChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEditChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    1,   90,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    1,  100,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      21,    0,  107,    2, 0x08 /* Private */,
      22,    0,  108,    2, 0x08 /* Private */,
      23,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TextEditChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEditChild *_t = static_cast<TextEditChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textBold(); break;
        case 1: _t->textUnderline(); break;
        case 2: _t->textItalic(); break;
        case 3: _t->textFamily((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->textSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->textStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->textColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setColorText(); break;
        case 8: _t->textAlign((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->selectAll(); break;
        case 10: _t->currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 11: _t->cursorPositionChanged(); break;
        case 12: _t->documentWasModified(); break;
        case 13: _t->clipboardDataChanged(); break;
        default: ;
        }
    }
}

const QMetaObject TextEditChild::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_TextEditChild.data,
      qt_meta_data_TextEditChild,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TextEditChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditChild::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditChild.stringdata0))
        return static_cast<void*>(const_cast< TextEditChild*>(this));
    if (!strcmp(_clname, "ChildInterface"))
        return static_cast< ChildInterface*>(const_cast< TextEditChild*>(this));
    if (!strcmp(_clname, "com.qtitan.ribbonmdisample.ChildInterface"))
        return static_cast< ChildInterface*>(const_cast< TextEditChild*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int TextEditChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
