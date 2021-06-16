#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(!db.open())
    {
        qDebug() << "Database can't open!";
        return 0;
    }
    QSqlQuery sql_query;

    //创表
    //用户信息表
    if(!sql_query.exec("create table regist(count char(16) primary key not NULL, password char(16) not NULL, phonenum char(11) unique, kind int not NULL, remember int not NULL)"))
        qDebug() << "Error: Fail to create table."<< sql_query.lastError();//1商家 2骑手 3用户 4管理员
    else
        qDebug() << "Table created!";
    //订单表
    if(!sql_query.exec("create table ordergoods(count char(16) primary key not NULL, goods_name char(50), goods_number int, goods_cost double, goods_arrive_state int, goods_pay_state int)"))
        qDebug() << "Error: Fail to create table."<< sql_query.lastError();//用户名，菜品名，菜品数量，菜品金额，订单送达状态(0为未送达，1为送达)，订单付款状态(0为未付款，1为付款)
    else
        qDebug() << "Table created!";
    //商品表
    if(!sql_query.exec("create table goods(name char(50) not NULL, image blob, price double)"))
        qDebug() << "Error: Fail to create table."<< sql_query.lastError();//商品名，商品图片，商品价格
    else
        qDebug() << "Table created!";

    //插入数据
    if(!sql_query.exec("insert into regist values(\"admin\",\"admin\",\"13000000000\",4,0)"))
        qDebug()<<sql_query.lastError();
    else
        qDebug()<<"insert success";

    //查询数据库
    sql_query.exec("select * from regist");
    while(sql_query.next())
    {
        qDebug()<<sql_query.value(0).toString()<<sql_query.value(1).toString()<<sql_query.value(2).toString()<<sql_query.value(3).toInt();
    }
    db.close();
    return a.exec();
}
