#include "resetpasswordpage.h"
#include "ui_resetpasswordpage.h"

ResetPasswordPage::ResetPasswordPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResetPasswordPage)
{
    ui->setupUi(this);
}

ResetPasswordPage::~ResetPasswordPage(){
    delete ui;
}
void ResetPasswordPage::setResetpasswordUsecase(ResetPasswordUsecase* usecase) {
    resetpasswordUseCase_ = usecase;
}
void ResetPasswordPage::on_pushButton_back_clicked(){
    emit backToLoginRequested();
}
void ResetPasswordPage::on_pushButton_reset_password_clicked(){
    ResetPasswordRequest request;
    request.phoneNumber_ = ui->lineEdit_phone_number->text().toStdString();
    request.newpass_ = ui->lineEdit_new_password->text().toStdString();
    request.newpassconfirm_ = ui->lineEdit_confirm_password->text().toStdString();
    resetpasswordUseCase_->execute(request);

}

