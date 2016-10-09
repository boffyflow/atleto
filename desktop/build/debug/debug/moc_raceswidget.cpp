/****************************************************************************
** Meta object code from reading C++ file 'raceswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/raceswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'raceswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RacesWidget_t {
    QByteArrayData data[12];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RacesWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RacesWidget_t qt_meta_stringdata_RacesWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RacesWidget"
QT_MOC_LITERAL(1, 12, 11), // "updateYears"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "rebuildTable"
QT_MOC_LITERAL(4, 38, 31), // "on_racesTable_itemDoubleClicked"
QT_MOC_LITERAL(5, 70, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 88, 4), // "item"
QT_MOC_LITERAL(7, 93, 26), // "on_gunTimeCheckBox_toggled"
QT_MOC_LITERAL(8, 120, 7), // "checked"
QT_MOC_LITERAL(9, 128, 21), // "on_pbCheckBox_toggled"
QT_MOC_LITERAL(10, 150, 22), // "on_yearCombo_activated"
QT_MOC_LITERAL(11, 173, 26) // "on_distanceCombo_activated"

    },
    "RacesWidget\0updateYears\0\0rebuildTable\0"
    "on_racesTable_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0"
    "on_gunTimeCheckBox_toggled\0checked\0"
    "on_pbCheckBox_toggled\0on_yearCombo_activated\0"
    "on_distanceCombo_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RacesWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      11,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void RacesWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RacesWidget *_t = static_cast<RacesWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateYears(); break;
        case 1: _t->rebuildTable(); break;
        case 2: _t->on_racesTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_gunTimeCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pbCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_yearCombo_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_distanceCombo_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RacesWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RacesWidget.data,
      qt_meta_data_RacesWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RacesWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RacesWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RacesWidget.stringdata0))
        return static_cast<void*>(const_cast< RacesWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RacesWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
