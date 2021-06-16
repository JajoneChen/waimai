/********************************************************************************
** Form generated from reading UI file 'addgoods.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGOODS_H
#define UI_ADDGOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addgoods
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *addgoods)
    {
        if (addgoods->objectName().isEmpty())
            addgoods->setObjectName(QString::fromUtf8("addgoods"));
        addgoods->resize(418, 416);
        lineEdit = new QLineEdit(addgoods);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 40, 171, 31));
        lineEdit_3 = new QLineEdit(addgoods);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 280, 171, 31));
        label = new QLabel(addgoods);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 72, 15));
        label_2 = new QLabel(addgoods);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 72, 15));
        label_3 = new QLabel(addgoods);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 290, 72, 15));
        pushButton = new QPushButton(addgoods);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 320, 93, 28));
        pushButton_2 = new QPushButton(addgoods);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 320, 93, 28));
        label_4 = new QLabel(addgoods);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 10, 121, 20));
        pushButton_3 = new QPushButton(addgoods);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 140, 51, 41));
        label_5 = new QLabel(addgoods);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 110, 141, 91));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(addgoods);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 210, 311, 51));
        label_6->setWordWrap(true);

        retranslateUi(addgoods);

        QMetaObject::connectSlotsByName(addgoods);
    } // setupUi

    void retranslateUi(QDialog *addgoods)
    {
        addgoods->setWindowTitle(QApplication::translate("addgoods", "Dialog", nullptr));
        label->setText(QApplication::translate("addgoods", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        label_2->setText(QApplication::translate("addgoods", "\345\225\206\345\223\201\345\233\276\347\211\207", nullptr));
        label_3->setText(QApplication::translate("addgoods", "\344\273\267\346\240\274", nullptr));
        pushButton->setText(QApplication::translate("addgoods", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("addgoods", "\350\277\224\345\233\236", nullptr));
        label_4->setText(QApplication::translate("addgoods", "\346\267\273\345\212\240\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QApplication::translate("addgoods", "+", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addgoods: public Ui_addgoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGOODS_H
