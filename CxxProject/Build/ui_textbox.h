/********************************************************************************
** Form generated from reading UI file 'textbox.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTBOX_H
#define UI_TEXTBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_textBox
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *textBox)
    {
        if (textBox->objectName().isEmpty())
            textBox->setObjectName(QStringLiteral("textBox"));
        textBox->resize(400, 300);
        pushButton = new QPushButton(textBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 240, 93, 28));
        textEdit = new QTextEdit(textBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 351, 201));

        retranslateUi(textBox);

        QMetaObject::connectSlotsByName(textBox);
    } // setupUi

    void retranslateUi(QDialog *textBox)
    {
        textBox->setWindowTitle(QApplication::translate("textBox", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("textBox", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textBox: public Ui_textBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTBOX_H
