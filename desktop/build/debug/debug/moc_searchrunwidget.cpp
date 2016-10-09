/****************************************************************************
** Meta object code from reading C++ file 'searchrunwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/searchrunwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchrunwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchRunWidget_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchRunWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchRunWidget_t qt_meta_stringdata_SearchRunWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SearchRunWidget"
QT_MOC_LITERAL(1, 16, 34), // "on_resultsWidget_itemDoubleCl..."
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 69, 4), // "item"
QT_MOC_LITERAL(5, 74, 6), // "column"
QT_MOC_LITERAL(6, 81, 23) // "on_searchButton_clicked"

    },
    "SearchRunWidget\0on_resultsWidget_itemDoubleClicked\0"
    "\0QTreeWidgetItem*\0item\0column\0"
    "on_searchButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchRunWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       6,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

       0        // eod
};

void SearchRunWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchRunWidget *_t = static_cast<SearchRunWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_resultsWidget_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_searchButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SearchRunWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SearchRunWidget.data,
      qt_meta_data_SearchRunWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SearchRunWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchRunWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SearchRunWidget.stringdata0))
        return static_cast<void*>(const_cast< SearchRunWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SearchRunWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
