#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <Application/UseCases/Login/loginusecase.h>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT
    LoginUseCase *loginUseCase_;

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    void setLoginUseCase(LoginUseCase *loginUseCase);

signals:
    void signUpRequested();
    void resetPasswordRequested();
    void mainMenuRequested();

private slots:

    void on_pushButton_sSignUp_clicked();

    void on_pushButton_ForgotPassword_clicked();

    void on_pushButton_Login_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H