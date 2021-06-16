#ifndef EDITGOODS_H
#define EDITGOODS_H

#include <QDialog>

namespace Ui {
class editgoods;
}

class editgoods : public QDialog
{
    Q_OBJECT

public:
    explicit editgoods(QWidget *parent = nullptr);
    ~editgoods();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::editgoods *ui;
};

#endif // EDITGOODS_H
