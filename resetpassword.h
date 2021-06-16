#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

namespace Ui {
class resetpassword;
}

class resetpassword : public QDialog
{
    Q_OBJECT

public:
    explicit resetpassword(QWidget *parent = nullptr);
    ~resetpassword();

private:
    Ui::resetpassword *ui;
};

#endif // RESETPASSWORD_H
