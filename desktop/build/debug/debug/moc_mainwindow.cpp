/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "updateStatus"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 27), // "on_actionPlotTest_triggered"
QT_MOC_LITERAL(4, 53, 29), // "on_actionImport_TCX_triggered"
QT_MOC_LITERAL(5, 83, 26), // "on_actionOptions_triggered"
QT_MOC_LITERAL(6, 110, 31), // "on_actionAbout_Atleto_triggered"
QT_MOC_LITERAL(7, 142, 24), // "on_actionRaces_triggered"
QT_MOC_LITERAL(8, 167, 27), // "on_actionCalendar_triggered"
QT_MOC_LITERAL(9, 195, 24), // "on_actionShoes_triggered"
QT_MOC_LITERAL(10, 220, 33), // "on_actionRun_Calculator_trigg..."
QT_MOC_LITERAL(11, 254, 29), // "on_actionSearch_Run_triggered"
QT_MOC_LITERAL(12, 284, 26), // "on_actionAthlete_triggered"
QT_MOC_LITERAL(13, 311, 35), // "on_actionReport_Generator_tri..."
QT_MOC_LITERAL(14, 347, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(15, 371, 27) // "on_actionAbout_Qt_triggered"

    },
    "MainWindow\0updateStatus\0\0"
    "on_actionPlotTest_triggered\0"
    "on_actionImport_TCX_triggered\0"
    "on_actionOptions_triggered\0"
    "on_actionAbout_Atleto_triggered\0"
    "on_actionRaces_triggered\0"
    "on_actionCalendar_triggered\0"
    "on_actionShoes_triggered\0"
    "on_actionRun_Calculator_triggered\0"
    "on_actionSearch_Run_triggered\0"
    "on_actionAthlete_triggered\0"
    "on_actionReport_Generator_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionAbout_Qt_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
       8,    1,   92,    2, 0x08 /* Private */,
       9,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateStatus(); break;
        case 1: _t->on_actionPlotTest_triggered(); break;
        case 2: _t->on_actionImport_TCX_triggered(); break;
        case 3: _t->on_actionOptions_triggered(); break;
        case 4: _t->on_actionAbout_Atleto_triggered(); break;
        case 5: _t->on_actionRaces_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_actionCalendar_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_actionShoes_triggered(); break;
        case 8: _t->on_actionRun_Calculator_triggered(); break;
        case 9: _t->on_actionSearch_Run_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_actionAthlete_triggered(); break;
        case 11: _t->on_actionReport_Generator_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_actionQuit_triggered(); break;
        case 13: _t->on_actionAbout_Qt_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
