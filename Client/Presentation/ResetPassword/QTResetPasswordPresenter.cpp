#include "QTResetPasswordPresenter.h"
#include "QMessageBox"
#include "qstring.h"

QTResetPasswordPresenter::QTResetPasswordPresenter(ResetPasswordPage *page) {
	resetpasswordPage_ = page;
}
void QTResetPasswordPresenter::presentValidationError(std::string msg) {
    QMessageBox::warning(resetpasswordPage_, "Validation Error", QString::fromStdString(msg));
}
void QTResetPasswordPresenter::presentResetPasswordFailure(std::string msg) {
    QMessageBox::warning(resetpasswordPage_, "Reset password Failure", QString::fromStdString(msg));
}
void QTResetPasswordPresenter::presentResetPasswordSuccess() {
    emit ResetpasswordSucceed();
}