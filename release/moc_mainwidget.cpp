/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ConstructorWidget/mainwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWidget_t {
    QByteArrayData data[19];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWidget_t qt_meta_stringdata_MainWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWidget"
QT_MOC_LITERAL(1, 11, 13), // "sphereCreated"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "radius_tmp"
QT_MOC_LITERAL(4, 37, 15), // "cylinderCreated"
QT_MOC_LITERAL(5, 53, 11), // "radius0_tmp"
QT_MOC_LITERAL(6, 65, 11), // "radius1_tmp"
QT_MOC_LITERAL(7, 77, 9), // "width_tmp"
QT_MOC_LITERAL(8, 87, 12), // "plastCreated"
QT_MOC_LITERAL(9, 100, 10), // "height_tmp"
QT_MOC_LITERAL(10, 111, 16), // "buttonAddPressed"
QT_MOC_LITERAL(11, 128, 19), // "buttonCreatePressed"
QT_MOC_LITERAL(12, 148, 14), // "sliderXChanged"
QT_MOC_LITERAL(13, 163, 2), // "mf"
QT_MOC_LITERAL(14, 166, 14), // "sliderYChanged"
QT_MOC_LITERAL(15, 181, 14), // "sliderZChanged"
QT_MOC_LITERAL(16, 196, 18), // "sliderScaleChanged"
QT_MOC_LITERAL(17, 215, 12), // "comboChanged"
QT_MOC_LITERAL(18, 228, 19) // "deleteButtonPressed"

    },
    "MainWidget\0sphereCreated\0\0radius_tmp\0"
    "cylinderCreated\0radius0_tmp\0radius1_tmp\0"
    "width_tmp\0plastCreated\0height_tmp\0"
    "buttonAddPressed\0buttonCreatePressed\0"
    "sliderXChanged\0mf\0sliderYChanged\0"
    "sliderZChanged\0sliderScaleChanged\0"
    "comboChanged\0deleteButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    3,   72,    2, 0x06 /* Public */,
       8,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,
      15,    1,   92,    2, 0x0a /* Public */,
      16,    1,   95,    2, 0x0a /* Public */,
      17,    1,   98,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    9,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sphereCreated((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->cylinderCreated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->plastCreated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->buttonAddPressed(); break;
        case 4: _t->buttonCreatePressed(); break;
        case 5: _t->sliderXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sliderYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sliderZChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sliderScaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->comboChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->deleteButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWidget::sphereCreated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWidget::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWidget::cylinderCreated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWidget::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWidget::plastCreated)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLWidget::staticMetaObject>(),
    qt_meta_stringdata_MainWidget.data,
    qt_meta_data_MainWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWidget::sphereCreated(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWidget::cylinderCreated(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWidget::plastCreated(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
