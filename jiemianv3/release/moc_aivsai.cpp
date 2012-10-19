/****************************************************************************
** Meta object code from reading C++ file 'aivsai.h'
**
** Created: Fri Oct 19 04:41:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aivsai.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aivsai.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AIvsAI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      14,    7,    7,    7, 0x08,
      20,    7,    7,    7, 0x08,
      39,    7,    7,    7, 0x08,
      45,    7,    7,    7, 0x08,
      63,    7,    7,    7, 0x08,
      78,    7,    7,    7, 0x08,
      93,    7,    7,    7, 0x08,
     109,    7,    7,    7, 0x08,
     120,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AIvsAI[] = {
    "AIvsAI\0\0AI1()\0AI2()\0on_Start_clicked()\0"
    "Map()\0connectError(int)\0initError(int)\0"
    "pathError(int)\0sendWinner(int)\0"
    "round(int)\0versionError(int)\0"
};

void AIvsAI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AIvsAI *_t = static_cast<AIvsAI *>(_o);
        switch (_id) {
        case 0: _t->AI1(); break;
        case 1: _t->AI2(); break;
        case 2: _t->on_Start_clicked(); break;
        case 3: _t->Map(); break;
        case 4: _t->connectError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->initError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->pathError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sendWinner((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->round((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->versionError((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AIvsAI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AIvsAI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AIvsAI,
      qt_meta_data_AIvsAI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AIvsAI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AIvsAI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AIvsAI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AIvsAI))
        return static_cast<void*>(const_cast< AIvsAI*>(this));
    return QWidget::qt_metacast(_clname);
}

int AIvsAI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
