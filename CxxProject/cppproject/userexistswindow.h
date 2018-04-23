#ifndef USEREXISTSWINDOW_H
#define USEREXISTSWINDOW_H

#include <QDialog>
#include "kunde.h"

namespace Ui {
class userExistsWindow;
}

class userExistsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit userExistsWindow(QWidget *parent = 0);
    ~userExistsWindow();
    void setTlfNr(int tlf);
    void setCusomerName();
    void setAnimalType(string type);
    bool checkAllInput(string iname, string iage);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::userExistsWindow *ui;
    int tlfnr;
    string animalType;
};

#endif // USEREXISTSWINDOW_H
