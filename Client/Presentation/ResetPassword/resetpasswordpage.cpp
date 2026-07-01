#include "resetpasswordpage.h"
#include "ui_resetpasswordpage.h"

ResetPasswordPage::ResetPasswordPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResetPasswordPage)
{
    ui->setupUi(this);
}

ResetPasswordPage::~ResetPasswordPage()
{
    delete ui;
}


void ResetPasswordPage::on_pushButton_back_clicked()
{
    emit backToLoginRequested();
}


void ResetPasswordPage::on_pushButton_reset_password_clicked()
{
    emit backToLoginRequested();
}

