/********************************************************************************
** Form generated from reading UI file 'order.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_H
#define UI_ORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Order
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QTableView *tableView;
    QTableView *tableView_2;
    QTableView *tableView_3;

    void setupUi(QDialog *Order)
    {
        if (Order->objectName().isEmpty())
            Order->setObjectName(QString::fromUtf8("Order"));
        Order->resize(1134, 1133);
        Order->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Order);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 811, 71));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 15pt \"\351\200\240\345\255\227\345\267\245\346\210\277\345\212\233\351\273\221\357\274\210\351\235\236\345\225\206\347\224\250\357\274\211\345\270\270\350\247\204\344\275\223\";\n"
"color:#fff"));
        pushButton = new QPushButton(Order);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 70, 101, 61));
        pushButton->setStyleSheet(QString::fromUtf8("	background:#03a9f4;\n"
"	color:#fff;\n"
"	border-radius:15px;\n"
"	border:1px solid black;"));
        pushButton_2 = new QPushButton(Order);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 70, 111, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("	background:#03a9f4;\n"
"	color:#fff;\n"
"	border-radius:15px;\n"
"	border:1px solid black;"));
        pushButton_3 = new QPushButton(Order);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 70, 111, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("	background:#03a9f4;\n"
"	color:#fff;\n"
"	border-radius:15px;\n"
"	border:1px solid black;"));
        label_3 = new QLabel(Order);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(-10, 60, 821, 61));
        label_3->setStyleSheet(QString::fromUtf8("background-image:url(:/image/customer-background.jpg)"));
        tableView = new QTableView(Order);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 120, 811, 391));
        tableView_2 = new QTableView(Order);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(0, 120, 811, 391));
        tableView_3 = new QTableView(Order);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(0, 120, 811, 391));
        label_3->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        tableView->raise();
        tableView_2->raise();
        tableView_3->raise();

        retranslateUi(Order);

        QMetaObject::connectSlotsByName(Order);
    } // setupUi

    void retranslateUi(QDialog *Order)
    {
        Order->setWindowTitle(QApplication::translate("Order", "Dialog", nullptr));
        label->setText(QApplication::translate("Order", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        pushButton->setText(QApplication::translate("Order", "\345\205\250\351\203\250\350\256\242\345\215\225", nullptr));
        pushButton_2->setText(QApplication::translate("Order", "\345\267\262\344\273\230\346\254\276", nullptr));
        pushButton_3->setText(QApplication::translate("Order", "\345\276\205\344\273\230\346\254\276", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Order: public Ui_Order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H
