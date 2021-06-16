#ifndef RIDDER_H
#define RIDDER_H

#include <QDialog>

namespace Ui {
class ridder;
}

class ridder : public QDialog
{
    Q_OBJECT

public:
    explicit ridder(QWidget *parent = nullptr);
    ~ridder();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::ridder *ui;
};

#endif // RIDDER_H
