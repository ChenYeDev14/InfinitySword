/****************************************************************************
** Meta object code from reading C++ file 'humanai.h'
**
** Created: Wed Nov 21 12:35:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../humanai.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'humanai.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_humanai[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      21,    8,    8,    8, 0x08,
      34,    8,    8,    8, 0x08,
      44,    8,    8,    8, 0x08,
      53,    8,    8,    8, 0x08,
      65,    8,    8,    8, 0x08,
      80,    8,    8,    8, 0x08,
      92,    8,    8,    8, 0x08,
     104,    8,    8,    8, 0x08,
     119,    8,    8,    8, 0x08,
     125,    8,    8,    8, 0x08,
     148,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_humanai[] = {
    "humanai\0\0initEmpty()\0GameUpdate()\0"
    "LoadMap()\0LoadAI()\0StartGame()\0"
    "connectError()\0initError()\0pathError()\0"
    "versionError()\0end()\0ai_init_ready(QString)\0"
    "on_Button_help_clicked()\0"
};

void humanai::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        humanai *_t = static_cast<humanai *>(_o);
        switch (_id) {
        case 0: _t->initEmpty(); break;
        case 1: _t->GameUpdate(); break;
        case 2: _t->LoadMap(); break;
        case 3: _t->LoadAI(); break;
        case 4: _t->StartGame(); break;
        case 5: _t->connectError(); break;
        case 6: _t->initError(); break;
        case 7: _t->pathError(); break;
        case 8: _t->versionError(); break;
        case 9: _t->end(); break;
        case 10: _t->ai_init_ready((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_Button_help_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData humanai::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject humanai::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_humanai,
      qt_meta_data_humanai, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &humanai::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *humanai::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *humanai::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_humanai))
        return static_cast<void*>(const_cast< humanai*>(this));
    return QWidget::qt_metacast(_clname);
}

int humanai::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
