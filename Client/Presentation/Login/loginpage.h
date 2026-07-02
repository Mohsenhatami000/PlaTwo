#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
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
