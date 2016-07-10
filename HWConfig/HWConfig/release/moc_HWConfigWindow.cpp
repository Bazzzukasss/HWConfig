/****************************************************************************
** Meta object code from reading C++ file 'HWConfigWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HWConfigWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HWConfigWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HWConfigWindow_t {
    QByteArrayData data[8];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HWConfigWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HWConfigWindow_t qt_meta_stringdata_HWConfigWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "HWConfigWindow"
QT_MOC_LITERAL(1, 15, 9), // "cmdSended"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 29), // "on_lineEdit_CMD_returnPressed"
QT_MOC_LITERAL(4, 56, 43), // "on_comboBox_CONNECTIONS_curre..."
QT_MOC_LITERAL(5, 100, 5), // "index"
QT_MOC_LITERAL(6, 106, 12), // "on_cmdSended"
QT_MOC_LITERAL(7, 119, 22) // "on_cmd_BUTTONS_clicked"

    },
    "HWConfigWindow\0cmdSended\0\0"
    "on_lineEdit_CMD_returnPressed\0"
    "on_comboBox_CONNECTIONS_currentIndexChanged\0"
    "index\0on_cmdSended\0on_cmd_BUTTONS_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HWConfigWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HWConfigWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HWConfigWindow *_t = static_cast<HWConfigWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cmdSended(); break;
        case 1: _t->on_lineEdit_CMD_returnPressed(); break;
        case 2: _t->on_comboBox_CONNECTIONS_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_cmdSended(); break;
        case 4: _t->on_cmd_BUTTONS_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HWConfigWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HWConfigWindow::cmdSended)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject HWConfigWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HWConfigWindow.data,
      qt_meta_data_HWConfigWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HWConfigWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HWConfigWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HWConfigWindow.stringdata0))
        return static_cast<void*>(const_cast< HWConfigWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HWConfigWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void HWConfigWindow::cmdSended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
