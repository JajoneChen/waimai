/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_resetpassword
{
public:

    void setupUi(QDialog *resetpassword)
    {
        if (resetpassword->objectName().isEmpty())
            resetpassword->setObjectName(QString::fromUtf8("resetpassword"));
        resetpassword->resize(541, 366);

        retranslateUi(resetpassword);

        QMetaObject::connectSlotsByName(resetpassword);
    } // setupUi

    void retranslateUi(QDialog *resetpassword)
    {
        resetpassword->setWindowTitle(QApplication::translate("resetpassword", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resetpassword: public Ui_resetpassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
