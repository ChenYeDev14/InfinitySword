/****************************************************************************
** Meta object code from reading C++ file 'mapeditor.h'
**
** Created: Sat Oct 20 17:35:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mapeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MapEditor[] = {

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
      11,   10,   10,   10, 0x08,
      21,   10,   10,   10, 0x08,
      31,   10,   10,   10, 0x08,
      41,   10,   10,   10, 0x08,
      51,   10,   10,   10, 0x08,
      61,   10,   10,   10, 0x08,
      71,   10,   10,   10, 0x08,
      81,   10,   10,   10, 0x08,
      88,   10,   10,   10, 0x08,
      95,   10,   10,   10, 0x08,
     105,   10,   10,   10, 0x08,
     131,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MapEditor[] = {
    "MapEditor\0\0Radio_1()\0Radio_2()\0Radio_3()\0"
    "Radio_4()\0Radio_5()\0Radio_6()\0Radio_7()\0"
    "Save()\0Open()\0newFile()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_4_clicked()\0"
};

void MapEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapEditor *_t = static_cast<MapEditor *>(_o);
        switch (_id) {
        case 0: _t->Radio_1(); break;
        case 1: _t->Radio_2(); break;
        case 2: _t->Radio_3(); break;
        case 3: _t->Radio_4(); break;
        case 4: _t->Radio_5(); break;
        case 5: _t->Radio_6(); break;
        case 6: _t->Radio_7(); break;
        case 7: _t->Save(); break;
        case 8: _t->Open(); break;
        case 9: _t->newFile(); break;
        case 10: _t->on_pushButton_6_clicked(); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MapEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MapEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapEditor,
      qt_meta_data_MapEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MapEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MapEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MapEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MapEditor))
        return static_cast<void*>(const_cast< MapEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int MapEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
