#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Login/loginpage.h"
#include "../SignUp/signuppage.h"
#include "../ResetPassword/resetpasswordpage.h"
#include "../MainMenu/mainmenupage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void showSignupPage();
    void showLoginPage();
    void showResetPasswordPage();
    void showMainMenuPage();

private:

    Ui::MainWindow *ui;

    LoginPage *loginPage;

    SignUp *signUpPage;

    ResetPasswordPage *resetPasswordPage;

    MainMenuPage *mainMenuPage;
};

#endif // MAINWINDOW_H
