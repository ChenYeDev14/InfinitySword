/****************************************************************************
** Meta object code from reading C++ file 'loginwidget.h'
**
** Created: Thu Oct 25 19:16:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loginwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogInWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   12,   12,   12, 0x08,
      44,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LogInWidget[] = {
    "LogInWidget\0\0login_success(QString)\0"
    "LogIn()\0http_request_ready_read()\0"
};

void LogInWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LogInWidget *_t = static_cast<LogInWidget *>(_o);
        switch (_id) {
        case 0: _t->login_success((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->LogIn(); break;
        case 2: _t->http_request_ready_read(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LogInWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LogInWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LogInWidget,
      qt_meta_data_LogInWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogInWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogInWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogInWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogInWidget))
        return static_cast<void*>(const_cast< LogInWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LogInWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LogInWidget::login_success(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
