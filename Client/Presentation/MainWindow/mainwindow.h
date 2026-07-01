#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Login/loginpage.h"
#include "../SignUp/signuppage.h"
#include "../ResetPassword/resetpasswordpage.h"
#include "../MainMenu/mainmenupage.h"
#include "../EditProfile/editprofilepage.h"
#include "../GameMenu/gamemenupage.h"
#include "../Lobby/lobbypage.h"


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
    void showEditProfilePage();
    void showGameMenuPage();
    void showLobbyPage();

private:

    Ui::MainWindow *ui;

    LoginPage *loginPage;

    SignUpPage *signUpPage;

    ResetPasswordPage *resetPasswordPage;

    MainMenuPage *mainMenuPage;

    EditProfilePage *editProfilePage;

    GameMenuPage *gameMenuPage;

    LobbyPage *lobbyPage;
};

#endif // MAINWINDOW_H
