/****************************************************************************
** Meta object code from reading C++ file 'atletooptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/atletooptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'atletooptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AtletoOptions_t {
    QByteArrayData data[9];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AtletoOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AtletoOptions_t qt_meta_stringdata_AtletoOptions = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AtletoOptions"
QT_MOC_LITERAL(1, 14, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "on_dbButton_clicked"
QT_MOC_LITERAL(4, 57, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(5, 78, 16), // "QAbstractButton*"
QT_MOC_LITERAL(6, 95, 6), // "button"
QT_MOC_LITERAL(7, 102, 22), // "on_sqliteRadio_clicked"
QT_MOC_LITERAL(8, 125, 21) // "on_mySqlRadio_clicked"

    },
    "AtletoOptions\0on_buttonBox_accepted\0"
    "\0on_dbButton_clicked\0on_buttonBox_clicked\0"
    "QAbstractButton*\0button\0on_sqliteRadio_clicked\0"
    "on_mySqlRadio_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AtletoOptions[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AtletoOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AtletoOptions *_t = static_cast<AtletoOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_dbButton_clicked(); break;
        case 2: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->on_sqliteRadio_clicked(); break;
        case 4: _t->on_mySqlRadio_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AtletoOptions::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AtletoOptions.data,
      qt_meta_data_AtletoOptions,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AtletoOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AtletoOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AtletoOptions.stringdata0))
        return static_cast<void*>(const_cast< AtletoOptions*>(this));
    return QDialog::qt_metacast(_clname);
}

int AtletoOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
