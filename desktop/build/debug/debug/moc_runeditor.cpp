/****************************************************************************
** Meta object code from reading C++ file 'runeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/runeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RunEditor_t {
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RunEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RunEditor_t qt_meta_stringdata_RunEditor = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RunEditor"
QT_MOC_LITERAL(1, 10, 23), // "on_reloadButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(4, 59, 23), // "on_raceCheckBox_toggled"
QT_MOC_LITERAL(5, 83, 7), // "checked"
QT_MOC_LITERAL(6, 91, 11), // "updateTable"
QT_MOC_LITERAL(7, 103, 14), // "QStandardItem*"
QT_MOC_LITERAL(8, 118, 4), // "item"
QT_MOC_LITERAL(9, 123, 8), // "storeRun"
QT_MOC_LITERAL(10, 132, 11) // "setRaceInfo"

    },
    "RunEditor\0on_reloadButton_clicked\0\0"
    "on_deleteButton_clicked\0on_raceCheckBox_toggled\0"
    "checked\0updateTable\0QStandardItem*\0"
    "item\0storeRun\0setRaceInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RunEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RunEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RunEditor *_t = static_cast<RunEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_reloadButton_clicked(); break;
        case 1: _t->on_deleteButton_clicked(); break;
        case 2: _t->on_raceCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->updateTable((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 4: _t->storeRun(); break;
        case 5: _t->setRaceInfo(); break;
        default: ;
        }
    }
}

const QMetaObject RunEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RunEditor.data,
      qt_meta_data_RunEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RunEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RunEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RunEditor.stringdata0))
        return static_cast<void*>(const_cast< RunEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int RunEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
