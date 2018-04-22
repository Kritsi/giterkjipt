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

private:
    Ui::AnimalProfilWindow *ui;
    string name;
    string age;
    string owner;
    string tlfNr;
    string sex;
    string sNeeds;
};

#endif // ANIMALPROFILWINDOW_H
