#include "signuppage.h"
#include "ui_signuppage.h"

SignUpPage::SignUpPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUpPage::~SignUpPage()
{
    delete ui;
}

void SignUpPage::on_pushButton_back_clicked()
{
    emit backToLoginRequested();
}


void SignUpPage::on_signup_clicked()
{
    emit signUpRequested();
}

