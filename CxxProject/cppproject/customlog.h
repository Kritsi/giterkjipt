#ifndef CUSTOMLOG_H
#define CUSTOMLOG_H

#include <QDialog>

namespace Ui {
class customlog;
}

class customlog : public QDialog
{
    Q_OBJECT

public:
    explicit customlog(QWidget *parent = 0);
    ~customlog();
    QString getMessage();

private slots:
    void on_btnConfirm_clicked();

private:
    Ui::customlog *ui;
    QString msg;
};

#endif // CUSTOMLOG_H
