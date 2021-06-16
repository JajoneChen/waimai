#include "customer.h"
#include "ui_customer.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QFrame>

customer::customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//隐藏边框
    setAttribute(Qt::WA_TranslucentBackground);//隐藏周围空白
//    QGridLayout *pLayout = new QGridLayout();//网格布局
//    for(int i = 0; i < 8; i++)
//    {
//        QLabel *pBtn1 = new QLabel();
//        QLabel *pBtn2 = new QLabel();
//        QString pt1 = QString(":/image/%1.png").arg(2*i+1);
//        QString pt2 = QString(":/image/%1.png").arg(2*i+2);
//        pBtn1->setPixmap(QPixmap(pt1));
//        pBtn1->setGeometry(rect().x()+120,rect().y()+120,60,60);
//        pBtn2->setPixmap(QPixmap(pt2));
//        pBtn1->setMinimumSize(QSize(ui->scrollArea->width()/2,150));
//        pBtn2->setMinimumSize(QSize(ui->scrollArea->width()/2,150));
//        pBtn1->setScaledContents(true);
//        pBtn2->setScaledContents(true);
//        pBtn1->setStyleSheet("QLabel{"
//                             "border-image:url(:/image/1.png)"
//                             "}");
//        pBtn2->setStyleSheet("QLabel{"
//                             "border-image:url(:/image/2.png)"
//                             "}");
//        pBtn1->set->setIcon(QIcon(":/image/1.png"));//设图片
//        pBtn2->setIcon(QIcon(":/image/2.png"));
//        pBtn1->setFlat(true);//隐藏
//        pBtn2->setFlat(true);
//        pBtn1->setIconSize(QSize(ui->scrollArea->width()/2,150));
//        pBtn2->setIconSize(QSize(ui->scrollArea->width()/2,150));
//        pBtn1->setMaximumSize(QSize(ui->scrollArea->width()/2,150));   //width height
//        pBtn2->setMaximumSize(QSize(ui->scrollArea->width()/2,150));
//        pLayout->addWidget(pBtn1,i,0);//把按钮添加到布局控件中 第i行第0列
//        pLayout->addWidget(pBtn2,i,1);
//    }
//    ui->scrollArea->widget()->setLayout(pLayout);//把布局放置到QScrollArea的内部QWidget中
}

customer::~customer()
{
    delete ui;
}

// 鼠标左键触发
void customer::mousePressEvent(QMouseEvent *event){

    // 判断鼠标左键
    if(event->button() == Qt::LeftButton){

        // 求坐标差值
        coordinate = event->globalPos() - this->frameGeometry().topLeft();
    }

}

// 鼠标移动触发
void customer::mouseMoveEvent(QMouseEvent *event){

    // 判断左键(Qt::LeftButton)是否被按下, 只有按下了才返回1(true)
    if(event->buttons() & Qt::LeftButton){

        // 移动窗口
        move(event->globalPos() - coordinate);

    }

}

void customer::on_pushButton_clicked()//注销
{
    this->close();
}

void customer::on_pushButton_2_clicked()//外卖订单
{
    //只允许弹出一次窗口
    if(getoboxcode()==false)
    {
        setoboxcode(true);
        o->show();
        return;
    }
    else
    {
        setoboxcode(false);
        o->close();
        o->show();
        return;
    }
}

void customer::on_pushButton_3_clicked()//购物车
{
    //只允许弹出一次窗口
    if(getsboxcode()==false)
    {
        setsboxcode(true);
        s->show();
        return;
    }
    else
    {
        setsboxcode(false);
        s->close();
        s->show();
        return;
    }
}
