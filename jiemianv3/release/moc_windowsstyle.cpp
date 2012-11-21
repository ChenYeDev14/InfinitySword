/****************************************************************************
** Meta object code from reading C++ file 'windowsstyle.h'
**
** Created: Tue Nov 6 14:07:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../windowsstyle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowsstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Style[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   13,    7,    6, 0x0a,
     124,  111,    7,    6, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_Style[] = {
    "Style\0\0QIcon\0which,option,widget\0"
    "standardIconImplementation(StandardPixmap,const QStyleOption*,const QW"
    "idget*)\0"
    "which,option\0"
    "standardIconImplementation(StandardPixmap,const QStyleOption*)\0"
};

void Style::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Style *_t = static_cast<Style *>(_o);
        switch (_id) {
        case 0: { QIcon _r = _t->standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])),(*reinterpret_cast< const QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 1: { QIcon _r = _t->standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Style::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Style::staticMetaObject = {
    { &QWindowsStyle::staticMetaObject, qt_meta_stringdata_Style,
      qt_meta_data_Style, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Style::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Style::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Style::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Style))
        return static_cast<void*>(const_cast< Style*>(this));
    return QWindowsStyle::qt_metacast(_clname);
}

int Style::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWindowsStyle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
