/********************************************************************************
** Form generated from reading UI file 'editgoods.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITGOODS_H
#define UI_EDITGOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_editgoods
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *editgoods)
    {
        if (editgoods->objectName().isEmpty())
            editgoods->setObjectName(QString::fromUtf8("editgoods"));
        editgoods->resize(335, 356);
        lineEdit = new QLineEdit(editgoods);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 151, 31));
        lineEdit_2 = new QLineEdit(editgoods);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 70, 151, 31));
        lineEdit_3 = new QLineEdit(editgoods);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 120, 151, 91));
        lineEdit_4 = new QLineEdit(editgoods);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(100, 240, 151, 31));
        label = new QLabel(editgoods);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 72, 15));
        label_2 = new QLabel(editgoods);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(11, 80, 81, 20));
        label_3 = new QLabel(editgoods);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 150, 81, 20));
        label_4 = new QLabel(editgoods);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 250, 72, 15));
        pushButton = new QPushButton(editgoods);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 300, 61, 41));
        pushButton_2 = new QPushButton(editgoods);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 300, 61, 41));

        retranslateUi(editgoods);

        QMetaObject::connectSlotsByName(editgoods);
    } // setupUi

    void retranslateUi(QDialog *editgoods)
    {
        editgoods->setWindowTitle(QApplication::translate("editgoods", "Dialog", nullptr));
        label->setText(QApplication::translate("editgoods", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        label_2->setText(QApplication::translate("editgoods", "\344\277\256\346\224\271\345\220\215\347\247\260", nullptr));
        label_3->setText(QApplication::translate("editgoods", "\344\277\256\346\224\271\345\233\276\347\211\207", nullptr));
        label_4->setText(QApplication::translate("editgoods", "\344\277\256\346\224\271\344\273\267\346\240\274", nullptr));
        pushButton->setText(QApplication::translate("editgoods", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("editgoods", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editgoods: public Ui_editgoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITGOODS_H
