/****************************************************************************
** Meta object code from reading C++ file 'MaFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projetPOO/MaFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MaFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaFenetre_t {
    QByteArrayData data[16];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaFenetre_t qt_meta_stringdata_MaFenetre = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MaFenetre"
QT_MOC_LITERAL(1, 10, 13), // "ouvrirDossier"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "suivant"
QT_MOC_LITERAL(4, 33, 9), // "precedent"
QT_MOC_LITERAL(5, 43, 9), // "rotationD"
QT_MOC_LITERAL(6, 53, 9), // "rotationG"
QT_MOC_LITERAL(7, 63, 9), // "diaporama"
QT_MOC_LITERAL(8, 73, 14), // "redimensionner"
QT_MOC_LITERAL(9, 88, 8), // "agrandir"
QT_MOC_LITERAL(10, 97, 7), // "reduire"
QT_MOC_LITERAL(11, 105, 9), // "supprimer"
QT_MOC_LITERAL(12, 115, 12), // "fichierImage"
QT_MOC_LITERAL(13, 128, 8), // "deplacer"
QT_MOC_LITERAL(14, 137, 8), // "renommer"
QT_MOC_LITERAL(15, 146, 9) // "stopdiapo"

    },
    "MaFenetre\0ouvrirDossier\0\0suivant\0"
    "precedent\0rotationD\0rotationG\0diaporama\0"
    "redimensionner\0agrandir\0reduire\0"
    "supprimer\0fichierImage\0deplacer\0"
    "renommer\0stopdiapo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaFenetre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MaFenetre *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ouvrirDossier(); break;
        case 1: _t->suivant(); break;
        case 2: _t->precedent(); break;
        case 3: _t->rotationD(); break;
        case 4: _t->rotationG(); break;
        case 5: _t->diaporama(); break;
        case 6: _t->redimensionner(); break;
        case 7: _t->agrandir(); break;
        case 8: _t->reduire(); break;
        case 9: _t->supprimer(); break;
        case 10: _t->fichierImage(); break;
        case 11: _t->deplacer(); break;
        case 12: _t->renommer(); break;
        case 13: _t->stopdiapo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MaFenetre::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MaFenetre.data,
    qt_meta_data_MaFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MaFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaFenetre.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MaFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
