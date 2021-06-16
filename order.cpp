#include "order.h"
#include "ui_order.h"

Order::Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//隐藏边框
    setAttribute(Qt::WA_TranslucentBackground);//隐藏周围空白
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(db.open()==false)
        QMessageBox::warning(this,"warning",db.lastError().text());
    QSqlQueryModel* model=new QSqlQueryModel(ui->tableView);
    QSqlQueryModel* model_2=new QSqlQueryModel(ui->tableView_2);
    QSqlQueryModel* model_3=new QSqlQueryModel(ui->tableView_3);
    model->setQuery("select * from ordergoods");
    model_2->setQuery("select * from ordergoods where goods_pay_state = 1");
    model_3->setQuery("select * from ordergoods where goods_pay_state = 0");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_2->setModel(model_2);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_3->setModel(model_3);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    db.close();
    ui->tableView->setVisible(1);//全部订单
    ui->tableView_2->setVisible(0);//已付款
    ui->tableView_3->setVisible(0);//待付款
}

Order::~Order()
{
    delete ui;
}

// 鼠标左键触发
void Order::mousePressEvent(QMouseEvent *event){

    // 判断鼠标左键
    if(event->button() == Qt::LeftButton){

        // 求坐标差值
        coordinate = event->globalPos() - this->frameGeometry().topLeft();
    }

}

// 鼠标移动触发
void Order::mouseMoveEvent(QMouseEvent *event){

    // 判断左键(Qt::LeftButton)是否被按下, 只有按下了才返回1(true)
    if(event->buttons() & Qt::LeftButton){

        // 移动窗口
        move(event->globalPos() - coordinate);

    }

}

void Order::on_pushButton_clicked()//全部订单
{
    ui->tableView->setVisible(1);
    ui->tableView_2->setVisible(0);
    ui->tableView_3->setVisible(0);
}

void Order::on_pushButton_2_clicked()//已付款
{
    ui->tableView->setVisible(0);
    ui->tableView_2->setVisible(1);
    ui->tableView_3->setVisible(0);
}

void Order::on_pushButton_3_clicked()//待付款
{
    ui->tableView->setVisible(0);
    ui->tableView_2->setVisible(0);
    ui->tableView_3->setVisible(1);
}
