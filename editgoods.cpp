#include "editgoods.h"
#include "ui_editgoods.h"

editgoods::editgoods(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editgoods)
{
    ui->setupUi(this);
}

editgoods::~editgoods()
{
    delete ui;
}

void editgoods::on_pushButton_clicked()//确认
{

}

void editgoods::on_pushButton_2_clicked()//返回
{
    this->close();
}
