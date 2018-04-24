/********************************************************************************
** Form generated from reading UI file 'checkoutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTWINDOW_H
#define UI_CHECKOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CheckOutWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *inputFindTlf;
    QLabel *label;
    QLineEdit *inputFindName;
    QLabel *label_2;
    QLabel *backgroundImg;
    QLabel *label_tlf_error;
    QLabel *label_name_error;

    void setupUi(QDialog *CheckOutWindow)
    {
        if (CheckOutWindow->objectName().isEmpty())
            CheckOutWindow->setObjectName(QStringLiteral("CheckOutWindow"));
        CheckOutWindow->resize(404, 287);
        CheckOutWindow->setStyleSheet(QLatin1String(".backgroundImg {\n"
"	opacity: 0.5;\n"
"}"));
        buttonBox = new QDialogButtonBox(CheckOutWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        inputFindTlf = new QLineEdit(CheckOutWindow);
        inputFindTlf->setObjectName(QStringLiteral("inputFindTlf"));
        inputFindTlf->setGeometry(QRect(160, 60, 113, 22));
        label = new QLabel(CheckOutWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 81, 16));
        inputFindName = new QLineEdit(CheckOutWindow);
        inputFindName->setObjectName(QStringLiteral("inputFindName"));
        inputFindName->setGeometry(QRect(160, 100, 113, 22));
        label_2 = new QLabel(CheckOutWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 101, 16));
        backgroundImg = new QLabel(CheckOutWindow);
        backgroundImg->setObjectName(QStringLiteral("backgroundImg"));
        backgroundImg->setGeometry(QRect(0, 0, 121, 41));
        backgroundImg->setStyleSheet(QLatin1String("QLabel::backgroundImg {\n"
"opacity: 0.5;\n"
"}"));
        label_tlf_error = new QLabel(CheckOutWindow);
        label_tlf_error->setObjectName(QStringLiteral("label_tlf_error"));
        label_tlf_error->setGeometry(QRect(280, 60, 121, 20));
        label_name_error = new QLabel(CheckOutWindow);
        label_name_error->setObjectName(QStringLiteral("label_name_error"));
        label_name_error->setGeometry(QRect(280, 100, 121, 20));

        retranslateUi(CheckOutWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), CheckOutWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CheckOutWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(CheckOutWindow);
    } // setupUi

    void retranslateUi(QDialog *CheckOutWindow)
    {
        CheckOutWindow->setWindowTitle(QApplication::translate("CheckOutWindow", "Check Out", nullptr));
        label->setText(QApplication::translate("CheckOutWindow", "Telephone:", nullptr));
        label_2->setText(QApplication::translate("CheckOutWindow", "Animal Name:", nullptr));
        backgroundImg->setText(QString());
        label_tlf_error->setText(QString());
        label_name_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckOutWindow: public Ui_CheckOutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTWINDOW_H
