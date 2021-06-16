/********************************************************************************
** Form generated from reading UI file 'delgoods.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELGOODS_H
#define UI_DELGOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_delgoods
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *delgoods)
    {
        if (delgoods->objectName().isEmpty())
            delgoods->setObjectName(QString::fromUtf8("delgoods"));
        delgoods->resize(376, 177);
        label = new QLabel(delgoods);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 72, 15));
        label_2 = new QLabel(delgoods);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 72, 15));
        lineEdit = new QLineEdit(delgoods);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 70, 211, 31));
        pushButton = new QPushButton(delgoods);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 130, 93, 28));
        pushButton_2 = new QPushButton(delgoods);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 130, 93, 28));

        retranslateUi(delgoods);

        QMetaObject::connectSlotsByName(delgoods);
    } // setupUi

    void retranslateUi(QDialog *delgoods)
    {
        delgoods->setWindowTitle(QApplication::translate("delgoods", "Dialog", nullptr));
        label->setText(QApplication::translate("delgoods", "\345\210\240\351\231\244\345\225\206\345\223\201", nullptr));
        label_2->setText(QApplication::translate("delgoods", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        pushButton->setText(QApplication::translate("delgoods", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("delgoods", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delgoods: public Ui_delgoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELGOODS_H
