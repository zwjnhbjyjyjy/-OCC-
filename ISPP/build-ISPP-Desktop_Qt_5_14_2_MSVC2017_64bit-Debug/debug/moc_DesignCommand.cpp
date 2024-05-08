/****************************************************************************
** Meta object code from reading C++ file 'DesignCommand.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ISPP/DesignCommand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DesignCommand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DesignCommand_t {
    QByteArrayData data[6];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DesignCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DesignCommand_t qt_meta_stringdata_DesignCommand = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DesignCommand"
QT_MOC_LITERAL(1, 14, 13), // "setDesignInfo"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "info"
QT_MOC_LITERAL(4, 34, 20), // "onDeviceItemSelected"
QT_MOC_LITERAL(5, 55, 14) // "onDeviceCancel"

    },
    "DesignCommand\0setDesignInfo\0\0info\0"
    "onDeviceItemSelected\0onDeviceCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DesignCommand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DesignCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DesignCommand *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDesignInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onDeviceItemSelected(); break;
        case 2: _t->onDeviceCancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DesignCommand::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DesignCommand::setDesignInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DesignCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DesignCommand.data,
    qt_meta_data_DesignCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DesignCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesignCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DesignCommand.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DesignCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DesignCommand::setDesignInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_DispersionCommand_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DispersionCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DispersionCommand_t qt_meta_stringdata_DispersionCommand = {
    {
QT_MOC_LITERAL(0, 0, 17) // "DispersionCommand"

    },
    "DispersionCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DispersionCommand[] = {

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

void DispersionCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DispersionCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand::staticMetaObject>(),
    qt_meta_stringdata_DispersionCommand.data,
    qt_meta_data_DispersionCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DispersionCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DispersionCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DispersionCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand::qt_metacast(_clname);
}

int DispersionCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ExtremCommand_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExtremCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExtremCommand_t qt_meta_stringdata_ExtremCommand = {
    {
QT_MOC_LITERAL(0, 0, 13) // "ExtremCommand"

    },
    "ExtremCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtremCommand[] = {

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

void ExtremCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ExtremCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand::staticMetaObject>(),
    qt_meta_stringdata_ExtremCommand.data,
    qt_meta_data_ExtremCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ExtremCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtremCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtremCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand::qt_metacast(_clname);
}

int ExtremCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Project2CurveCommand_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Project2CurveCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Project2CurveCommand_t qt_meta_stringdata_Project2CurveCommand = {
    {
QT_MOC_LITERAL(0, 0, 20) // "Project2CurveCommand"

    },
    "Project2CurveCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Project2CurveCommand[] = {

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

void Project2CurveCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Project2CurveCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand::staticMetaObject>(),
    qt_meta_stringdata_Project2CurveCommand.data,
    qt_meta_data_Project2CurveCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Project2CurveCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Project2CurveCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Project2CurveCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand::qt_metacast(_clname);
}

int Project2CurveCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_NotationCommand_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotationCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotationCommand_t qt_meta_stringdata_NotationCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "NotationCommand"

    },
    "NotationCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotationCommand[] = {

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

void NotationCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject NotationCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand::staticMetaObject>(),
    qt_meta_stringdata_NotationCommand.data,
    qt_meta_data_NotationCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NotationCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotationCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotationCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand::qt_metacast(_clname);
}

int NotationCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
