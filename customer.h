#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include "order.h"
#include "shoppingcart.h"
#include <QMouseEvent>
#include <string>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class customer;
}

class customer : public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = nullptr);
    Order* o = new Order;
    shoppingcart* s=new shoppingcart;
    bool getoboxcode()
    {
        return oboxcode;
    }
    void setoboxcode(bool x)
    {
        sboxcode=x;
    }
    bool getsboxcode()
    {
        return oboxcode;
    }
    void setsboxcode(bool x)
    {
        sboxcode=x;
    }
    ~customer();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::customer *ui;
    QPoint coordinate;
    bool oboxcode = false;
    bool sboxcode = false;
};

#endif // CUSTOMER_H
