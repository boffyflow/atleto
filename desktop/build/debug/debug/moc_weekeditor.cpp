/****************************************************************************
** Meta object code from reading C++ file 'weekeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/weekeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weekeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeekEditor_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeekEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeekEditor_t qt_meta_stringdata_WeekEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WeekEditor"
QT_MOC_LITERAL(1, 11, 11), // "dataChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "dayChanged"
QT_MOC_LITERAL(4, 35, 22), // "on_todayButton_clicked"
QT_MOC_LITERAL(5, 58, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(6, 80, 21), // "on_prevButton_clicked"
QT_MOC_LITERAL(7, 102, 23), // "on_dateEdit_dateChanged"
QT_MOC_LITERAL(8, 126, 4), // "date"
QT_MOC_LITERAL(9, 131, 15) // "weekViewChanged"

    },
    "WeekEditor\0dataChanged\0\0dayChanged\0"
    "on_todayButton_clicked\0on_nextButton_clicked\0"
    "on_prevButton_clicked\0on_dateEdit_dateChanged\0"
    "date\0weekViewChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeekEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   53,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    8,
    QMetaType::Void,

       0        // eod
};

void WeekEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeekEditor *_t = static_cast<WeekEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->dayChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->on_todayButton_clicked(); break;
        case 3: _t->on_nextButton_clicked(); break;
        case 4: _t->on_prevButton_clicked(); break;
        case 5: _t->on_dateEdit_dateChanged((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 6: _t->weekViewChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeekEditor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeekEditor::dataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeekEditor::*_t)(const QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeekEditor::dayChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WeekEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WeekEditor.data,
      qt_meta_data_WeekEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeekEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeekEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeekEditor.stringdata0))
        return static_cast<void*>(const_cast< WeekEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int WeekEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void WeekEditor::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void WeekEditor::dayChanged(const QDate & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
