/********************************************************************************
** Form generated from reading UI file 'boss.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOSS_H
#define UI_BOSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_boss
{
public:
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QDialog *boss)
    {
        if (boss->objectName().isEmpty())
            boss->setObjectName(QString::fromUtf8("boss"));
        boss->resize(639, 583);
        frame = new QFrame(boss);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 621, 561));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 93, 28));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 10, 93, 28));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 10, 93, 28));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(510, 10, 93, 28));
        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 50, 601, 431));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 500, 201, 31));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 500, 93, 28));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 510, 72, 15));

        retranslateUi(boss);

        QMetaObject::connectSlotsByName(boss);
    } // setupUi

    void retranslateUi(QDialog *boss)
    {
        boss->setWindowTitle(QApplication::translate("boss", "Welcome!", nullptr));
        pushButton->setText(QApplication::translate("boss", "\345\242\236\345\212\240\345\225\206\345\223\201", nullptr));
        pushButton_2->setText(QApplication::translate("boss", "\345\210\240\351\231\244\345\225\206\345\223\201", nullptr));
        pushButton_4->setText(QApplication::translate("boss", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        pushButton_5->setText(QApplication::translate("boss", "\350\277\224\345\233\236", nullptr));
        pushButton_3->setText(QApplication::translate("boss", "\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("boss", "\350\276\223\345\205\245\350\217\234\345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boss: public Ui_boss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOSS_H
