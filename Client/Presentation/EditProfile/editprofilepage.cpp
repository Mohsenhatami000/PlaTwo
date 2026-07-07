#include "editprofilepage.h"
#include "Application/DTO/Auth/EditProfileRequest.h"
#include "ui_editprofilepage.h"


EditProfilePage::EditProfilePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditProfilePage)
{
    ui->setupUi(this);
}

EditProfilePage::~EditProfilePage()
{
    delete ui;
}

void EditProfilePage::on_pushButton_cancel_clicked()
{
    emit cancelRequested();
}


void EditProfilePage::on_pushButton_save_changes_clicked()
{
    EditProfileRequest request;
    request.name_ = (ui->lineEdit_name->text()).toStdString();
    request.username_ = (ui->lineEdit_username->text()).toStdString();
    request.email_ = (ui->lineEdit_email->text()).toStdString();
    request.phoneNumber_ = (ui->lineEdit_phone_number->text()).toStdString();
    request.currentPassword_ = (ui->lineEdit_current_password->text()).toStdString();
    request.newPassword_ = (ui->lineEdit_new_password->text()).toStdString();
    request.confirmPassword_ = (ui->lineEdit_confirm_new_password->text()).toStdString();

    editProfileUseCase_->execute(request);
}

Ui::EditProfilePage* EditProfilePage::getUiEditProfilePage(){
    return ui;
}

void EditProfilePage::setEditProfileUseCase(EditProfileUseCase *editProfileUseCase){
    editProfileUseCase_ = editProfileUseCase;
}