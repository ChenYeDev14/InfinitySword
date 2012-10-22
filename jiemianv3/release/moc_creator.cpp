/****************************************************************************
** Meta object code from reading C++ file 'creator.h'
**
** Created: Sun Oct 21 19:01:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../creator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Creator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      25,    8,    8,    8, 0x08,
      41,    8,    8,    8, 0x08,
      54,    8,    8,    8, 0x08,
      67,    8,    8,    8, 0x08,
      86,    8,    8,    8, 0x08,
     105,    8,    8,    8, 0x08,
     119,    8,    8,    8, 0x08,
     133,    8,    8,    8, 0x08,
     147,    8,    8,    8, 0x08,
     161,    8,    8,    8, 0x08,
     169,    8,    8,    8, 0x08,
     187,    8,    8,    8, 0x08,
     205,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Creator[] = {
    "Creator\0\0BeginToSingle()\0SingleToBegin()\0"
    "SingleToAi()\0AiToSingle()\0SingleToReplayer()\0"
    "ReplayerToSingle()\0TeamToBegin()\0"
    "BeginToTeam()\0MapToSingle()\0SingLeToMap()\0"
    "Music()\0SingleToHumanai()\0HumanaiToSingle()\0"
    "continueMusic()\0"
};

void Creator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Creator *_t = static_cast<Creator *>(_o);
        switch (_id) {
        case 0: _t->BeginToSingle(); break;
        case 1: _t->SingleToBegin(); break;
        case 2: _t->SingleToAi(); break;
        case 3: _t->AiToSingle(); break;
        case 4: _t->SingleToReplayer(); break;
        case 5: _t->ReplayerToSingle(); break;
        case 6: _t->TeamToBegin(); break;
        case 7: _t->BeginToTeam(); break;
        case 8: _t->MapToSingle(); break;
        case 9: _t->SingLeToMap(); break;
        case 10: _t->Music(); break;
        case 11: _t->SingleToHumanai(); break;
        case 12: _t->HumanaiToSingle(); break;
        case 13: _t->continueMusic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Creator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Creator::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Creator,
      qt_meta_data_Creator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Creator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Creator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Creator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Creator))
        return static_cast<void*>(const_cast< Creator*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Creator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
