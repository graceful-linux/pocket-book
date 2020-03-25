#ifndef APP_H
#define APP_H
#include "login.h"

#include <QWidget>

class App : public QWidget
{
    Q_OBJECT
public:
    explicit App(QWidget *parent = nullptr);

    bool canLogin ();

protected:
    void showEvent(QShowEvent *event) override;

Q_SIGNALS:

private:
    bool            mCanLogin;

};

#endif // APP_H
