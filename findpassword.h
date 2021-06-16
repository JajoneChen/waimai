#ifndef FINDPASSWORD_H
#define FINDPASSWORD_H

#include <QDialog>

namespace Ui {
class findpassword;
}

class findpassword : public QDialog
{
    Q_OBJECT

public:
    explicit findpassword(QWidget *parent = nullptr);
    ~findpassword();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::findpassword *ui;
};

#endif // FINDPASSWORD_H
