#include "delgoods.h"
#include "ui_delgoods.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

delgoods::delgoods(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delgoods)
{
    ui->setupUi(this);
}

delgoods::~delgoods()
{
    delete ui;
}

void delgoods::on_pushButton_2_clicked()
{
    this->close();
}

void delgoods::on_pushButton_clicked()//确认按钮
{
    QString name=ui->lineEdit->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(db.open()==false)
        QMessageBox::warning(this,"warning",db.lastError().text());
    QSqlQuery sqlq(db);
    QString ins =QString("delete from goods where name='%1';").arg(name);
    if(!sqlq.exec(ins))
    {
        QMessageBox::warning(this,"warning","Delete failed."+sqlq.lastError().text());
    }
    else
        QMessageBox::information(this,"information","Delete successfully!");
    ui->lineEdit->clear();
}
