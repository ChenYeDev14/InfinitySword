/****************************************************************************
** Meta object code from reading C++ file 'TestBattle.h'
**
** Created: Wed Oct 24 01:47:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../platform/TestBattle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestBattle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestBattle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      25,   11,   11,   11, 0x05,
      41,   11,   11,   11, 0x05,
      54,   11,   11,   11, 0x05,
      66,   11,   11,   11, 0x05,
      82,   11,   11,   11, 0x05,
      96,   11,   11,   11, 0x05,
     109,   11,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_TestBattle[] = {
    "TestBattle\0\0path_error()\0connect_error()\0"
    "init_error()\0mem_error()\0version_error()\0"
    "game_end(int)\0check_fail()\0round_up(int)\0"
};

void TestBattle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestBattle *_t = static_cast<TestBattle *>(_o);
        switch (_id) {
        case 0: _t->path_error(); break;
        case 1: _t->connect_error(); break;
        case 2: _t->init_error(); break;
        case 3: _t->mem_error(); break;
        case 4: _t->version_error(); break;
        case 5: _t->game_end((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->check_fail(); break;
        case 7: _t->round_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TestBattle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestBattle::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TestBattle,
      qt_meta_data_TestBattle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestBattle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestBattle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestBattle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestBattle))
        return static_cast<void*>(const_cast< TestBattle*>(this));
    return QThread::qt_metacast(_clname);
}

int TestBattle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TestBattle::path_error()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TestBattle::connect_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TestBattle::init_error()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TestBattle::mem_error()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TestBattle::version_error()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void TestBattle::game_end(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TestBattle::check_fail()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void TestBattle::round_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
