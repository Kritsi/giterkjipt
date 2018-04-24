/********************************************************************************
** Form generated from reading UI file 'secwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECWINDOW_H
#define UI_SECWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secWindow
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCheckIn;
    QPushButton *btnCheckOut;
    QLabel *label_hotelname;
    QLabel *label_12;
    QLabel *label_username;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_adr;
    QLabel *label_tlf;
    QLabel *label_img;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *label_totelCages;
    QLabel *label_7;
    QLabel *label_freeCages;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_dog;
    QLabel *label_11;
    QLabel *label_freeDogCages;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLabel *label_Cat;
    QLabel *label_14;
    QLabel *label_freeCatCages;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLineEdit *inputSearch;
    QTableView *tableView_Animals;
    QLabel *label;
    QPushButton *tester;
    QPushButton *pushButton;

    void setupUi(QDialog *secWindow)
    {
        if (secWindow->objectName().isEmpty())
            secWindow->setObjectName(QStringLiteral("secWindow"));
        secWindow->resize(716, 612);
        secWindow->setMinimumSize(QSize(0, 100));
        gridLayout = new QGridLayout(secWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(secWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 460, 441, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnCheckIn = new QPushButton(horizontalLayoutWidget);
        btnCheckIn->setObjectName(QStringLiteral("btnCheckIn"));
        btnCheckIn->setAutoFillBackground(false);
        btnCheckIn->setStyleSheet(QStringLiteral("background-color:#ffa0ca;"));

        horizontalLayout->addWidget(btnCheckIn);

        btnCheckOut = new QPushButton(horizontalLayoutWidget);
        btnCheckOut->setObjectName(QStringLiteral("btnCheckOut"));
        btnCheckOut->setStyleSheet(QStringLiteral("background-color:#a0d4ff;"));

        horizontalLayout->addWidget(btnCheckOut);

        label_hotelname = new QLabel(tab);
        label_hotelname->setObjectName(QStringLiteral("label_hotelname"));
        label_hotelname->setGeometry(QRect(30, 20, 241, 51));
        label_hotelname->setStyleSheet(QStringLiteral("font-size: 30px; "));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 80, 21, 16));
        label_username = new QLabel(tab);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setGeometry(QRect(50, 80, 151, 16));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(460, 80, 231, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_adr = new QLabel(formLayoutWidget);
        label_adr->setObjectName(QStringLiteral("label_adr"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_adr);

        label_tlf = new QLabel(formLayoutWidget);
        label_tlf->setObjectName(QStringLiteral("label_tlf"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_tlf);

        label_img = new QLabel(tab);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(420, 160, 221, 281));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 150, 231, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font-size: 14px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        label_totelCages = new QLabel(verticalLayoutWidget);
        label_totelCages->setObjectName(QStringLiteral("label_totelCages"));

        horizontalLayout_2->addWidget(label_totelCages);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        label_freeCages = new QLabel(verticalLayoutWidget);
        label_freeCages->setObjectName(QStringLiteral("label_freeCages"));

        horizontalLayout_2->addWidget(label_freeCages);


        verticalLayout->addLayout(horizontalLayout_2);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("font-size: 14px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(label_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        label_dog = new QLabel(verticalLayoutWidget);
        label_dog->setObjectName(QStringLiteral("label_dog"));

        horizontalLayout_3->addWidget(label_dog);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        label_freeDogCages = new QLabel(verticalLayoutWidget);
        label_freeDogCages->setObjectName(QStringLiteral("label_freeDogCages"));

        horizontalLayout_3->addWidget(label_freeDogCages);


        verticalLayout->addLayout(horizontalLayout_3);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("font-size: 14px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(label_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_4->addWidget(label_13);

        label_Cat = new QLabel(verticalLayoutWidget);
        label_Cat->setObjectName(QStringLiteral("label_Cat"));

        horizontalLayout_4->addWidget(label_Cat);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);

        label_freeCatCages = new QLabel(verticalLayoutWidget);
        label_freeCatCages->setObjectName(QStringLiteral("label_freeCatCages"));

        horizontalLayout_4->addWidget(label_freeCatCages);


        verticalLayout->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        inputSearch = new QLineEdit(tab_2);
        inputSearch->setObjectName(QStringLiteral("inputSearch"));

        gridLayout_2->addWidget(inputSearch, 1, 0, 1, 1);

        tableView_Animals = new QTableView(tab_2);
        tableView_Animals->setObjectName(QStringLiteral("tableView_Animals"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView_Animals->sizePolicy().hasHeightForWidth());
        tableView_Animals->setSizePolicy(sizePolicy);
        tableView_Animals->setAutoFillBackground(false);

        gridLayout_2->addWidget(tableView_Animals, 2, 0, 1, 2);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tester = new QPushButton(tab_2);
        tester->setObjectName(QStringLiteral("tester"));

        gridLayout_2->addWidget(tester, 3, 0, 1, 1);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(secWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(secWindow);
    } // setupUi

    void retranslateUi(QDialog *secWindow)
    {
        secWindow->setWindowTitle(QApplication::translate("secWindow", "KennelSoft", nullptr));
        btnCheckIn->setText(QApplication::translate("secWindow", "Check In", nullptr));
        btnCheckOut->setText(QApplication::translate("secWindow", "Check Out", nullptr));
        label_hotelname->setText(QApplication::translate("secWindow", "Hotell navn", nullptr));
        label_12->setText(QApplication::translate("secWindow", "Hi!", nullptr));
        label_username->setText(QApplication::translate("secWindow", "Username", nullptr));
        label_5->setText(QApplication::translate("secWindow", "Hotel info:", nullptr));
        label_2->setText(QApplication::translate("secWindow", "TlfNr:", nullptr));
        label_4->setText(QApplication::translate("secWindow", "Adresse:", nullptr));
        label_adr->setText(QApplication::translate("secWindow", "Adresse", nullptr));
        label_tlf->setText(QApplication::translate("secWindow", "Tlf", nullptr));
        label_img->setText(QString());
        label_3->setText(QApplication::translate("secWindow", "Antall plasser ", nullptr));
        label_8->setText(QApplication::translate("secWindow", "Total", nullptr));
        label_totelCages->setText(QApplication::translate("secWindow", "50", nullptr));
        label_7->setText(QApplication::translate("secWindow", "Ledig ", nullptr));
        label_freeCages->setText(QApplication::translate("secWindow", "22", nullptr));
        label_6->setText(QApplication::translate("secWindow", "Antall plasser hund", nullptr));
        label_10->setText(QApplication::translate("secWindow", "Total", nullptr));
        label_dog->setText(QApplication::translate("secWindow", "25", nullptr));
        label_11->setText(QApplication::translate("secWindow", "Ledig", nullptr));
        label_freeDogCages->setText(QApplication::translate("secWindow", "13", nullptr));
        label_9->setText(QApplication::translate("secWindow", "Antall plasser katt", nullptr));
        label_13->setText(QApplication::translate("secWindow", "Total", nullptr));
        label_Cat->setText(QApplication::translate("secWindow", "25", nullptr));
        label_14->setText(QApplication::translate("secWindow", "Ledig", nullptr));
        label_freeCatCages->setText(QApplication::translate("secWindow", "15", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("secWindow", "Dashboard", nullptr));
        label->setText(QApplication::translate("secWindow", "Search:", nullptr));
        tester->setText(QApplication::translate("secWindow", "Update", nullptr));
        pushButton->setText(QApplication::translate("secWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("secWindow", "Animal Overview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secWindow: public Ui_secWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECWINDOW_H
