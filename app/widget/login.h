#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

Q_SLOT void canLogin(bool);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
