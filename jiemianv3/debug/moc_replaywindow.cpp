/****************************************************************************
** Meta object code from reading C++ file 'replaywindow.h'
**
** Created: Wed Oct 17 01:51:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../replaywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replaywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReplayWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   32,   13,   13, 0x08,
      51,   13,   13,   13, 0x08,
      63,   13,   13,   13, 0x08,
      75,   13,   13,   13, 0x08,
      99,   13,   13,   13, 0x08,
     124,   13,   13,   13, 0x08,
     150,   13,   13,   13, 0x08,
     182,  176,   13,   13, 0x08,
     222,   13,   13,   13, 0x08,
     260,   13,   13,   13, 0x08,
     299,   13,   13,   13, 0x08,
     335,   13,   13,   13, 0x08,
     372,   13,   13,   13, 0x08,
     398,   13,   13,   13, 0x08,
     424,   14,   13,   13, 0x08,
     444,   13,   13,   13, 0x08,
     468,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ReplayWindow[] = {
    "ReplayWindow\0\0i,n\0show(int,int)\0n\0"
    "ChangeRound(int)\0timerStop()\0timerDone()\0"
    "on_loadButton_clicked()\0"
    "on_startButton_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_6_clicked()\0value\0"
    "on_horizontalSlider_2_valueChanged(int)\0"
    "on_horizontalSlider_2_sliderPressed()\0"
    "on_horizontalSlider_2_sliderReleased()\0"
    "on_horizontalSlider_sliderPressed()\0"
    "on_horizontalSlider_sliderReleased()\0"
    "on_stopButton_1_clicked()\0"
    "on_pushButton_2_clicked()\0Label_show(int,int)\0"
    "on_pushButton_clicked()\0GoInto()\0"
};

void ReplayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ReplayWindow *_t = static_cast<ReplayWindow *>(_o);
        switch (_id) {
        case 0: _t->show((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->ChangeRound((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->timerStop(); break;
        case 3: _t->timerDone(); break;
        case 4: _t->on_loadButton_clicked(); break;
        case 5: _t->on_startButton_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_6_clicked(); break;
        case 8: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSlider_2_sliderPressed(); break;
        case 10: _t->on_horizontalSlider_2_sliderReleased(); break;
        case 11: _t->on_horizontalSlider_sliderPressed(); break;
        case 12: _t->on_horizontalSlider_sliderReleased(); break;
        case 13: _t->on_stopButton_1_clicked(); break;
        case 14: _t->on_pushButton_2_clicked(); break;
        case 15: _t->Label_show((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->on_pushButton_clicked(); break;
        case 17: _t->GoInto(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ReplayWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ReplayWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ReplayWindow,
      qt_meta_data_ReplayWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReplayWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReplayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReplayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReplayWindow))
        return static_cast<void*>(const_cast< ReplayWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ReplayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ReplayWindow::show(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
