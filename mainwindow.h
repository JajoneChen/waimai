#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "regist.h"
#include "findpassword.h"
#include "administrator.h"
#include "ridder.h"
#include "customer.h"
#include "boss.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Dialog *re=new Dialog;
    findpassword *fp=new findpassword;
    administrator *ad=new administrator;
    boss *bo=new boss;
    ridder *ri=new ridder;
    customer * cu=new customer;
    bool getrboxcode()
    {
        return rboxcode;
    }
    void setrboxcode(bool x)
    {
        rboxcode=x;
    }
    bool getfboxcode()
    {
        return fboxcode;
    }
    void setfboxcode(bool x)
    {
        fboxcode=x;
    }

private slots:
    void on_Login_clicked();

    void on_Regist_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QPoint coordinate;
    bool rboxcode = false;
    bool fboxcode = false;
};
#endif // MAINWINDOW_H
