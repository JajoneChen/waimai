/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *Login;
    QLabel *count;
    QCheckBox *checkBox;
    QLineEdit *Password;
    QPushButton *Regist;
    QLineEdit *Count;
    QLabel *password;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(453, 434);
        MainWindow->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	font-size:16px;\n"
"	font-family:Century Gothic;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 391, 361));
        frame->setStyleSheet(QString::fromUtf8("	border-radius:15px;\n"
"	background-image:url(:/image/background.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 170, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("	background:#03a9f4;\n"
"	color:#fff;\n"
"	border-radius:15px"));
        Login = new QPushButton(frame);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setGeometry(QRect(80, 260, 81, 41));
        Login->setStyleSheet(QString::fromUtf8("	background:#03a9f4;\n"
"	color:#fff;\n"
"	border-radius:15px"));
        count = new QLabel(frame);
        count->setObjectName(QString::fromUtf8("count"));
        count->setGeometry(QRect(80, 40, 31, 21));
        count->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(190, 220, 91, 19));
        checkBox->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        Password = new QLineEdit(frame);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(80, 170, 201, 31));
        Password->setStyleSheet(QString::fromUtf8("	background:transparent;\n"
"	border:none;\n"
"	color:#717072;\n"
"	border-bottom:1px solid #717072;"));
        Regist = new QPushButton(frame);
        Regist->setObjectName(QString::fromUtf8("Regist"));
        Regist->setGeometry(QRect(210, 260, 81, 41));
        Regist->setStyleSheet(QString::fromUtf8("	background:#03a9f4;\n"
"	color:#fff;\n"
"	border-radius:15px"));
        Count = new QLineEdit(frame);
        Count->setObjectName(QString::fromUtf8("Count"));
        Count->setGeometry(QRect(80, 70, 201, 31));
        Count->setStyleSheet(QString::fromUtf8("	background:transparent;\n"
"	border:none;\n"
"	color:#717072;\n"
"	border-bottom:1px solid #717072;"));
        password = new QLabel(frame);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(80, 140, 31, 21));
        password->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 0, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/image/close.png);\n"
"border-radius:15px"));
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(Count, Password);
        QWidget::setTabOrder(Password, pushButton);
        QWidget::setTabOrder(pushButton, checkBox);
        QWidget::setTabOrder(checkBox, Login);
        QWidget::setTabOrder(Login, Regist);
        QWidget::setTabOrder(Regist, pushButton_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        Login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        count->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        Password->setPlaceholderText(QApplication::translate("MainWindow", "Password", nullptr));
        Regist->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        Count->setPlaceholderText(QApplication::translate("MainWindow", "Username", nullptr));
        password->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
