/****************************************************************************
** Meta object code from reading C++ file 'humanai_maindevice.h'
**
** Created: Fri Oct 19 03:17:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../humanai_maindevice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'humanai_maindevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_maindevice[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_maindevice[] = {
    "maindevice\0\0gameEnd(int)\0GameUpdate()\0"
    "LoadMap()\0LoadAI()\0StartGame()\0"
    "connectError()\0initError()\0pathError()\0"
    "versionError()\0end()\0"
};

void maindevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        maindevice *_t = static_cast<maindevice *>(_o);
        switch (_id) {
        case 0: _t->gameEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->GameUpdate(); break;
        case 2: _t->LoadMap(); break;
        case 3: _t->LoadAI(); break;
        case 4: _t->StartGame(); break;
        case 5: _t->connectError(); break;
        case 6: _t->initError(); break;
        case 7: _t->pathError(); break;
        case 8: _t->versionError(); break;
        case 9: _t->end(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData maindevice::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject maindevice::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_maindevice,
      qt_meta_data_maindevice, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &maindevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *maindevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *maindevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_maindevice))
        return static_cast<void*>(const_cast< maindevice*>(this));
    return QWidget::qt_metacast(_clname);
}

int maindevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void maindevice::gameEnd(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
