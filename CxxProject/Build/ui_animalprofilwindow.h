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
    QLabel *label_name;
    QLabel *label_age;
    QLabel *label_owner;
    QLabel *labe_tlf;
    QLabel *label;
    QLabel *label_2;
    QTableView *tableView_log;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnLogFood;
    QPushButton *btnLogClean;
    QPushButton *btnLogCustom;
    QLabel *label_3;
    QLabel *label_sex;
    QLabel *label_specialNeeds;
    QPushButton *btn_Img;

    void setupUi(QDialog *AnimalProfilWindow)
    {
        if (AnimalProfilWindow->objectName().isEmpty())
            AnimalProfilWindow->setObjectName(QStringLiteral("AnimalProfilWindow"));
        AnimalProfilWindow->resize(511, 666);
        labelImg = new QLabel(AnimalProfilWindow);
        labelImg->setObjectName(QStringLiteral("labelImg"));
        labelImg->setGeometry(QRect(30, 30, 181, 171));
        label_name = new QLabel(AnimalProfilWindow);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(240, 60, 211, 16));
        label_age = new QLabel(AnimalProfilWindow);
        label_age->setObjectName(QStringLiteral("label_age"));
        label_age->setGeometry(QRect(240, 80, 201, 16));
        label_owner = new QLabel(AnimalProfilWindow);
        label_owner->setObjectName(QStringLiteral("label_owner"));
        label_owner->setGeometry(QRect(240, 160, 211, 16));
        labe_tlf = new QLabel(AnimalProfilWindow);
        labe_tlf->setObjectName(QStringLiteral("labe_tlf"));
        labe_tlf->setGeometry(QRect(240, 180, 55, 16));
        label = new QLabel(AnimalProfilWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 30, 55, 16));
        label_2 = new QLabel(AnimalProfilWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 130, 55, 16));
        tableView_log = new QTableView(AnimalProfilWindow);
        tableView_log->setObjectName(QStringLiteral("tableView_log"));
        tableView_log->setGeometry(QRect(10, 240, 471, 351));
        tableView_log->setAutoScrollMargin(0);
        tableView_log->setShowGrid(false);
        tableView_log->setCornerButtonEnabled(true);
        tableView_log->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_log->horizontalHeader()->setDefaultSectionSize(180);
        tableView_log->horizontalHeader()->setStretchLastSection(true);
        horizontalLayoutWidget = new QWidget(AnimalProfilWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 610, 421, 51));
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
        label_3->setGeometry(QRect(10, 570, 112, 49));
        label_sex = new QLabel(AnimalProfilWindow);
        label_sex->setObjectName(QStringLiteral("label_sex"));
        label_sex->setGeometry(QRect(240, 100, 55, 16));
        label_specialNeeds = new QLabel(AnimalProfilWindow);
        label_specialNeeds->setObjectName(QStringLiteral("label_specialNeeds"));
        label_specialNeeds->setGeometry(QRect(60, 210, 401, 20));
        btn_Img = new QPushButton(AnimalProfilWindow);
        btn_Img->setObjectName(QStringLiteral("btn_Img"));
        btn_Img->setGeometry(QRect(10, 210, 31, 28));

        retranslateUi(AnimalProfilWindow);

        QMetaObject::connectSlotsByName(AnimalProfilWindow);
    } // setupUi

    void retranslateUi(QDialog *AnimalProfilWindow)
    {
        AnimalProfilWindow->setWindowTitle(QApplication::translate("AnimalProfilWindow", "Dialog", nullptr));
        labelImg->setText(QString());
        label_name->setText(QApplication::translate("AnimalProfilWindow", "Navn", nullptr));
        label_age->setText(QApplication::translate("AnimalProfilWindow", "alder", nullptr));
        label_owner->setText(QApplication::translate("AnimalProfilWindow", "Eier", nullptr));
        labe_tlf->setText(QApplication::translate("AnimalProfilWindow", "Tlf", nullptr));
        label->setText(QApplication::translate("AnimalProfilWindow", "Animal:", nullptr));
        label_2->setText(QApplication::translate("AnimalProfilWindow", "Owner:", nullptr));
        btnLogFood->setText(QApplication::translate("AnimalProfilWindow", "Fed", nullptr));
        btnLogClean->setText(QApplication::translate("AnimalProfilWindow", "Cleaned cage", nullptr));
        btnLogCustom->setText(QApplication::translate("AnimalProfilWindow", "Custom", nullptr));
        label_3->setText(QApplication::translate("AnimalProfilWindow", "Logging functions: ", nullptr));
        label_sex->setText(QApplication::translate("AnimalProfilWindow", "label_sex", nullptr));
        label_specialNeeds->setText(QApplication::translate("AnimalProfilWindow", "sn", nullptr));
        btn_Img->setText(QApplication::translate("AnimalProfilWindow", "Img", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimalProfilWindow: public Ui_AnimalProfilWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALPROFILWINDOW_H
