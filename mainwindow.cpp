#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "regist.h"
#include "findpassword.h"
#include <string>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
using namespace std;

MainWindow::MainWindow(QWidget *parent)/*******************登陆界面********************/
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//隐藏边框
    setAttribute(Qt::WA_TranslucentBackground);//隐藏周围空白
    ui->Count->setPlaceholderText("Count");
    ui->Password->setPlaceholderText("Password");
    ui->Count->setMaxLength(10);
    ui->Password->setMaxLength(16);
    ui->Password->setEchoMode(QLineEdit::Password);
    connect(ui->Regist,SIGNAL(clicked(bool)),this,SLOT(on_Regist_clicked()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->Password,SIGNAL(returnPressed()),ui->Login,SIGNAL(clicked()),Qt::UniqueConnection);//实现按回车键登录
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 鼠标左键触发
void MainWindow::mousePressEvent(QMouseEvent *event){

    // 判断鼠标左键
    if(event->button() == Qt::LeftButton){

        // 求坐标差值
        coordinate = event->globalPos() - this->frameGeometry().topLeft();
    }

}

// 鼠标移动触发
void MainWindow::mouseMoveEvent(QMouseEvent *event){

    // 判断左键(Qt::LeftButton)是否被按下, 只有按下了才返回1(true)
    if(event->buttons() & Qt::LeftButton){

        // 移动窗口
        move(event->globalPos() - coordinate);

    }

}

void MainWindow::on_Login_clicked()//登录
{
    QString count=ui->Count->text();
    QString password=ui->Password->text();
    if(count==""&&password=="")
        QMessageBox::warning(this,"Warning!","Count and Password can't be empty!");
    else if(count=="")
        QMessageBox::warning(this,"Warning!","Count can't be empty!");
    else if(password=="")
        QMessageBox::warning(this,"Warning!","Password can't be empty!");
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    QSqlQuery sqlq(db);
    QString c = QString("select count,password from regist where count='%1';").arg(count);
    sqlq.exec(c);
    sqlq.next();
    if(sqlq.value(0).toString()=="admin" && sqlq.value(1).toString()=="admin")
    {
        ad->show();
        this->close();
    }

    if(sqlq.value(0).toString()==""||sqlq.value(1).toString()=="")
        QMessageBox::warning(this,"warning","Count or Password is error!");
    else
    {
        //1商家 2骑手 3用户
        QString shibie = QString("select kind from regist where count='%1'").arg(count);
        sqlq.exec(shibie);
        sqlq.next();
        if(sqlq.value(0).toInt()==1)
        {
            bo->show();
            this->close();
        }
        if(sqlq.value(0).toInt()==2)
        {
            ri->show();
            this->close();
        }
        if(sqlq.value(0).toInt()==3)
        {
            cu->show();
            this->close();
        }
    }
    db.close();
}

void MainWindow::on_Regist_clicked()//注册
{
    //只允许弹出一次窗口
    if(getrboxcode()==false)
    {
        setrboxcode(true);
        re->show();
        return;
    }
    else
    {
        setrboxcode(false);
        re->close();
        re->show();
        return;
    }
}

void MainWindow::on_pushButton_clicked()//找回密码
{
    //只允许弹出一次窗口
    if(getfboxcode()==false)
    {
        setfboxcode(true);
        fp->show();
        return;
    }
    else
    {
        setfboxcode(false);
        fp->close();
        fp->show();
        return;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
