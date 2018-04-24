/********************************************************************************
** Form generated from reading UI file 'animalprofilwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMALPROFILWINDOW_H
#define UI_ANIMALPROFILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimalProfilWindow
{
public:
    QLabel *labelImg;
    QLabel *label;
    QLabel *label_2;
    QTableView *tableView_log;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnLogFood;
    QPushButton *btnLogClean;
    QPushButton *btnLogCustom;
    QLabel *label_3;
    QLabel *label_specialNeeds;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_checkInDate;
    QLabel *label_age;
    QLabel *label_6;
    QLabel *label_sex;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLabel *label_owner;
    QLabel *labe_tlf;
    QLabel *label_9;

    void setupUi(QDialog *AnimalProfilWindow)
    {
        if (AnimalProfilWindow->objectName().isEmpty())
            AnimalProfilWindow->setObjectName(QStringLiteral("AnimalProfilWindow"));
        AnimalProfilWindow->resize(511, 686);
        labelImg = new QLabel(AnimalProfilWindow);
        labelImg->setObjectName(QStringLiteral("labelImg"));
        labelImg->setGeometry(QRect(10, 20, 211, 211));
        label = new QLabel(AnimalProfilWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 20, 55, 16));
        label->setStyleSheet(QStringLiteral("font-weight: bold;"));
        label_2 = new QLabel(AnimalProfilWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 170, 55, 16));
        label_2->setStyleSheet(QStringLiteral("font-weight: bold;"));
        tableView_log = new QTableView(AnimalProfilWindow);
        tableView_log->setObjectName(QStringLiteral("tableView_log"));
        tableView_log->setGeometry(QRect(10, 270, 491, 331));
        tableView_log->setAutoScrollMargin(0);
        tableView_log->setShowGrid(false);
        tableView_log->setCornerButtonEnabled(true);
        tableView_log->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_log->horizontalHeader()->setDefaultSectionSize(180);
        tableView_log->horizontalHeader()->setStretchLastSection(true);
        horizontalLayoutWidget = new QWidget(AnimalProfilWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 630, 421, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnLogFood = new QPushButton(horizontalLayoutWidget);
        btnLogFood->setObjectName(QStringLiteral("btnLogFood"));

        horizontalLayout->addWidget(btnLogFood);

        btnLogClean = new QPushButton(horizontalLayoutWidget);
        btnLogClean->setObjectName(QStringLiteral("btnLogClean"));

        horizontalLayout->addWidget(btnLogClean);

        btnLogCustom = new QPushButton(horizontalLayoutWidget);
        btnLogCustom->setObjectName(QStringLiteral("btnLogCustom"));

        horizontalLayout->addWidget(btnLogCustom);

        label_3 = new QLabel(AnimalProfilWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 608, 112, 21));
        label_specialNeeds = new QLabel(AnimalProfilWindow);
        label_specialNeeds->setObjectName(QStringLiteral("label_specialNeeds"));
        label_specialNeeds->setGeometry(QRect(60, 240, 421, 21));
        formLayoutWidget = new QWidget(AnimalProfilWindow);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(240, 40, 261, 117));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(formLayoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_name);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        label_checkInDate = new QLabel(formLayoutWidget);
        label_checkInDate->setObjectName(QStringLiteral("label_checkInDate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_checkInDate);

        label_age = new QLabel(formLayoutWidget);
        label_age->setObjectName(QStringLiteral("label_age"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_age);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        label_sex = new QLabel(formLayoutWidget);
        label_sex->setObjectName(QStringLiteral("label_sex"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_sex);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_11);

        formLayoutWidget_2 = new QWidget(AnimalProfilWindow);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(240, 190, 261, 51));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        label_owner = new QLabel(formLayoutWidget_2);
        label_owner->setObjectName(QStringLiteral("label_owner"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_owner);

        labe_tlf = new QLabel(formLayoutWidget_2);
        labe_tlf->setObjectName(QStringLiteral("labe_tlf"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, labe_tlf);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);


        retranslateUi(AnimalProfilWindow);

        QMetaObject::connectSlotsByName(AnimalProfilWindow);
    } // setupUi

    void retranslateUi(QDialog *AnimalProfilWindow)
    {
        AnimalProfilWindow->setWindowTitle(QApplication::translate("AnimalProfilWindow", "Dialog", nullptr));
        labelImg->setText(QString());
        label->setText(QApplication::translate("AnimalProfilWindow", "Animal:", nullptr));
        label_2->setText(QApplication::translate("AnimalProfilWindow", "Owner:", nullptr));
        btnLogFood->setText(QApplication::translate("AnimalProfilWindow", "Fed", nullptr));
        btnLogClean->setText(QApplication::translate("AnimalProfilWindow", "Cleaned cage", nullptr));
        btnLogCustom->setText(QApplication::translate("AnimalProfilWindow", "Custom", nullptr));
        label_3->setText(QApplication::translate("AnimalProfilWindow", "Logging functions: ", nullptr));
        label_specialNeeds->setText(QApplication::translate("AnimalProfilWindow", "sn", nullptr));
        label_name->setText(QApplication::translate("AnimalProfilWindow", "Navn", nullptr));
        label_5->setText(QApplication::translate("AnimalProfilWindow", "Name:", nullptr));
        label_4->setText(QApplication::translate("AnimalProfilWindow", "From:", nullptr));
        label_checkInDate->setText(QApplication::translate("AnimalProfilWindow", "Innsjekk", nullptr));
        label_age->setText(QApplication::translate("AnimalProfilWindow", "alder", nullptr));
        label_6->setText(QApplication::translate("AnimalProfilWindow", "Age:", nullptr));
        label_sex->setText(QApplication::translate("AnimalProfilWindow", "label_sex", nullptr));
        label_7->setText(QApplication::translate("AnimalProfilWindow", "Sex:", nullptr));
        label_10->setText(QApplication::translate("AnimalProfilWindow", "To:", nullptr));
        label_11->setText(QApplication::translate("AnimalProfilWindow", "-----", nullptr));
        label_8->setText(QApplication::translate("AnimalProfilWindow", "Name:", nullptr));
        label_owner->setText(QApplication::translate("AnimalProfilWindow", "Eier", nullptr));
        labe_tlf->setText(QApplication::translate("AnimalProfilWindow", "Tlf", nullptr));
        label_9->setText(QApplication::translate("AnimalProfilWindow", "TlfNr:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimalProfilWindow: public Ui_AnimalProfilWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALPROFILWINDOW_H
