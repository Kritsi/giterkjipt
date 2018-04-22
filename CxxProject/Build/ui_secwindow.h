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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QLabel *label_3;
    QLabel *label_totelCages;
    QLabel *label_freeCages;
    QLabel *label_6;
    QLabel *label_dog;
    QLabel *label_freeDogCages;
    QLabel *label_9;
    QLabel *label_Cat;
    QLabel *label_freeCatCages;
    QLabel *label_12;
    QLabel *label_username;
    QLabel *label_tlf;
    QLabel *label_adr;
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

        horizontalLayout->addWidget(btnCheckIn);

        btnCheckOut = new QPushButton(horizontalLayoutWidget);
        btnCheckOut->setObjectName(QStringLiteral("btnCheckOut"));

        horizontalLayout->addWidget(btnCheckOut);

        label_hotelname = new QLabel(tab);
        label_hotelname->setObjectName(QStringLiteral("label_hotelname"));
        label_hotelname->setGeometry(QRect(20, 40, 241, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 131, 16));
        label_totelCages = new QLabel(tab);
        label_totelCages->setObjectName(QStringLiteral("label_totelCages"));
        label_totelCages->setGeometry(QRect(20, 150, 55, 16));
        label_freeCages = new QLabel(tab);
        label_freeCages->setObjectName(QStringLiteral("label_freeCages"));
        label_freeCages->setGeometry(QRect(120, 150, 55, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 190, 141, 16));
        label_dog = new QLabel(tab);
        label_dog->setObjectName(QStringLiteral("label_dog"));
        label_dog->setGeometry(QRect(20, 220, 55, 16));
        label_freeDogCages = new QLabel(tab);
        label_freeDogCages->setObjectName(QStringLiteral("label_freeDogCages"));
        label_freeDogCages->setGeometry(QRect(120, 220, 55, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 260, 131, 16));
        label_Cat = new QLabel(tab);
        label_Cat->setObjectName(QStringLiteral("label_Cat"));
        label_Cat->setGeometry(QRect(20, 290, 55, 16));
        label_freeCatCages = new QLabel(tab);
        label_freeCatCages->setObjectName(QStringLiteral("label_freeCatCages"));
        label_freeCatCages->setGeometry(QRect(120, 290, 55, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(500, 40, 21, 16));
        label_username = new QLabel(tab);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setGeometry(QRect(520, 40, 151, 16));
        label_tlf = new QLabel(tab);
        label_tlf->setObjectName(QStringLiteral("label_tlf"));
        label_tlf->setGeometry(QRect(460, 380, 211, 16));
        label_adr = new QLabel(tab);
        label_adr->setObjectName(QStringLiteral("label_adr"));
        label_adr->setGeometry(QRect(460, 410, 221, 16));
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

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


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
        label_3->setText(QApplication::translate("secWindow", "Antall plasser ", nullptr));
        label_totelCages->setText(QApplication::translate("secWindow", "50", nullptr));
        label_freeCages->setText(QApplication::translate("secWindow", "22", nullptr));
        label_6->setText(QApplication::translate("secWindow", "Antall plasser hund", nullptr));
        label_dog->setText(QApplication::translate("secWindow", "25", nullptr));
        label_freeDogCages->setText(QApplication::translate("secWindow", "13", nullptr));
        label_9->setText(QApplication::translate("secWindow", "Antall plasser katt", nullptr));
        label_Cat->setText(QApplication::translate("secWindow", "25", nullptr));
        label_freeCatCages->setText(QApplication::translate("secWindow", "15", nullptr));
        label_12->setText(QApplication::translate("secWindow", "Hi!", nullptr));
        label_username->setText(QApplication::translate("secWindow", "Username", nullptr));
        label_tlf->setText(QApplication::translate("secWindow", "Tlf", nullptr));
        label_adr->setText(QApplication::translate("secWindow", "Adresse", nullptr));
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
