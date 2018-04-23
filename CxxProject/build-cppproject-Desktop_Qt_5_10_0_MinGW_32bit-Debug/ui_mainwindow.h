/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *databasecon;
    QLabel *lblconnection;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *username;
    QLineEdit *leUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password;
    QLineEdit *lePassword;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *Login;
    QLabel *lblTitle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(260, 297);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        databasecon = new QLabel(centralWidget);
        databasecon->setObjectName(QStringLiteral("databasecon"));
        databasecon->setGeometry(QRect(10, 180, 126, 16));
        lblconnection = new QLabel(centralWidget);
        lblconnection->setObjectName(QStringLiteral("lblconnection"));
        lblconnection->setGeometry(QRect(142, 180, 121, 16));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 224, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        username = new QLabel(verticalLayoutWidget);
        username->setObjectName(QStringLiteral("username"));

        horizontalLayout->addWidget(username);

        leUsername = new QLineEdit(verticalLayoutWidget);
        leUsername->setObjectName(QStringLiteral("leUsername"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leUsername->sizePolicy().hasHeightForWidth());
        leUsername->setSizePolicy(sizePolicy);
        leUsername->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(leUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        password = new QLabel(verticalLayoutWidget);
        password->setObjectName(QStringLiteral("password"));

        horizontalLayout_2->addWidget(password);

        lePassword = new QLineEdit(verticalLayoutWidget);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(47);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lePassword->sizePolicy().hasHeightForWidth());
        lePassword->setSizePolicy(sizePolicy1);
        lePassword->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(lePassword);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Login = new QPushButton(verticalLayoutWidget);
        Login->setObjectName(QStringLiteral("Login"));

        horizontalLayout_3->addWidget(Login);


        verticalLayout->addLayout(horizontalLayout_3);

        lblTitle = new QLabel(centralWidget);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(10, 10, 231, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 260, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        databasecon->setText(QApplication::translate("MainWindow", "Database connection: ", nullptr));
        lblconnection->setText(QApplication::translate("MainWindow", "Not checked", nullptr));
        username->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        password->setText(QApplication::translate("MainWindow", "Password:", nullptr));
        Login->setText(QApplication::translate("MainWindow", "Login", nullptr));
        lblTitle->setText(QApplication::translate("MainWindow", "Please log in:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
