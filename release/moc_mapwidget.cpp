/****************************************************************************
** Meta object code from reading C++ file 'mapwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MapWidget2/mapwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapWidget_t {
    QByteArrayData data[20];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapWidget_t qt_meta_stringdata_MapWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MapWidget"
QT_MOC_LITERAL(1, 10, 6), // "inside"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "DateTime"
QT_MOC_LITERAL(4, 27, 2), // "dT"
QT_MOC_LITERAL(5, 30, 7), // "outside"
QT_MOC_LITERAL(6, 38, 13), // "ESACalculated"
QT_MOC_LITERAL(7, 52, 15), // "vector<double>&"
QT_MOC_LITERAL(8, 68, 8), // "vESA_tmp"
QT_MOC_LITERAL(9, 77, 10), // "vAngle_tmp"
QT_MOC_LITERAL(10, 88, 11), // "setDateTime"
QT_MOC_LITERAL(11, 100, 2), // "dt"
QT_MOC_LITERAL(12, 103, 16), // "setSimpleElement"
QT_MOC_LITERAL(13, 120, 3), // "dsR"
QT_MOC_LITERAL(14, 124, 4), // "dcR0"
QT_MOC_LITERAL(15, 129, 4), // "dcR1"
QT_MOC_LITERAL(16, 134, 3), // "dcW"
QT_MOC_LITERAL(17, 138, 3), // "dpH"
QT_MOC_LITERAL(18, 142, 3), // "dpW"
QT_MOC_LITERAL(19, 146, 19) // "clearSimpleElements"

    },
    "MapWidget\0inside\0\0DateTime\0dT\0outside\0"
    "ESACalculated\0vector<double>&\0vESA_tmp\0"
    "vAngle_tmp\0setDateTime\0dt\0setSimpleElement\0"
    "dsR\0dcR0\0dcR1\0dcW\0dpH\0dpW\0clearSimpleElements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       6,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   65,    2, 0x0a /* Public */,
      12,    1,   68,    2, 0x0a /* Public */,
      12,    3,   71,    2, 0x0a /* Public */,
      12,    2,   78,    2, 0x0a /* Public */,
      19,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   14,   15,   16,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   17,   18,
    QMetaType::Void,

       0        // eod
};

void MapWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inside((*reinterpret_cast< DateTime(*)>(_a[1]))); break;
        case 1: _t->outside((*reinterpret_cast< DateTime(*)>(_a[1]))); break;
        case 2: _t->ESACalculated((*reinterpret_cast< vector<double>(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2]))); break;
        case 3: _t->setDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 4: _t->setSimpleElement((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setSimpleElement((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->setSimpleElement((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->clearSimpleElements(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MapWidget::*)(DateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapWidget::inside)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MapWidget::*)(DateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapWidget::outside)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MapWidget::*)(vector<double> & , vector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapWidget::ESACalculated)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MapWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLWidget::staticMetaObject>(),
    qt_meta_stringdata_MapWidget.data,
    qt_meta_data_MapWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapWidget.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int MapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MapWidget::inside(DateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapWidget::outside(DateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MapWidget::ESACalculated(vector<double> & _t1, vector<double> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
