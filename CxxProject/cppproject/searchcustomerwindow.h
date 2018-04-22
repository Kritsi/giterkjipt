#ifndef SEARCHCUSTOMERWINDOW_H
#define SEARCHCUSTOMERWINDOW_H

#include <QDialog>

using namespace std;

namespace Ui {
class searchCustomerWindow;
}

class searchCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchCustomerWindow(QWidget *parent = 0);
    ~searchCustomerWindow();
    void setAnimalType(string type);

private slots:
    void on_pushButton_clicked();

private:
    Ui::searchCustomerWindow *ui;
    string animalType;
};

#endif // SEARCHCUSTOMERWINDOW_H
