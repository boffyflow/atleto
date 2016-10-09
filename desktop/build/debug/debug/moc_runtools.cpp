/****************************************************************************
** Meta object code from reading C++ file 'runtools.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/runtools.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runtools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RunTools_t {
    QByteArrayData data[14];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RunTools_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RunTools_t qt_meta_stringdata_RunTools = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RunTools"
QT_MOC_LITERAL(1, 9, 32), // "on_outputDistanceCombo_activated"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 28), // "on_inputTimeEdit_timeChanged"
QT_MOC_LITERAL(4, 72, 4), // "date"
QT_MOC_LITERAL(5, 77, 40), // "on_inputDistanceLineEdit_edit..."
QT_MOC_LITERAL(6, 118, 23), // "on_raceTime_timeChanged"
QT_MOC_LITERAL(7, 142, 27), // "on_raceTime_editingFinished"
QT_MOC_LITERAL(8, 170, 22), // "on_raceCombo_activated"
QT_MOC_LITERAL(9, 193, 5), // "index"
QT_MOC_LITERAL(10, 199, 36), // "on_unitsComboBox_currentIndex..."
QT_MOC_LITERAL(11, 236, 5), // "units"
QT_MOC_LITERAL(12, 242, 32), // "on_inputTimeEdit_dateTimeChanged"
QT_MOC_LITERAL(13, 275, 9) // "inputTime"

    },
    "RunTools\0on_outputDistanceCombo_activated\0"
    "\0on_inputTimeEdit_timeChanged\0date\0"
    "on_inputDistanceLineEdit_editingFinished\0"
    "on_raceTime_timeChanged\0"
    "on_raceTime_editingFinished\0"
    "on_raceCombo_activated\0index\0"
    "on_unitsComboBox_currentIndexChanged\0"
    "units\0on_inputTimeEdit_dateTimeChanged\0"
    "inputTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RunTools[] = {

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
       1,    1,   54,    2, 0x08 /* Private */,
       3,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QTime,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QDateTime,   13,

       0        // eod
};

void RunTools::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RunTools *_t = static_cast<RunTools *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_outputDistanceCombo_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_inputTimeEdit_timeChanged((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 2: _t->on_inputDistanceLineEdit_editingFinished(); break;
        case 3: _t->on_raceTime_timeChanged((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 4: _t->on_raceTime_editingFinished(); break;
        case 5: _t->on_raceCombo_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_unitsComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_inputTimeEdit_dateTimeChanged((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RunTools::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RunTools.data,
      qt_meta_data_RunTools,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RunTools::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RunTools::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RunTools.stringdata0))
        return static_cast<void*>(const_cast< RunTools*>(this));
    return QDialog::qt_metacast(_clname);
}

int RunTools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
