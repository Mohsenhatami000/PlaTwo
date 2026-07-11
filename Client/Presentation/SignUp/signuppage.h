#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include "Application/UseCases/SignUp/SignUpUseCase.h"
#include "Application/DTO/Auth/SignUpDTO.h"
namespace Ui {
class SignUp;
}

class SignUpPage : public QWidget
{
    Q_OBJECT
    SignupUseCase *signupUsecase_;

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();
    void setSignupUsecase(SignupUseCase *usecase);

signals:
    void backToLoginRequested();

private slots:
    void on_pushButton_back_clicked();
    void on_signup_clicked();

private:
    Ui::SignUp *ui;

};

#endif // SIGNUPPAGE_H
