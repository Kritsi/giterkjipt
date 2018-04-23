/********************************************************************************
** Form generated from reading UI file 'userexistswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEREXISTSWINDOW_H
#define UI_USEREXISTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_userExistsWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QCheckBox *checkBox;
    QLineEdit *inputAge;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QLabel *label_7;
    QLineEdit *inputName;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *nameCustomer;
    QLabel *label_name_error;
    QLabel *label_age_error;

    void setupUi(QDialog *userExistsWindow)
    {
        if (userExistsWindow->objectName().isEmpty())
            userExistsWindow->setObjectName(QStringLiteral("userExistsWindow"));
        userExistsWindow->resize(412, 393);
        buttonBox = new QDialogButtonBox(userExistsWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 310, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(userExistsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 70, 55, 16));
        checkBox = new QCheckBox(userExistsWindow);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(230, 250, 81, 20));
        inputAge = new QLineEdit(userExistsWindow);
        inputAge->setObjectName(QStringLiteral("inputAge"));
        inputAge->setGeometry(QRect(120, 140, 113, 22));
        label_9 = new QLabel(userExistsWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 210, 81, 16));
        groupBox_2 = new QGroupBox(userExistsWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(120, 200, 181, 31));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(0, 10, 95, 20));
        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(110, 10, 95, 20));
        label_7 = new QLabel(userExistsWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 140, 81, 16));
        inputName = new QLineEdit(userExistsWindow);
        inputName->setObjectName(QStringLiteral("inputName"));
        inputName->setGeometry(QRect(120, 110, 113, 22));
        label_8 = new QLabel(userExistsWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 110, 81, 16));
        label_10 = new QLabel(userExistsWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 210, 81, 16));
        label_11 = new QLabel(userExistsWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 250, 161, 16));
        nameCustomer = new QLabel(userExistsWindow);
        nameCustomer->setObjectName(QStringLiteral("nameCustomer"));
        nameCustomer->setGeometry(QRect(30, 20, 371, 16));
        label_name_error = new QLabel(userExistsWindow);
        label_name_error->setObjectName(QStringLiteral("label_name_error"));
        label_name_error->setGeometry(QRect(250, 110, 151, 16));
        label_age_error = new QLabel(userExistsWindow);
        label_age_error->setObjectName(QStringLiteral("label_age_error"));
        label_age_error->setGeometry(QRect(250, 140, 151, 16));

        retranslateUi(userExistsWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), userExistsWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), userExistsWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(userExistsWindow);
    } // setupUi

    void retranslateUi(QDialog *userExistsWindow)
    {
        userExistsWindow->setWindowTitle(QApplication::translate("userExistsWindow", "Dialog", nullptr));
        label_2->setText(QApplication::translate("userExistsWindow", "Animal:", nullptr));
        checkBox->setText(QString());
        label_9->setText(QApplication::translate("userExistsWindow", "Type:", nullptr));
        groupBox_2->setTitle(QString());
        radioButton_5->setText(QApplication::translate("userExistsWindow", "Male", nullptr));
        radioButton_6->setText(QApplication::translate("userExistsWindow", "Female", nullptr));
        label_7->setText(QApplication::translate("userExistsWindow", "Age", nullptr));
        label_8->setText(QApplication::translate("userExistsWindow", "Name:", nullptr));
        label_10->setText(QApplication::translate("userExistsWindow", "Type:", nullptr));
        label_11->setText(QApplication::translate("userExistsWindow", "Special needs/wishes:", nullptr));
        nameCustomer->setText(QString());
        label_name_error->setText(QString());
        label_age_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class userExistsWindow: public Ui_userExistsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEREXISTSWINDOW_H
