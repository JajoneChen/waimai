#include "findpassword.h"
#include "ui_findpassword.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

findpassword::findpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findpassword)
{
    ui->setupUi(this);
}

findpassword::~findpassword()
{
    delete ui;
}

void findpassword::on_pushButton_clicked()//验证
{
    QString count=ui->lineEdit->text();
    QString phonenum=ui->lineEdit_2->text();
    if(count=="")
        QMessageBox::warning(this,"Warning","Count can't be empty!");
    else if(phonenum=="")
        QMessageBox::warning(this,"Warning","Phone number can't be empty!");
}

void findpassword::on_pushButton_2_clicked()//返回
{
    this->close();
}
