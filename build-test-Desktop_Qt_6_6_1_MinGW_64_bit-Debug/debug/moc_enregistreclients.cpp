/****************************************************************************
** Meta object code from reading C++ file 'enregistreclients.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test/enregistreclients.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enregistreclients.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS = QtMocHelpers::stringData(
    "Ui::enregistreclient",
    "on_BTNValider_clicked",
    "",
    "on_BTNNouveau_clicked",
    "on_enregistrelivres_windowTitleChanged",
    "title"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[21];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[39];
    char stringdata5[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS_t qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "Ui::enregistreclient"
        QT_MOC_LITERAL(21, 21),  // "on_BTNValider_clicked"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 21),  // "on_BTNNouveau_clicked"
        QT_MOC_LITERAL(66, 38),  // "on_enregistrelivres_windowTit..."
        QT_MOC_LITERAL(105, 5)   // "title"
    },
    "Ui::enregistreclient",
    "on_BTNValider_clicked",
    "",
    "on_BTNNouveau_clicked",
    "on_enregistrelivres_windowTitleChanged",
    "title"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUiSCOPEenregistreclientENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    1,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject Ui::enregistreclient::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUiSCOPEenregistreclientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<enregistreclient, std::true_type>,
        // method 'on_BTNValider_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BTNNouveau_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enregistrelivres_windowTitleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Ui::enregistreclient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<enregistreclient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_BTNValider_clicked(); break;
        case 1: _t->on_BTNNouveau_clicked(); break;
        case 2: _t->on_enregistrelivres_windowTitleChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Ui::enregistreclient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ui::enregistreclient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUiSCOPEenregistreclientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Ui::enregistreclient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
