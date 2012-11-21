/****************************************************************************
** Meta object code from reading C++ file 'testwidget.h'
**
** Created: Tue Nov 20 04:27:16 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     134,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     158,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestWidget[] = {
    "TestWidget\0\0on_pushButton_12_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_9_clicked()\0connectError()\0"
    "pathError()\0initError()\0round(int)\0"
    "versionError()\0result(int)\0checkFail()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_6_clicked()\0"
};

void TestWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestWidget *_t = static_cast<TestWidget *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_12_clicked(); break;
        case 1: _t->on_pushButton_11_clicked(); break;
        case 2: _t->on_pushButton_10_clicked(); break;
        case 3: _t->on_pushButton_9_clicked(); break;
        case 4: _t->connectError(); break;
        case 5: _t->pathError(); break;
        case 6: _t->initError(); break;
        case 7: _t->round((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->versionError(); break;
        case 9: _t->result((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->checkFail(); break;
        case 11: _t->on_pushButton_2_clicked(); break;
        case 12: _t->on_pushButton_8_clicked(); break;
        case 13: _t->on_pushButton_7_clicked(); break;
        case 14: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TestWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TestWidget,
      qt_meta_data_TestWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestWidget))
        return static_cast<void*>(const_cast< TestWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TestWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
