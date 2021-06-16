/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_shoppingcart
{
public:

    void setupUi(QDialog *shoppingcart)
    {
        if (shoppingcart->objectName().isEmpty())
            shoppingcart->setObjectName(QString::fromUtf8("shoppingcart"));
        shoppingcart->resize(400, 300);

        retranslateUi(shoppingcart);

        QMetaObject::connectSlotsByName(shoppingcart);
    } // setupUi

    void retranslateUi(QDialog *shoppingcart)
    {
        shoppingcart->setWindowTitle(QApplication::translate("shoppingcart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shoppingcart: public Ui_shoppingcart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
