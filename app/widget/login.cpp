#include "login.h"
#include "ui_login.h"

#include <QDebug>

Login::Login(QWidget *parent) : QDialog(parent),  ui(new Ui::Login)
{
    ui->setupUi(this);


    connect(ui->loginButton, SIGNAL(clicked(bool)), this, SLOT(canLogin(bool)));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Login::~Login()
{
    delete ui;
}

void Login::canLogin(bool)
{
    if (ui->nameEdit->text().trimmed() == "name"
            && ui->passwdEdit->text().trimmed() == "passwd") {
        accept();
        qDebug() << "click";
        close();
    }
}
