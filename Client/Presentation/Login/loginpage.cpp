#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_pushButton_sSignUp_clicked()
{
    emit signUpRequested();
}


void LoginPage::on_pushButton_ForgotPassword_clicked()
{
    emit resetPasswordRequested();
}

