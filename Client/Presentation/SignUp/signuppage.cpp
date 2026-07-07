#include "signuppage.h"
#include "Presentation/SignUp/ui_signuppage.h"

SignUpPage::SignUpPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
    
{
    
    ui->setupUi(this);
}

SignUpPage::~SignUpPage()
{
    delete ui;
}

void SignUpPage::setSignupUsecase(SignupUseCase *usecase){
    signupUsecase_ = usecase;
}

void SignUpPage::on_pushButton_back_clicked()
{
    emit backToLoginRequested();
}


void SignUpPage::on_signup_clicked(){
    SignUpRequest request;
    request.name_ = ui->lineEdit_name->text().toStdString();
    request.username_ = ui->lineEdit_username->text().toStdString();
    request.phoneNumber_ = ui->lineEdit_phone_number->text().toStdString();
    request.email_ = ui->lineEdit_email->text().toStdString();
    request.password_ = ui->password->text().toStdString();
    request.confirmPassword_ = ui->lineEdit_confirm_password->text().toStdString();
    signupUsecase_->execute(request);

}

