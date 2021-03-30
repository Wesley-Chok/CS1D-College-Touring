/****************************************************************************
** Meta object code from reading C++ file 'adminpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "adminpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_adminpage_t {
    QByteArrayData data[14];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_adminpage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_adminpage_t qt_meta_stringdata_adminpage = {
    {
QT_MOC_LITERAL(0, 0, 9), // "adminpage"
QT_MOC_LITERAL(1, 10, 27), // "on_viewDistancesBtn_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 26), // "on_viewSouvenirBtn_clicked"
QT_MOC_LITERAL(4, 66, 36), // "on_addCampusThroughInputFile_..."
QT_MOC_LITERAL(5, 103, 38), // "on_addSouvenirThroughInputFil..."
QT_MOC_LITERAL(6, 142, 33), // "on_changeSouvPriceBackBtn_cli..."
QT_MOC_LITERAL(7, 176, 33), // "on_changeSouvenirPriceBtn_cli..."
QT_MOC_LITERAL(8, 210, 33), // "on_updateSouvenirPriceBtn_cli..."
QT_MOC_LITERAL(9, 244, 25), // "on_addSouvenirBtn_clicked"
QT_MOC_LITERAL(10, 270, 28), // "on_createSouvenirBtn_clicked"
QT_MOC_LITERAL(11, 299, 28), // "on_deleteSouvenirBtn_clicked"
QT_MOC_LITERAL(12, 328, 28), // "on_deletePageBackBtn_clicked"
QT_MOC_LITERAL(13, 357, 35) // "on_deleteSouvenirConfirmBtn_c..."

    },
    "adminpage\0on_viewDistancesBtn_clicked\0"
    "\0on_viewSouvenirBtn_clicked\0"
    "on_addCampusThroughInputFile_clicked\0"
    "on_addSouvenirThroughInputFile_clicked\0"
    "on_changeSouvPriceBackBtn_clicked\0"
    "on_changeSouvenirPriceBtn_clicked\0"
    "on_updateSouvenirPriceBtn_clicked\0"
    "on_addSouvenirBtn_clicked\0"
    "on_createSouvenirBtn_clicked\0"
    "on_deleteSouvenirBtn_clicked\0"
    "on_deletePageBackBtn_clicked\0"
    "on_deleteSouvenirConfirmBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminpage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void adminpage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<adminpage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_viewDistancesBtn_clicked(); break;
        case 1: _t->on_viewSouvenirBtn_clicked(); break;
        case 2: _t->on_addCampusThroughInputFile_clicked(); break;
        case 3: _t->on_addSouvenirThroughInputFile_clicked(); break;
        case 4: _t->on_changeSouvPriceBackBtn_clicked(); break;
        case 5: _t->on_changeSouvenirPriceBtn_clicked(); break;
        case 6: _t->on_updateSouvenirPriceBtn_clicked(); break;
        case 7: _t->on_addSouvenirBtn_clicked(); break;
        case 8: _t->on_createSouvenirBtn_clicked(); break;
        case 9: _t->on_deleteSouvenirBtn_clicked(); break;
        case 10: _t->on_deletePageBackBtn_clicked(); break;
        case 11: _t->on_deleteSouvenirConfirmBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject adminpage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_adminpage.data,
    qt_meta_data_adminpage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *adminpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminpage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_adminpage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int adminpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
