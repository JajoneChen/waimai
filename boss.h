#ifndef BOSS_H
#define BOSS_H

#include <QDialog>

namespace Ui {
class boss;
}

class boss : public QDialog
{
    Q_OBJECT

public:
    explicit boss(QWidget *parent = nullptr);
    ~boss();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::boss *ui;
};

#endif // BOSS_H
