/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QPushButton *pushButton_new;
    QPushButton *pushButton_exists;

    void setupUi(QDialog *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QStringLiteral("user"));
        user->resize(400, 200);
        pushButton_new = new QPushButton(user);
        pushButton_new->setObjectName(QStringLiteral("pushButton_new"));
        pushButton_new->setGeometry(QRect(60, 80, 121, 28));
        pushButton_exists = new QPushButton(user);
        pushButton_exists->setObjectName(QStringLiteral("pushButton_exists"));
        pushButton_exists->setGeometry(QRect(230, 80, 121, 28));

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QDialog *user)
    {
        user->setWindowTitle(QApplication::translate("user", "Dialog", nullptr));
        pushButton_new->setText(QApplication::translate("user", "New customer", nullptr));
        pushButton_exists->setText(QApplication::translate("user", "Existing customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
