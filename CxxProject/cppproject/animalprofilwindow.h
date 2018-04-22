#ifndef ANIMALPROFILWINDOW_H
#define ANIMALPROFILWINDOW_H

#include <QDialog>
#include <iostream>

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

    void setAnimalInfo(string iname, string iage, string iowner, int tlf, string sex, string needs);
    void showAnimalInfo();
    void setAnimalPic(string animalType);
    void getLogEntries();

private slots:
    void on_btnLogFood_clicked();

    void on_btnLogClean_clicked();

    void on_btnLogCustom_clicked();

private:
    Ui::AnimalProfilWindow *ui;
    string name;
    string age;
    string owner;
    int tlfNr;
    string sex;
    string sNeeds;
    int animalID;
};

#endif // ANIMALPROFILWINDOW_H
