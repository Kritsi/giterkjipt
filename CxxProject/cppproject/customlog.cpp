#include "customlog.h"
#include "ui_customlog.h"

customlog::customlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customlog)
{
    ui->setupUi(this);
}

customlog::~customlog()
{
    delete ui;
}

void customlog::on_btnConfirm_clicked()
{
    msg = ui->leMsg->text();
    this->close();
}

QString customlog::getMessage(){
    return msg;
}
