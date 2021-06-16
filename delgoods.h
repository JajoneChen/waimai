#ifndef DELGOODS_H
#define DELGOODS_H

#include <QDialog>

namespace Ui {
class delgoods;
}

class delgoods : public QDialog
{
    Q_OBJECT

public:
    explicit delgoods(QWidget *parent = nullptr);
    ~delgoods();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::delgoods *ui;
};

#endif // DELGOODS_H
