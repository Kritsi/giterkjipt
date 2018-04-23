/********************************************************************************
** Form generated from reading UI file 'searchcustomerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHCUSTOMERWINDOW_H
#define UI_SEARCHCUSTOMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_searchCustomerWindow
{
public:
    QLineEdit *inputTlf;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *error_msg;

    void setupUi(QDialog *searchCustomerWindow)
    {
        if (searchCustomerWindow->objectName().isEmpty())
            searchCustomerWindow->setObjectName(QStringLiteral("searchCustomerWindow"));
        searchCustomerWindow->resize(400, 123);
        inputTlf = new QLineEdit(searchCustomerWindow);
        inputTlf->setObjectName(QStringLiteral("inputTlf"));
        inputTlf->setGeometry(QRect(120, 50, 113, 21));
        label = new QLabel(searchCustomerWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 91, 16));
        pushButton = new QPushButton(searchCustomerWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 50, 93, 28));
        error_msg = new QLabel(searchCustomerWindow);
        error_msg->setObjectName(QStringLiteral("error_msg"));
        error_msg->setGeometry(QRect(20, 100, 361, 16));

        retranslateUi(searchCustomerWindow);

        QMetaObject::connectSlotsByName(searchCustomerWindow);
    } // setupUi

    void retranslateUi(QDialog *searchCustomerWindow)
    {
        searchCustomerWindow->setWindowTitle(QApplication::translate("searchCustomerWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("searchCustomerWindow", "Telephone:", nullptr));
        pushButton->setText(QApplication::translate("searchCustomerWindow", "Search", nullptr));
        error_msg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class searchCustomerWindow: public Ui_searchCustomerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHCUSTOMERWINDOW_H
