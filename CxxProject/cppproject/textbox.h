#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "kunde.h"

#include <QDialog>

namespace Ui {
class textBox;
}

class textBox : public QDialog
{
    Q_OBJECT

public:
    explicit textBox(QWidget *parent = 0);
    ~textBox();
    void setCustomer(Customer c);
    void setAnimalName(QString aname);

private slots:
    void on_pushButton_clicked();

private:
    Ui::textBox *ui;
    Customer customer;
    QString animalName;
};

#endif // TEXTBOX_H
