#include "ridder.h"
#include "ui_ridder.h"
#include <QStandardItemModel>
#include "mainwindow.h"

ridder::ridder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ridder)
{
    ui->setupUi(this);
    ui->tableView->setShowGrid(true);//显示网格线
    ui->tableView->setGridStyle(Qt::SolidLine);//画网格线
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("订单号,顾客姓名,顾客电话,送货地址").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

ridder::~ridder()
{
    delete ui;
}

void ridder::on_pushButton_5_clicked()
{
    this->close();
    MainWindow* m=new MainWindow;
    m->show();
}
