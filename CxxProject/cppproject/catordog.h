#ifndef CATORDOG_H
#define CATORDOG_H

#include <QDialog>

namespace Ui {
class CatOrDog;
}

class CatOrDog : public QDialog
{
    Q_OBJECT

public:
    explicit CatOrDog(QWidget *parent = 0);
    ~CatOrDog();

private slots:
    void on_btnCat_clicked();

    void on_btnDog_clicked();

private:
    Ui::CatOrDog *ui;
};

#endif // CATORDOG_H
