/****************************************************************************
** Meta object code from reading C++ file 'DesignCommand3D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ISPP/DesignCommand3D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DesignCommand3D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DesignCommand3D_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DesignCommand3D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DesignCommand3D_t qt_meta_stringdata_DesignCommand3D = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DesignCommand3D"
QT_MOC_LITERAL(1, 16, 13), // "setDesignInfo"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "info"
QT_MOC_LITERAL(4, 36, 20) // "onDeviceItemSelected"

    },
    "DesignCommand3D\0setDesignInfo\0\0info\0"
    "onDeviceItemSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DesignCommand3D[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DesignCommand3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DesignCommand3D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDesignInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onDeviceItemSelected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DesignCommand3D::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DesignCommand3D::setDesignInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DesignCommand3D::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DesignCommand3D.data,
    qt_meta_data_DesignCommand3D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DesignCommand3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesignCommand3D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DesignCommand3D.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DesignCommand3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DesignCommand3D::setDesignInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_BoolDesignCommand_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoolDesignCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoolDesignCommand_t qt_meta_stringdata_BoolDesignCommand = {
    {
QT_MOC_LITERAL(0, 0, 17) // "BoolDesignCommand"

    },
    "BoolDesignCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoolDesignCommand[] = {

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

void BoolDesignCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BoolDesignCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_BoolDesignCommand.data,
    qt_meta_data_BoolDesignCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BoolDesignCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoolDesignCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BoolDesignCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int BoolDesignCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Project2FaceCommand_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Project2FaceCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Project2FaceCommand_t qt_meta_stringdata_Project2FaceCommand = {
    {
QT_MOC_LITERAL(0, 0, 19) // "Project2FaceCommand"

    },
    "Project2FaceCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Project2FaceCommand[] = {

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

void Project2FaceCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Project2FaceCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_Project2FaceCommand.data,
    qt_meta_data_Project2FaceCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Project2FaceCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Project2FaceCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Project2FaceCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int Project2FaceCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_TransformCommand_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransformCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransformCommand_t qt_meta_stringdata_TransformCommand = {
    {
QT_MOC_LITERAL(0, 0, 16) // "TransformCommand"

    },
    "TransformCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransformCommand[] = {

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

void TransformCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TransformCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_TransformCommand.data,
    qt_meta_data_TransformCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TransformCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransformCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TransformCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int TransformCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ChamferCommand_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChamferCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChamferCommand_t qt_meta_stringdata_ChamferCommand = {
    {
QT_MOC_LITERAL(0, 0, 14) // "ChamferCommand"

    },
    "ChamferCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChamferCommand[] = {

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

void ChamferCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ChamferCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_ChamferCommand.data,
    qt_meta_data_ChamferCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChamferCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChamferCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChamferCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int ChamferCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_FilletCommand_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilletCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilletCommand_t qt_meta_stringdata_FilletCommand = {
    {
QT_MOC_LITERAL(0, 0, 13) // "FilletCommand"

    },
    "FilletCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilletCommand[] = {

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

void FilletCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FilletCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_FilletCommand.data,
    qt_meta_data_FilletCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilletCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilletCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilletCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int FilletCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_TranslateCommand_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TranslateCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TranslateCommand_t qt_meta_stringdata_TranslateCommand = {
    {
QT_MOC_LITERAL(0, 0, 16) // "TranslateCommand"

    },
    "TranslateCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TranslateCommand[] = {

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

void TranslateCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TranslateCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_TranslateCommand.data,
    qt_meta_data_TranslateCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TranslateCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TranslateCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TranslateCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int TranslateCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RotateCommand_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RotateCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RotateCommand_t qt_meta_stringdata_RotateCommand = {
    {
QT_MOC_LITERAL(0, 0, 13) // "RotateCommand"

    },
    "RotateCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RotateCommand[] = {

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

void RotateCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RotateCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_RotateCommand.data,
    qt_meta_data_RotateCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RotateCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RotateCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RotateCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int RotateCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ScaleCommand_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScaleCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScaleCommand_t qt_meta_stringdata_ScaleCommand = {
    {
QT_MOC_LITERAL(0, 0, 12) // "ScaleCommand"

    },
    "ScaleCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScaleCommand[] = {

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

void ScaleCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ScaleCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_ScaleCommand.data,
    qt_meta_data_ScaleCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScaleCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScaleCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScaleCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int ScaleCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MirrorCommand_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MirrorCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MirrorCommand_t qt_meta_stringdata_MirrorCommand = {
    {
QT_MOC_LITERAL(0, 0, 13) // "MirrorCommand"

    },
    "MirrorCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MirrorCommand[] = {

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

void MirrorCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MirrorCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_MirrorCommand.data,
    qt_meta_data_MirrorCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MirrorCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MirrorCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MirrorCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int MirrorCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_OffsetCommand_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OffsetCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OffsetCommand_t qt_meta_stringdata_OffsetCommand = {
    {
QT_MOC_LITERAL(0, 0, 13) // "OffsetCommand"

    },
    "OffsetCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OffsetCommand[] = {

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

void OffsetCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OffsetCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<DesignCommand3D::staticMetaObject>(),
    qt_meta_stringdata_OffsetCommand.data,
    qt_meta_data_OffsetCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OffsetCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OffsetCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OffsetCommand.stringdata0))
        return static_cast<void*>(this);
    return DesignCommand3D::qt_metacast(_clname);
}

int OffsetCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DesignCommand3D::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
