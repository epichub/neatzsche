/****************************************************************************
** Meta object code from reading C++ file 'paintwindow.h'
**
** Created: Thu Nov 22 11:15:03 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lightsim/paintwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_PaintWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_PaintWindow[] = {
    "PaintWindow\0"
};

const QMetaObject PaintWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintWindow,
      qt_meta_data_PaintWindow, 0 }
};

const QMetaObject *PaintWindow::metaObject() const
{
    return &staticMetaObject;
}

void *PaintWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PaintWindow))
	return static_cast<void*>(const_cast< PaintWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
