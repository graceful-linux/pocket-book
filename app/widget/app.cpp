#include "app.h"

#include <QApplication>
#include <QDebug>

App::App(QWidget *parent) : QWidget(parent)
{
    mCanLogin = false;

    setFixedSize(600, 400);

    mMainWidget = new QWidget;
    mRightWidget = new QWidget;
    mRightLayout = new QVBoxLayout(mRightWidget);
    mMainLayout = new QHBoxLayout(mMainWidget);
    mNav = new Nav();
    mTipsLabel = new QLabel("Item: 0");

    mRightWidget->setFixedWidth(600 - mNav->width());
    mNav->setRowHeight(50);
    mNav->addItem("常规1");
    mNav->addItem("常规2");
    mNav->addItem("常规3");
    mNav->addItem("常规4");
    mNav->addItem("常规5");
    mNav->addItem("常规6");

    mRightLayout->addWidget(mTipsLabel, 0, Qt::AlignCenter);

    mMainLayout->setContentsMargins(0, 0, 0, 0);
    mMainLayout->addWidget(mNav);
    mMainLayout->addWidget(mRightWidget);

    setLayout(mMainLayout);
//    setCen

    connect(mNav, &Nav::currentItemChanged, this, [=](const int& cur) {
        mTipsLabel->setText("item: " + QString::number(cur));
    });
}

bool App::canLogin()
{
    return mCanLogin;
}

void App::showEvent(QShowEvent*)
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

