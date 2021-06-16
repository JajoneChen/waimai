#include "administrator.h"
#include "ui_administrator.h"
#include <QModelIndex>
#include "mainwindow.h"

administrator::administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(db.open()==false)
        QMessageBox::warning(this,"warning",db.lastError().text());
    QSqlQueryModel* model=new QSqlQueryModel(ui->tableView);
    model->setQuery("select * from regist");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    db.close();
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_pushButton_clicked()//删除用户
{
    int currow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString count = index.sibling(currow,0).data().toString();

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(db.open()==false)
        QMessageBox::warning(this,"warning",db.lastError().text());

    QSqlQuery query(db);
    QString c = QString("delete from regist where count='%1';").arg(count);
    if(query.exec(c))
    {
        QSqlQueryModel* model=new QSqlQueryModel(ui->tableView);
        model->setQuery("select * from regist");
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        QMessageBox::information(this,"information","Delete successfully!");
    }
    else
    {
        QMessageBox::warning(this,"warning","Delete failed.");
    }

    db.close();
}

void administrator::on_pushButton_2_clicked()//注销
{
    MainWindow* m = new MainWindow;
    this->close();
    m->show();
}
