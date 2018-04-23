/********************************************************************************
** Form generated from reading UI file 'catordog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATORDOG_H
#define UI_CATORDOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CatOrDog
{
public:
    QPushButton *btnCat;
    QPushButton *btnDog;
    QLabel *label_error;

    void setupUi(QDialog *CatOrDog)
    {
        if (CatOrDog->objectName().isEmpty())
            CatOrDog->setObjectName(QStringLiteral("CatOrDog"));
        CatOrDog->resize(400, 200);
        btnCat = new QPushButton(CatOrDog);
        btnCat->setObjectName(QStringLiteral("btnCat"));
        btnCat->setGeometry(QRect(30, 80, 141, 28));
        btnDog = new QPushButton(CatOrDog);
        btnDog->setObjectName(QStringLiteral("btnDog"));
        btnDog->setGeometry(QRect(220, 80, 141, 28));
        label_error = new QLabel(CatOrDog);
        label_error->setObjectName(QStringLiteral("label_error"));
        label_error->setGeometry(QRect(30, 130, 331, 16));

        retranslateUi(CatOrDog);

        QMetaObject::connectSlotsByName(CatOrDog);
    } // setupUi

    void retranslateUi(QDialog *CatOrDog)
    {
        CatOrDog->setWindowTitle(QApplication::translate("CatOrDog", "Dialog", nullptr));
        btnCat->setText(QApplication::translate("CatOrDog", "Cat", nullptr));
        btnDog->setText(QApplication::translate("CatOrDog", "Dog", nullptr));
        label_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CatOrDog: public Ui_CatOrDog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATORDOG_H
