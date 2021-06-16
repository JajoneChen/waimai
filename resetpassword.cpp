#include "resetpassword.h"
#include "ui_resetpassword.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

resetpassword::resetpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetpassword)
{
    ui->setupUi(this);
}

resetpassword::~resetpassword()
{
    delete ui;
}
