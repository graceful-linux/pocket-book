#ifndef APP_H
#define APP_H
#include "login.h"
#include "nav.h"

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>

class App : public QWidget
{
    Q_OBJECT
public:
    explicit App(QWidget *parent = nullptr);

    // 登录是否成功
    bool canLogin ();

protected:
    void showEvent(QShowEvent *event) override;

Q_SIGNALS:

private:
    int                 mMinWidth;
    int                 mMinHeight;

    bool                mCanLogin;

    Nav*                mNav;
    QLabel*             mTipsLabel;

    QWidget*            mMainWidget;
    QWidget*            mRightWidget;

    QHBoxLayout*        mMainLayout;                // 整体布局
    QVBoxLayout*        mMainContentLayout;         // 主要内容布局
};

#endif // APP_H
