#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include <QDialog>

using namespace std;

namespace Ui {
class CheckOutWindow;
}

class CheckOutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutWindow(QWidget *parent = 0);
    ~CheckOutWindow();
    bool checkAllInput(string itlf, string iname);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CheckOutWindow *ui;
};

#endif // CHECKOUTWINDOW_H
