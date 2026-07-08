#include "qteditprofilepresenter.h"
#include "Presentation/EditProfile/ui_editprofilepage.h"
#include <QString>
#include <QMessageBox>

QtEditProfilePresenter::QtEditProfilePresenter(EditProfilePage *editProfilePage){
    editProfilePage_ = editProfilePage;
}

void QtEditProfilePresenter::LoadEditProfilePage(User user) const{
    editProfilePage_->getUiEditProfilePage()->lineEdit_name->setText(QString::fromStdString(user.uName().nameValue()));
    editProfilePage_->getUiEditProfilePage()->lineEdit_username->setText(QString::fromStdString(user.uUserName().userNameValue()));
    editProfilePage_->getUiEditProfilePage()->lineEdit_email->setText(QString::fromStdString(user.uEmail().emailValue()));
    editProfilePage_->getUiEditProfilePage()->lineEdit_phone_number->setText(QString::fromStdString(user.uPhoneNumber().phoneNumerValue()));
}

void QtEditProfilePresenter::presentValidationError(std::string msg){
    QMessageBox::warning(editProfilePage_, "Validation Error", QString::fromStdString(msg));
}

void QtEditProfilePresenter::presentEditSuccess(){
    emit saveChangesRequested();
}