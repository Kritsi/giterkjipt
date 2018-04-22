#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>

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
    void setUsername(string uname);
    void setTotalCages(string tcages);
    void setTotalCatCages(string tcages);
    void setTotalDogCages(string tcages);
    void setTotalFreeCages(string tcages);
    void setTotalFreeCatCages(string tcages);
    void setTotalFreeDogCages(string tcages);
    void showMainInfo();

private slots:

    void on_btnCheckIn_clicked();

    void on_btnCheckOut_clicked();

    void on_tester_clicked();

    void on_pushButton_clicked();

    void on_tableView_Animals_activated(const QModelIndex &index);

private:
    Ui::secWindow *ui;
    string username;
    string totalCages;
    string totalCatCages;
    string totalDogCages;
    string totalFreeCages;
    string totalFreeCatCages;
    string totalFreeDogCages;
};

#endif // SECWINDOW_H
