#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Login_clicked();

private:
    Ui::MainWindow *ui;
    bool loginUser (QString username, string password);
    bool checkPassword(string dbPass, string inputPass);

};

#endif // MAINWINDOW_H
