#include "app.h"

#include <QApplication>
#include <QDebug>

App::App(QWidget *parent) : QWidget(parent)
{
    mCanLogin = false;
}

bool App::canLogin()
{
    return mCanLogin;
}

void App::showEvent(QShowEvent *event)
{
    Login login(this);

    if (QDialog::Accepted == login.exec()) {
        qDebug() << "登陆成功！";
        mCanLogin = true;
    } else {
        qDebug() << "登录失败!";
        mCanLogin = false;
    }
}

