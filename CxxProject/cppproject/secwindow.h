#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>
#include "db.h"
using namespace std;

namespace Ui {
class secWindow;
}

class secWindow : public QDialog
{
    Q_OBJECT

public:
    explicit secWindow(QWidget *parent = 0);
    ~secWindow();
    void setBackground(QString path);
    void setUsername(QString uname);
    void setTotalCages(int tcages);
    void setTotalCatCages(int tcages);
    void setTotalDogCages(int tcages);
    void setTotalFreeCages(int tcages);
    void setTotalFreeCatCages(int tcages);
    void setTotalFreeDogCages(int tcages);
    void showMainInfo();

private slots:

    void on_btnCheckIn_clicked();

    void on_btnCheckOut_clicked();

    void on_tester_clicked();

    void on_pushButton_clicked();

    void on_tableView_Animals_activated(const QModelIndex &index);

private:
    Database db;
    Ui::secWindow *ui;
    QString username;
    int totalCages;
    int totalCatCages;
    int totalDogCages;
    int totalFreeCages;
    int totalFreeCatCages;
    int totalFreeDogCages;
};

#endif // SECWINDOW_H
