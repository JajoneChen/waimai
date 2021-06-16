#include "boss.h"
#include "ui_boss.h"
#include <QStandardItemModel>
#include <QTableWidget>
#include "mainwindow.h"
#include "delgoods.h"
#include "addgoods.h"
#include "editgoods.h"

boss::boss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boss)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("商品名称,商品图片,价格").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

boss::~boss()
{
    delete ui;
}

void boss::on_pushButton_5_clicked()//返回
{
    this->close();
    MainWindow* p=new MainWindow;
    p->show();
}

void boss::on_pushButton_2_clicked()//删除商品
{
    delgoods* d=new delgoods;
    d->show();
}

void boss::on_pushButton_clicked()//增加商品
{
    addgoods* a=new addgoods;
    a->show();
}

void boss::on_pushButton_4_clicked()//修改商品
{
    editgoods* e=new editgoods;
    e->show();
}

void boss::on_pushButton_3_clicked()//查询
{
    QString s=ui->lineEdit->text();//获取输入商品名
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(db.open()==false)
        QMessageBox::warning(this,"warning",db.lastError().text());
    QSqlQuery query(db);
    QString sqlq = QString("select * from goods where name='%1'").arg(s);
    QSqlQueryModel* model=new QSqlQueryModel(ui->tableView);
    query.exec(sqlq);
    query.next();
    if(query.value(0)=="")
    {
        QMessageBox::warning(this,"warning","There is no such product.");
    }
    else
    {
        model->setQuery(sqlq);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    db.close();
}
