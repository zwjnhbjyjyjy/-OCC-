/****************************************************************************
** Meta object code from reading C++ file 'DrawCommand.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ISPP/DrawCommand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawCommand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawCommand_t {
    QByteArrayData data[10];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawCommand_t qt_meta_stringdata_DrawCommand = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DrawCommand"
QT_MOC_LITERAL(1, 12, 11), // "setDrawInfo"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "info"
QT_MOC_LITERAL(4, 30, 15), // "onDeviceClicked"
QT_MOC_LITERAL(5, 46, 2), // "px"
QT_MOC_LITERAL(6, 49, 2), // "py"
QT_MOC_LITERAL(7, 52, 13), // "onDeviceMoved"
QT_MOC_LITERAL(8, 66, 11), // "onDeviceEnd"
QT_MOC_LITERAL(9, 78, 14) // "onDeviceCancel"

    },
    "DrawCommand\0setDrawInfo\0\0info\0"
    "onDeviceClicked\0px\0py\0onDeviceMoved\0"
    "onDeviceEnd\0onDeviceCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   42,    2, 0x08 /* Private */,
       7,    2,   47,    2, 0x08 /* Private */,
       8,    2,   52,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,

       0        // eod
};

void DrawCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawCommand *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDrawInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onDeviceClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onDeviceMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->onDeviceEnd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onDeviceCancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DrawCommand::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawCommand::setDrawInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DrawCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DrawCommand.data,
    qt_meta_data_DrawCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawCommand.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DrawCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DrawCommand::setDrawInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_DrawPointCommand_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawPointCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawPointCommand_t qt_meta_stringdata_DrawPointCommand = {
    {
QT_MOC_LITERAL(0, 0, 16) // "DrawPointCommand"

    },
    "DrawPointCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawPointCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawPointCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawPointCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawPointCommand.data,
    qt_meta_data_DrawPointCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawPointCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawPointCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawPointCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawPointCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawLineCommand_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawLineCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawLineCommand_t qt_meta_stringdata_DrawLineCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "DrawLineCommand"

    },
    "DrawLineCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawLineCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawLineCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawLineCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawLineCommand.data,
    qt_meta_data_DrawLineCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawLineCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawLineCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawLineCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawLineCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawCircCommand_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawCircCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawCircCommand_t qt_meta_stringdata_DrawCircCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "DrawCircCommand"

    },
    "DrawCircCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawCircCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawCircCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawCircCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawCircCommand.data,
    qt_meta_data_DrawCircCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawCircCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawCircCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawCircCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawCircCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawElipsCommand_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawElipsCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawElipsCommand_t qt_meta_stringdata_DrawElipsCommand = {
    {
QT_MOC_LITERAL(0, 0, 16) // "DrawElipsCommand"

    },
    "DrawElipsCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawElipsCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawElipsCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawElipsCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawElipsCommand.data,
    qt_meta_data_DrawElipsCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawElipsCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawElipsCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawElipsCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawElipsCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawSplineCommand_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawSplineCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawSplineCommand_t qt_meta_stringdata_DrawSplineCommand = {
    {
QT_MOC_LITERAL(0, 0, 17) // "DrawSplineCommand"

    },
    "DrawSplineCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawSplineCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawSplineCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawSplineCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawSplineCommand.data,
    qt_meta_data_DrawSplineCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawSplineCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawSplineCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawSplineCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawSplineCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawBoxCommand_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawBoxCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawBoxCommand_t qt_meta_stringdata_DrawBoxCommand = {
    {
QT_MOC_LITERAL(0, 0, 14) // "DrawBoxCommand"

    },
    "DrawBoxCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawBoxCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawBoxCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawBoxCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawBoxCommand.data,
    qt_meta_data_DrawBoxCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawBoxCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawBoxCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawBoxCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawBoxCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawCylinderCommand_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawCylinderCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawCylinderCommand_t qt_meta_stringdata_DrawCylinderCommand = {
    {
QT_MOC_LITERAL(0, 0, 19) // "DrawCylinderCommand"

    },
    "DrawCylinderCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawCylinderCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawCylinderCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawCylinderCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawCylinderCommand.data,
    qt_meta_data_DrawCylinderCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawCylinderCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawCylinderCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawCylinderCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawCylinderCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawConeCommand_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawConeCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawConeCommand_t qt_meta_stringdata_DrawConeCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "DrawConeCommand"

    },
    "DrawConeCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawConeCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawConeCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawConeCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawConeCommand.data,
    qt_meta_data_DrawConeCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawConeCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawConeCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawConeCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawConeCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawSphereCommand_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawSphereCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawSphereCommand_t qt_meta_stringdata_DrawSphereCommand = {
    {
QT_MOC_LITERAL(0, 0, 17) // "DrawSphereCommand"

    },
    "DrawSphereCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawSphereCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawSphereCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawSphereCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawSphereCommand.data,
    qt_meta_data_DrawSphereCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawSphereCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawSphereCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawSphereCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawSphereCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawTorusCommand_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawTorusCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawTorusCommand_t qt_meta_stringdata_DrawTorusCommand = {
    {
QT_MOC_LITERAL(0, 0, 16) // "DrawTorusCommand"

    },
    "DrawTorusCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawTorusCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawTorusCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawTorusCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DrawCommand::staticMetaObject>(),
    qt_meta_stringdata_DrawTorusCommand.data,
    qt_meta_data_DrawTorusCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawTorusCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawTorusCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawTorusCommand.stringdata0))
        return static_cast<void*>(this);
    return DrawCommand::qt_metacast(_clname);
}

int DrawTorusCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawCommand::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
