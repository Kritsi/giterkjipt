#ifndef USER_H
#define USER_H

#include <QDialog>

using namespace std;

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = 0);
    ~user();
    void setAnimalType(QString type);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_new_clicked();

    void on_pushButton_exists_clicked();

private:
    Ui::user *ui;
    QString animalType = "";
};

#endif // USER_H
