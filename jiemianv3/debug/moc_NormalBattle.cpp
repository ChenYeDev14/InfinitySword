/****************************************************************************
** Meta object code from reading C++ file 'NormalBattle.h'
**
** Created: Wed Oct 24 01:42:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../platform/NormalBattle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NormalBattle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DS14__AiReadWriteThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_DS14__AiReadWriteThread[] = {
    "DS14::AiReadWriteThread\0\0connectError()\0"
};

void DS14::AiReadWriteThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AiReadWriteThread *_t = static_cast<AiReadWriteThread *>(_o);
        switch (_id) {
        case 0: _t->connectError(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DS14::AiReadWriteThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DS14::AiReadWriteThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DS14__AiReadWriteThread,
      qt_meta_data_DS14__AiReadWriteThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DS14::AiReadWriteThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DS14::AiReadWriteThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DS14::AiReadWriteThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DS14__AiReadWriteThread))
        return static_cast<void*>(const_cast< AiReadWriteThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DS14::AiReadWriteThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DS14::AiReadWriteThread::connectError()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_DS14__NormalBattle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      36,   19,   19,   19, 0x05,
      55,   19,   19,   19, 0x05,
      71,   19,   19,   19, 0x05,
      88,   19,   19,   19, 0x05,
     104,   99,   19,   19, 0x05,
     131,   19,   19,   19, 0x05,
     143,   19,   19,   19, 0x05,
     173,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     192,   19,   19,   19, 0x0a,
     208,   19,   19,   19, 0x0a,
     214,   19,   19,   19, 0x0a,
     237,   19,   19,   19, 0x0a,
     258,   19,   19,   19, 0x0a,
     271,   19,   19,   19, 0x0a,
     290,  288,   19,   19, 0x0a,
     308,   19,   19,   19, 0x08,
     330,   19,   19,   19, 0x08,
     352,   19,   19,   19, 0x08,
     371,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DS14__NormalBattle[] = {
    "DS14::NormalBattle\0\0path_error(int)\0"
    "connect_error(int)\0init_error(int)\0"
    "send_winner(int)\0round(int)\0name\0"
    "ready_for_connect(QString)\0mem_error()\0"
    "debug_battle_logic_prepared()\0"
    "version_error(int)\0ready_connect()\0"
    "end()\0change_to_debug_mode()\0"
    "change_to_run_mode()\0stopBattle()\0"
    "continueBattle()\0t\0setSleepTime(int)\0"
    "send_connect_error1()\0send_connect_error2()\0"
    "send_init_error1()\0send_init_error2()\0"
};

void DS14::NormalBattle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NormalBattle *_t = static_cast<NormalBattle *>(_o);
        switch (_id) {
        case 0: _t->path_error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->connect_error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->init_error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->send_winner((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->round((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ready_for_connect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->mem_error(); break;
        case 7: _t->debug_battle_logic_prepared(); break;
        case 8: _t->version_error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ready_connect(); break;
        case 10: _t->end(); break;
        case 11: _t->change_to_debug_mode(); break;
        case 12: _t->change_to_run_mode(); break;
        case 13: _t->stopBattle(); break;
        case 14: _t->continueBattle(); break;
        case 15: _t->setSleepTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->send_connect_error1(); break;
        case 17: _t->send_connect_error2(); break;
        case 18: _t->send_init_error1(); break;
        case 19: _t->send_init_error2(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DS14::NormalBattle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DS14::NormalBattle::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DS14__NormalBattle,
      qt_meta_data_DS14__NormalBattle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DS14::NormalBattle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DS14::NormalBattle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DS14::NormalBattle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DS14__NormalBattle))
        return static_cast<void*>(const_cast< NormalBattle*>(this));
    return QThread::qt_metacast(_clname);
}

int DS14::NormalBattle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void DS14::NormalBattle::path_error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DS14::NormalBattle::connect_error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DS14::NormalBattle::init_error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DS14::NormalBattle::send_winner(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DS14::NormalBattle::round(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DS14::NormalBattle::ready_for_connect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DS14::NormalBattle::mem_error()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void DS14::NormalBattle::debug_battle_logic_prepared()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void DS14::NormalBattle::version_error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
