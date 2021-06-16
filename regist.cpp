#include "regist.h"
#include "ui_regist.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <regex>
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()//注册按钮
{
    QString count=ui->lineEdit->text();//账号
    QString password=ui->lineEdit_2->text();//密码
    QString comfirm_password=ui->lineEdit_3->text();//确认密码
    QString phonenum=ui->lineEdit_4->text();//手机号
    bool countflag=true;//判断用户名 不能大于10位
    bool passwordflag=true;//判断密码 8-16位
    bool phonenumflag=true;//判断手机号 11位
    int kind;
    if(ui->boss->isChecked())
        kind=1;
    if(ui->ridder->isChecked())
        kind=2;
    if(ui->customer->isChecked())
        kind=3;
    regex pn("^[1][3-5,7-9]\\d{9}$");
    string pnum=phonenum.toStdString();
    smatch m;
    if(count=="")
        QMessageBox::warning(this,"Warning","Count can't be empty!");
    else if(password=="")
        QMessageBox::warning(this,"Warning","Password can't be empty!");
    else if(comfirm_password=="")
        QMessageBox::warning(this,"Warning","Please comfirm your password!");
    else if(phonenum=="")
        QMessageBox::warning(this,"Warning","Phone number can't be empty!");
    else if(!(ui->boss->isChecked()||ui->ridder->isChecked()||ui->customer->isChecked()))
        QMessageBox::warning(this,"Warning","Please select the category you want to register.");
    else
    {
        if(count.length()>10)
            countflag=false;
        if(password.length()<8&&password.length()>16)
            passwordflag=false;
        if(phonenum.length()!=11||!regex_match(pnum,m,pn))
            phonenumflag=false;
        for(int i=0;i<count.length();i++)
        {
            if(!((count[i]>='a'&&count[i]<='z')||(count[i]>='0'&&count[i]<='9')||(count[i]>='A'&&count[i]<='Z')))
            {
                countflag=false;
                break;
            }
        }
        for(int i=0;i<password.length();i++)
        {
            if(!((password[i]>='a'&&password[i]<='z')||(password[i]>='0'&&password[i]<='9')||(password[i]>='A'&&password[i]<='Z')))
            {
                passwordflag=false;
                break;
            }
        }
        for(int i =0;i<phonenum.length();i++)
        {
            if(phonenum[i]<'0'||phonenum>'9')
            {
                phonenumflag=false;
                break;
            }
        }
        if(countflag==false)
            QMessageBox::warning(this,"warning","Count format error!");
        else if(passwordflag==false)
            QMessageBox::warning(this,"warning","Password format error!");
        else if(password!=comfirm_password)
            QMessageBox::warning(this,"warning","The two passwords are inconsistent!");
        else if(phonenumflag==false)
            QMessageBox::warning(this,"warning","Phonenumber format error!");
        else
        {
            QSqlDatabase db;
            if(QSqlDatabase::contains("qt_sql_default_connection"))
                db = QSqlDatabase::database("qt_sql_default_connection");
            else
                db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("waimai.db");
            if(db.open()==false)
                QMessageBox::warning(this,"warning",db.lastError().text());
            QSqlQuery sqlq(db);
            QString ins =QString("insert into regist values('%1','%2','%3','%4',0);").arg(count).arg(password).arg(phonenum).arg(kind);
            if(!sqlq.exec(ins))
                QMessageBox::warning(this,"warning","Count has existed!");
            else
                QMessageBox::information(this,"Success!","Regist successfully!");
        }
    }

}

void Dialog::on_pushButton_2_clicked()//返回按钮
{
    this->close();
}
