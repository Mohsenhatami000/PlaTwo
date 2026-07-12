#ifndef RESETPASSWORDPAGE_H
#define RESETPASSWORDPAGE_H

#include <QWidget>
#include "Application/UseCases/ResetPassword/ResetPasswordUsecase.h"
#include "Application/DTO/Auth/ResetPasswordDTO.h"

namespace Ui {
class ResetPasswordPage;
}

class ResetPasswordPage : public QWidget
{
    Q_OBJECT
    ResetPasswordUsecase* resetpasswordUseCase_;
public:
    explicit ResetPasswordPage(QWidget *parent = nullptr);
    ~ResetPasswordPage();
    void setResetpasswordUsecase(ResetPasswordUsecase* usecase);

signals:
    void backToLoginRequested();
    void resetPasswordRequested();

private slots:

    void on_pushButton_back_clicked();

    void on_pushButton_reset_password_clicked();

private:
    Ui::ResetPasswordPage *ui;
};

#endif // RESETPASSWORDPAGE_H
