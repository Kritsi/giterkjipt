#ifndef ANIMALPROFILWINDOW_H
#define ANIMALPROFILWINDOW_H

#include <QDialog>
#include <iostream>
#include "db.h"

using namespace std;

namespace Ui {
class AnimalProfilWindow;
}

class AnimalProfilWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalProfilWindow(QWidget *parent = 0);
    ~AnimalProfilWindow();

    void setAnimalInfo(QString iname, int tlf);
    void showAnimalInfo();
    void setDefaultPic(QString animalType);
    void setPic(QString path);
    void getLogEntries();

private slots:
    void on_btnLogFood_clicked();
    void on_btnLogClean_clicked();
    void on_btnLogCustom_clicked();
    void on_btn_Img_clicked();

private:
    Database db;
    Ui::AnimalProfilWindow *ui;
    QString name;
    QString owner;
    QString animalType;
    QString sex;
    QString sNeeds;
    QString animalPic;
    int age;
    int tlfNr;
    int animalID;
    string checkInDate;
};

#endif // ANIMALPROFILWINDOW_H
