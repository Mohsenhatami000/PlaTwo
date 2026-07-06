#include "QtLoginpresenter.h"
#include "QMessageBox"
#include "qstring.h"

QtLoginPresenter::QtLoginPresenter(LoginPage *loginPage){
    loginPage_ = loginPage;
}

void QtLoginPresenter::presentValidationError(std::string msg){
    QMessageBox::warning(loginPage_, "Validation Error", QString::fromStdString(msg));
};

void QtLoginPresenter::presentLoginFailure(std::string msg){
    QMessageBox::warning(loginPage_, "Login Failure", QString::fromStdString(msg));
};

void QtLoginPresenter::presentLoginSuccess(){
    emit LoginSucceed();
};

