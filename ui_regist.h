/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QCheckBox *boss;
    QCheckBox *ridder;
    QCheckBox *customer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(443, 340);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 20, 201, 31));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 72, 15));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 90, 72, 15));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 150, 72, 15));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 210, 72, 15));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 80, 201, 31));
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 140, 201, 31));
        lineEdit_4 = new QLineEdit(Dialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 200, 201, 31));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 290, 93, 28));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 290, 93, 28));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 250, 401, 21));
        boss = new QCheckBox(widget);
        boss->setObjectName(QString::fromUtf8("boss"));
        boss->setGeometry(QRect(70, 0, 91, 19));
        boss->setAutoExclusive(true);
        ridder = new QCheckBox(widget);
        ridder->setObjectName(QString::fromUtf8("ridder"));
        ridder->setGeometry(QRect(150, 0, 101, 19));
        ridder->setAutoExclusive(true);
        customer = new QCheckBox(widget);
        customer->setObjectName(QString::fromUtf8("customer"));
        customer->setGeometry(QRect(270, 0, 91, 19));
        customer->setAutoExclusive(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
        label->setText(QApplication::translate("Dialog", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", nullptr));
        boss->setText(QApplication::translate("Dialog", "\345\225\206\345\256\266", nullptr));
        ridder->setText(QApplication::translate("Dialog", "\345\244\226\345\215\226\351\205\215\351\200\201\345\221\230", nullptr));
        customer->setText(QApplication::translate("Dialog", "\346\231\256\351\200\232\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
