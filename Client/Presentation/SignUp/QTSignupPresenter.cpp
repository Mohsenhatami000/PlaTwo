#include "QTSignupPresenter.h"
#include "QMessageBox"
#include "qstring.h"

QtSignupPresenter::QtSignupPresenter(SignUpPage *page):signupPage_(page)
{
}
void QtSignupPresenter::presentValidationError(std::string msg){
	QMessageBox::warning(signupPage_, "Validation Error", QString::fromStdString(msg));
}
void QtSignupPresenter::presentSignupFailure(std::string msg){
	QMessageBox::warning(signupPage_, "SignUp Failure", QString::fromStdString(msg));
}
void QtSignupPresenter::presentSignUpSuccess(){
	emit SignUpSucceed();
}
