/********************************************************************************
** Form generated from reading UI file 'findpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPASSWORD_H
#define UI_FINDPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_findpassword
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *findpassword)
    {
        if (findpassword->objectName().isEmpty())
            findpassword->setObjectName(QString::fromUtf8("findpassword"));
        findpassword->resize(442, 250);
        lineEdit = new QLineEdit(findpassword);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 40, 191, 31));
        lineEdit_2 = new QLineEdit(findpassword);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 100, 191, 31));
        label = new QLabel(findpassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 72, 15));
        label_2 = new QLabel(findpassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 72, 15));
        pushButton = new QPushButton(findpassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 170, 81, 31));
        pushButton->setAutoRepeatDelay(300);
        pushButton->setAutoRepeatInterval(100);
        pushButton->setAutoDefault(true);
        pushButton_2 = new QPushButton(findpassword);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 170, 81, 31));

        retranslateUi(findpassword);

        QMetaObject::connectSlotsByName(findpassword);
    } // setupUi

    void retranslateUi(QDialog *findpassword)
    {
        findpassword->setWindowTitle(QApplication::translate("findpassword", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("findpassword", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("findpassword", "\346\211\213\346\234\272\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("findpassword", "\351\252\214\350\257\201", nullptr));
        pushButton_2->setText(QApplication::translate("findpassword", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findpassword: public Ui_findpassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPASSWORD_H
