#include "addgoods.h"
#include "ui_addgoods.h"
#include "boss.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QFileDialog>
#include <QImage>
#include <QFileInfo>

addgoods::addgoods(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addgoods)
{
    ui->setupUi(this);
}

addgoods::~addgoods()
{
    delete ui;
}

void addgoods::on_pushButton_2_clicked()
{
    this->close();
}

void addgoods::on_pushButton_clicked()//确认按钮
{
    QString name=ui->lineEdit->text();
    QFile* file=new QFile(ui->label_6->text());
    file->open(QIODevice::ReadOnly);//设置为只读
    QByteArray image=file->readAll();//将数据转换为QByteArray类型存储
    file->close();
    double price=ui->lineEdit_3->text().toDouble();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waimai.db");
    if(db.open()==false)
        QMessageBox::warning(this,"warning",db.lastError().text());
    QSqlQuery sqlq(db);
    QString ins =QString("insert into goods values('%1',:imagedata,'%2');").arg(name).arg(price);
    sqlq.prepare(ins);
    sqlq.bindValue(":imagedata",image);
    if(!sqlq.exec())
    {
        QMessageBox::warning(this,"warning","Add failed."+sqlq.lastError().text());
    }
    else
        QMessageBox::information(this,"information","Add successfully!");
    ui->lineEdit->clear();
    ui->label_5->clear();
    ui->lineEdit_3->clear();
    ui->label_6->clear();
}

void addgoods::on_pushButton_3_clicked()//选择图片
{
    QString OpenFile,OpenFilePath;
    QImage image;
    OpenFile = QFileDialog::getOpenFileName(this,"Please choose an image file","./","Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
    if(OpenFile!="")
    {
        if(image.load(OpenFile))
        {
            ui->label_5->setPixmap(QPixmap::fromImage(image).scaled(ui->label_5->size()));
        }
        //显示路径
        QFileInfo OpenFileInfo = QFileInfo(OpenFile);
        OpenFilePath = OpenFileInfo.filePath();
        ui->label_6->setText(OpenFilePath);
    }
}
