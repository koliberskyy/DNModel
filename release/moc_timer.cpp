/****************************************************************************
** Meta object code from reading C++ file 'timer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Timer/timer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Timer_t {
    QByteArrayData data[9];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Timer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Timer_t qt_meta_stringdata_Timer = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Timer"
QT_MOC_LITERAL(1, 6, 4), // "goMf"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 8), // "currDate"
QT_MOC_LITERAL(4, 21, 8), // "currTime"
QT_MOC_LITERAL(5, 30, 8), // "runTimer"
QT_MOC_LITERAL(6, 39, 1), // "t"
QT_MOC_LITERAL(7, 41, 3), // "run"
QT_MOC_LITERAL(8, 45, 9) // "stopTimer"

    },
    "Timer\0goMf\0\0currDate\0currTime\0runTimer\0"
    "t\0run\0stopTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Timer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       4,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   51,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QTime,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Timer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Timer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goMf(); break;
        case 1: _t->currDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->currTime((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 3: _t->runTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->run(); break;
        case 5: _t->stopTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Timer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::goMf)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Timer::*)(QDate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::currDate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Timer::*)(QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::currTime)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Timer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Timer.data,
    qt_meta_data_Timer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Timer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Timer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Timer::goMf()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Timer::currDate(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Timer::currTime(QTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
