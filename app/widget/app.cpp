#include "app.h"

#include <QApplication>
#include <QDebug>

App::App(QWidget *parent) : QWidget(parent)
{
    mMinWidth = 600;
    mMinHeight = 300;

    mCanLogin = false;

    mNav = new Nav();

    mNewRecord = new QLabel("记一笔");
    mReportForm = new QLabel ("报表");
    mHistoryDetail = new QLabel("历史明细");

    mNewRecord->hide();
    mReportForm->hide();
    mHistoryDetail->hide();

    mMainWidget = new QWidget();
    mRightWidget = new QWidget();

    mMainLayout = new QHBoxLayout();

    mMainContentLayout = new QVBoxLayout();

    mNav->getMinWidth() > mMinWidth ? setMinimumWidth(mNav->getMinWidth()) : setMinimumWidth(mMinWidth);
    mNav->getMinHeight() > mMinHeight ? setMinimumHeight(mNav->getMinHeight()) : setMinimumHeight(mMinHeight);

    connect(mNav, SIGNAL(navSizeChanged(int&,int&)), this, SLOT([=](int&w, int&h){
        w > mMinWidth ? setMinimumWidth(w) : setMinimumWidth(mMinWidth);
        h > mMinHeight ? setMinimumHeight(h) : setMinimumHeight(mMinHeight);
    }));

    mNav->addItem("菜单");
    mNav->addItem("记一笔");
    mNav->addItem("明细");
    mNav->addItem("报表");

    mMainContentLayout->addWidget(mNewRecord, 0, Qt::AlignCenter);
    mMainContentLayout->addWidget(mReportForm, 0, Qt::AlignCenter);
    mMainContentLayout->addWidget(mHistoryDetail, 0, Qt::AlignCenter);

    mHistoryDetail->show();

    mMainLayout->setContentsMargins(0, 0, 0, 0);
    mMainLayout->addWidget(mNav);
    mMainLayout->addLayout(mMainContentLayout);

    setLayout(mMainLayout);

    connect(mNav, &Nav::currentItemChanged, this, [=](const int& cur) {
        if (0 == cur) {
            // FIXME:// 添加展开效果
            return ;
        }
        mNewRecord->hide();
        mReportForm->hide();
        mHistoryDetail->hide();

        switch (cur) {
        case 0:
        case 1:
            mNewRecord->show();
            break;
        case 2:
            mHistoryDetail->show();
            break;
        case 3:
            mReportForm->show();
            break;
        }
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

