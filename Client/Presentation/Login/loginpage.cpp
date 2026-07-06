#include "loginpage.h"
#include "Presentation/Login/ui_loginpage.h"

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

void LoginPage::setLoginUseCase(LoginUseCase *loginUseCase){
    loginUseCase_ = loginUseCase;
}

void LoginPage::on_pushButton_sSignUp_clicked()
{
    emit signUpRequested();
}


void LoginPage::on_pushButton_ForgotPassword_clicked()
{
    emit resetPasswordRequested();
}


void LoginPage::on_pushButton_Login_clicked()
{

    loginUseCase_->execute(ui->lineEdit_UserName->text().toStdString(), ui->lineEdit_Password->text().toStdString());
}