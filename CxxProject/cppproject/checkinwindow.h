#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H

#include <QDialog>
#include "db.h"

namespace Ui {
class CheckInWindow;
}

class CheckInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInWindow(QWidget *parent = 0);
    ~CheckInWindow();
    void setAnimalType(QString type);
    bool checkAllInput(QString ifirstname, QString ilastname, QString itlf, QString iname, QString iage);

private slots:
    void on_buttonBox_2_accepted();
    void on_buttonBox_2_rejected();

private: 
    Database db;
    Ui::CheckInWindow *ui;
    QString animalType;
};

#endif // CHECKINWINDOW_H
