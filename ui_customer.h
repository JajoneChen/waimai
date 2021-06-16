/********************************************************************************
** Form generated from reading UI file 'customer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_H
#define UI_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customer
{
public:
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;

    void setupUi(QDialog *customer)
    {
        if (customer->objectName().isEmpty())
            customer->setObjectName(QString::fromUtf8("customer"));
        customer->resize(789, 589);
        customer->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(customer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(10, 10, 771, 571));
        frame->setStyleSheet(QString::fromUtf8("background-image:url(:/image/customer-background.jpg)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 1, 122, 570));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setMinimumSize(QSize(99, 142));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"image: url(:/image/shops.png);\n"
"text-align:bottom;\n"
"padding:20px;\n"
""));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(99, 142));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"image: url(:/image/shopping.png);\n"
"padding:25px;\n"
"text-align:bottom;"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(99, 142));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"image: url(:/image/order.png);\n"
"text-align:bottom;\n"
"padding:20px;\n"
""));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(99, 142));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"image: url(:/image/quit.png);\n"
"text-align:bottom;\n"
"padding:27px;\n"
"padding-bottom:20px"));

        verticalLayout->addWidget(pushButton);

        graphicsView = new QGraphicsView(frame);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(140, 10, 241, 111));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image:url(:/image/1.png)"));
        graphicsView_2 = new QGraphicsView(frame);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(140, 160, 241, 131));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/5.png);"));
        graphicsView_3 = new QGraphicsView(frame);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(140, 330, 241, 111));
        graphicsView_3->setStyleSheet(QString::fromUtf8("border-image: url(:/image/2.png);"));

        retranslateUi(customer);

        QMetaObject::connectSlotsByName(customer);
    } // setupUi

    void retranslateUi(QDialog *customer)
    {
        customer->setWindowTitle(QApplication::translate("customer", "Welcome!", nullptr));
        pushButton_4->setText(QApplication::translate("customer", "\n"
"\n"
"\n"
"\n"
"\346\237\245\347\234\213\345\272\227\351\223\272", nullptr));
        pushButton_3->setText(QApplication::translate("customer", "\n"
"\n"
"\n"
"\350\264\255\347\211\251\350\275\246", nullptr));
        pushButton_2->setText(QApplication::translate("customer", "\n"
"\n"
"\n"
"\345\244\226\345\215\226\350\256\242\345\215\225", nullptr));
        pushButton->setText(QApplication::translate("customer", "\n"
"\n"
"\n"
"\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customer: public Ui_customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
