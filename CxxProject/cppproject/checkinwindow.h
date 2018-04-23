#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H

#include <QDialog>

using namespace std;

namespace Ui {
class CheckInWindow;
}

class CheckInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInWindow(QWidget *parent = 0);
    ~CheckInWindow();
    void setAnimalType(string type);
    bool checkAllInput(string ifirstname, string ilastname, string itlf, string iname, string iage);

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::CheckInWindow *ui;
    string animalType;
};

#endif // CHECKINWINDOW_H
