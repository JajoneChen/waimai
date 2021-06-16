/********************************************************************************
** Form generated from reading UI file 'ridder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIDDER_H
#define UI_RIDDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ridder
{
public:
    QFrame *frame;
    QTableView *tableView;
    QPushButton *pushButton_5;

    void setupUi(QDialog *ridder)
    {
        if (ridder->objectName().isEmpty())
            ridder->setObjectName(QString::fromUtf8("ridder"));
        ridder->resize(751, 420);
        frame = new QFrame(ridder);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 0, 631, 421));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 611, 391));
        pushButton_5 = new QPushButton(ridder);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(650, 10, 93, 28));

        retranslateUi(ridder);

        QMetaObject::connectSlotsByName(ridder);
    } // setupUi

    void retranslateUi(QDialog *ridder)
    {
        ridder->setWindowTitle(QApplication::translate("ridder", "Welcome!", nullptr));
        pushButton_5->setText(QApplication::translate("ridder", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ridder: public Ui_ridder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIDDER_H
