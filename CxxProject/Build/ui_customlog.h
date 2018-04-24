/********************************************************************************
** Form generated from reading UI file 'customlog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMLOG_H
#define UI_CUSTOMLOG_H

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

class Ui_customlog
{
public:
    QPushButton *btnConfirm;
    QLineEdit *leMsg;
    QLabel *label;

    void setupUi(QDialog *customlog)
    {
        if (customlog->objectName().isEmpty())
            customlog->setObjectName(QStringLiteral("customlog"));
        customlog->resize(438, 119);
        btnConfirm = new QPushButton(customlog);
        btnConfirm->setObjectName(QStringLiteral("btnConfirm"));
        btnConfirm->setGeometry(QRect(320, 80, 93, 28));
        leMsg = new QLineEdit(customlog);
        leMsg->setObjectName(QStringLiteral("leMsg"));
        leMsg->setGeometry(QRect(30, 50, 381, 22));
        label = new QLabel(customlog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 221, 16));

        retranslateUi(customlog);

        QMetaObject::connectSlotsByName(customlog);
    } // setupUi

    void retranslateUi(QDialog *customlog)
    {
        customlog->setWindowTitle(QApplication::translate("customlog", "Dialog", nullptr));
        btnConfirm->setText(QApplication::translate("customlog", "Confirm", nullptr));
        label->setText(QApplication::translate("customlog", "Please insert log message: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customlog: public Ui_customlog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMLOG_H
