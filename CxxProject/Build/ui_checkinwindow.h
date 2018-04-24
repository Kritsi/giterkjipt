/********************************************************************************
** Form generated from reading UI file 'checkinwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINWINDOW_H
#define UI_CHECKINWINDOW_H

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

class Ui_CheckInWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *inputFirstname;
    QLineEdit *inputLastname;
    QLineEdit *inputTlf;
    QLineEdit *inputName;
    QLineEdit *inputAge;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *checkBox;
    QLabel *label_10;
    QDialogButtonBox *buttonBox_2;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QLabel *label_fn_error;
    QLabel *label_ln_error;
    QLabel *label_tlf_error;
    QLabel *label_name_error;
    QLabel *label_age_error;

    void setupUi(QDialog *CheckInWindow)
    {
        if (CheckInWindow->objectName().isEmpty())
            CheckInWindow->setObjectName(QStringLiteral("CheckInWindow"));
        CheckInWindow->resize(442, 473);
        buttonBox = new QDialogButtonBox(CheckInWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 430, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        inputFirstname = new QLineEdit(CheckInWindow);
        inputFirstname->setObjectName(QStringLiteral("inputFirstname"));
        inputFirstname->setGeometry(QRect(120, 40, 113, 22));
        inputLastname = new QLineEdit(CheckInWindow);
        inputLastname->setObjectName(QStringLiteral("inputLastname"));
        inputLastname->setGeometry(QRect(120, 90, 113, 22));
        inputTlf = new QLineEdit(CheckInWindow);
        inputTlf->setObjectName(QStringLiteral("inputTlf"));
        inputTlf->setGeometry(QRect(120, 140, 113, 22));
        inputName = new QLineEdit(CheckInWindow);
        inputName->setObjectName(QStringLiteral("inputName"));
        inputName->setGeometry(QRect(120, 240, 113, 22));
        inputAge = new QLineEdit(CheckInWindow);
        inputAge->setObjectName(QStringLiteral("inputAge"));
        inputAge->setGeometry(QRect(120, 270, 113, 22));
        label = new QLabel(CheckInWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 210, 55, 16));
        label_3 = new QLabel(CheckInWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 40, 81, 16));
        label_4 = new QLabel(CheckInWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 90, 81, 16));
        label_5 = new QLabel(CheckInWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 150, 81, 16));
        label_7 = new QLabel(CheckInWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 270, 81, 16));
        label_8 = new QLabel(CheckInWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 240, 81, 16));
        label_9 = new QLabel(CheckInWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 330, 81, 16));
        checkBox = new QCheckBox(CheckInWindow);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(230, 370, 81, 20));
        label_10 = new QLabel(CheckInWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 330, 81, 16));
        buttonBox_2 = new QDialogButtonBox(CheckInWindow);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(80, 430, 341, 32));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_11 = new QLabel(CheckInWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 370, 161, 16));
        groupBox_2 = new QGroupBox(CheckInWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(120, 320, 181, 31));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(0, 10, 95, 20));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(110, 10, 95, 20));
        label_fn_error = new QLabel(CheckInWindow);
        label_fn_error->setObjectName(QStringLiteral("label_fn_error"));
        label_fn_error->setGeometry(QRect(260, 40, 151, 16));
        label_ln_error = new QLabel(CheckInWindow);
        label_ln_error->setObjectName(QStringLiteral("label_ln_error"));
        label_ln_error->setGeometry(QRect(260, 90, 161, 20));
        label_tlf_error = new QLabel(CheckInWindow);
        label_tlf_error->setObjectName(QStringLiteral("label_tlf_error"));
        label_tlf_error->setGeometry(QRect(260, 140, 161, 16));
        label_name_error = new QLabel(CheckInWindow);
        label_name_error->setObjectName(QStringLiteral("label_name_error"));
        label_name_error->setGeometry(QRect(250, 240, 161, 16));
        label_age_error = new QLabel(CheckInWindow);
        label_age_error->setObjectName(QStringLiteral("label_age_error"));
        label_age_error->setGeometry(QRect(250, 270, 151, 16));

        retranslateUi(CheckInWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), CheckInWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CheckInWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(CheckInWindow);
    } // setupUi

    void retranslateUi(QDialog *CheckInWindow)
    {
        CheckInWindow->setWindowTitle(QApplication::translate("CheckInWindow", "Check In Animal", nullptr));
        label->setText(QApplication::translate("CheckInWindow", "Animal:", nullptr));
        label_3->setText(QApplication::translate("CheckInWindow", "First Name:", nullptr));
        label_4->setText(QApplication::translate("CheckInWindow", "Last Name:", nullptr));
        label_5->setText(QApplication::translate("CheckInWindow", "Telephone:", nullptr));
        label_7->setText(QApplication::translate("CheckInWindow", "Age", nullptr));
        label_8->setText(QApplication::translate("CheckInWindow", "Name:", nullptr));
        label_9->setText(QApplication::translate("CheckInWindow", "Type:", nullptr));
        checkBox->setText(QString());
        label_10->setText(QApplication::translate("CheckInWindow", "Type:", nullptr));
        label_11->setText(QApplication::translate("CheckInWindow", "Special needs/wishes:", nullptr));
        groupBox_2->setTitle(QString());
        radioButton_4->setText(QApplication::translate("CheckInWindow", "Male", nullptr));
        radioButton_3->setText(QApplication::translate("CheckInWindow", "Female", nullptr));
        label_fn_error->setText(QString());
        label_ln_error->setText(QString());
        label_tlf_error->setText(QString());
        label_name_error->setText(QString());
        label_age_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckInWindow: public Ui_CheckInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINWINDOW_H
