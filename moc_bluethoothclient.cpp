/****************************************************************************
** Meta object code from reading C++ file 'bluethoothclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "bluethooth/bluethoothclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluethoothclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BluethoothClient_t {
    QByteArrayData data[11];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluethoothClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluethoothClient_t qt_meta_stringdata_BluethoothClient = {
    {
QT_MOC_LITERAL(0, 0, 16), // "BluethoothClient"
QT_MOC_LITERAL(1, 17, 8), // "finished"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "deviceDiscovered"
QT_MOC_LITERAL(4, 44, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(5, 65, 6), // "device"
QT_MOC_LITERAL(6, 72, 18), // "finishedDiscovered"
QT_MOC_LITERAL(7, 91, 17), // "serviceDiscovered"
QT_MOC_LITERAL(8, 109, 21), // "QBluetoothServiceInfo"
QT_MOC_LITERAL(9, 131, 11), // "serviceInfo"
QT_MOC_LITERAL(10, 143, 25) // "finishedServiceDiscovered"

    },
    "BluethoothClient\0finished\0\0deviceDiscovered\0"
    "QBluetoothDeviceInfo\0device\0"
    "finishedDiscovered\0serviceDiscovered\0"
    "QBluetoothServiceInfo\0serviceInfo\0"
    "finishedServiceDiscovered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluethoothClient[] = {

 // content:
       8,       // revision
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
       3,    1,   40,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,
       7,    1,   44,    2, 0x0a /* Public */,
      10,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void BluethoothClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BluethoothClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->deviceDiscovered((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 2: _t->finishedDiscovered(); break;
        case 3: _t->serviceDiscovered((*reinterpret_cast< const QBluetoothServiceInfo(*)>(_a[1]))); break;
        case 4: _t->finishedServiceDiscovered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothServiceInfo >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BluethoothClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluethoothClient::finished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BluethoothClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BluethoothClient.data,
    qt_meta_data_BluethoothClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BluethoothClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluethoothClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BluethoothClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BluethoothClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void BluethoothClient::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
