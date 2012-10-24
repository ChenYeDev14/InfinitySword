/****************************************************************************
** Meta object code from reading C++ file 'humanai_aithread.h'
**
** Created: Wed Oct 24 01:32:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../humanai_aithread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'humanai_aithread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AiThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      23,    9,    9,    9, 0x05,
      39,    9,    9,    9, 0x05,
      52,    9,    9,    9, 0x05,
      64,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_AiThread[] = {
    "AiThread\0\0path_error()\0connect_error()\0"
    "init_error()\0mem_error()\0version_error()\0"
};

void AiThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AiThread *_t = static_cast<AiThread *>(_o);
        switch (_id) {
        case 0: _t->path_error(); break;
        case 1: _t->connect_error(); break;
        case 2: _t->init_error(); break;
        case 3: _t->mem_error(); break;
        case 4: _t->version_error(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AiThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AiThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AiThread,
      qt_meta_data_AiThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AiThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AiThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AiThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AiThread))
        return static_cast<void*>(const_cast< AiThread*>(this));
    return QThread::qt_metacast(_clname);
}

int AiThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AiThread::path_error()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AiThread::connect_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AiThread::init_error()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void AiThread::mem_error()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void AiThread::version_error()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
