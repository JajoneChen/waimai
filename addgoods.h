#ifndef ADDGOODS_H
#define ADDGOODS_H

#include <QDialog>

namespace Ui {
class addgoods;
}

class addgoods : public QDialog
{
    Q_OBJECT

public:
    explicit addgoods(QWidget *parent = nullptr);
    ~addgoods();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::addgoods *ui;
};

#endif // ADDGOODS_H
