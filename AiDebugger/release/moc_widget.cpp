/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Wed Nov 21 12:41:34 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      32,    7,    7,    7, 0x08,
      59,    7,    7,    7, 0x08,
      87,    7,    7,    7, 0x08,
     102,    7,    7,    7, 0x08,
     124,    7,    7,    7, 0x08,
     142,    7,    7,    7, 0x08,
     155,    7,    7,    7, 0x08,
     167,    7,    7,    7, 0x08,
     182,    7,    7,    7, 0x08,
     200,    7,    7,    7, 0x08,
     211,    7,    7,    7, 0x08,
     238,  229,    7,    7, 0x08,
     281,  275,    7,    7, 0x08,
     321,    7,    7,    7, 0x08,
     347,  275,    7,    7, 0x08,
     387,    7,    7,    7, 0x08,
     428,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0on_pushButton_clicked()\0"
    "on_pushButton_AI_clicked()\0"
    "on_pushButton_Map_clicked()\0pathError(int)\0"
    "startDebugAI(QString)\0connectError(int)\0"
    "roundUp(int)\0winner(int)\0initError(int)\0"
    "versionError(int)\0Debug(int)\0"
    "startShowReplay()\0position\0"
    "on_horizontalSlider_sliderMoved(int)\0"
    "value\0on_horizontalSlider_2_valueChanged(int)\0"
    "on_pushButton_2_clicked()\0"
    "on_horizontalSlider_3_valueChanged(int)\0"
    "on_pushButton_show_round_minus_clicked()\0"
    "on_pushButton_show_round_plus_clicked()\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_AI_clicked(); break;
        case 2: _t->on_pushButton_Map_clicked(); break;
        case 3: _t->pathError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->startDebugAI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->connectError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->roundUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->winner((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->initError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->versionError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->Debug((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->startShowReplay(); break;
        case 12: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_2_clicked(); break;
        case 15: _t->on_horizontalSlider_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pushButton_show_round_minus_clicked(); break;
        case 17: _t->on_pushButton_show_round_plus_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
