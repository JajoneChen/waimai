/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_administrator
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *administrator)
    {
        if (administrator->objectName().isEmpty())
            administrator->setObjectName(QString::fromUtf8("administrator"));
        administrator->resize(690, 458);
        tableView = new QTableView(administrator);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 70, 651, 371));
        pushButton = new QPushButton(administrator);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 40, 93, 28));
        pushButton_2 = new QPushButton(administrator);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 30, 93, 28));

        retranslateUi(administrator);

        QMetaObject::connectSlotsByName(administrator);
    } // setupUi

    void retranslateUi(QDialog *administrator)
    {
        administrator->setWindowTitle(QApplication::translate("administrator", "\347\256\241\347\220\206\345\221\230", nullptr));
        pushButton->setText(QApplication::translate("administrator", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_2->setText(QApplication::translate("administrator", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class administrator: public Ui_administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
