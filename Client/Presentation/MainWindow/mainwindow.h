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
#include "Domain/Interfaces/Repositories/IUserRepository.h"
#include "Domain/Interfaces/Services/iloginpresenter.h"
#include "../Login/QtLoginpresenter.h"
#include "Application/UseCases/Login/loginusecase.h"
#include "Domain/Interfaces/Services/IHasher.h"
#include "Domain/Interfaces/Services/isessioncontext.h"
#include "Application/UseCases/EditProfile/loadeditprofileusecase.h"
#include "Domain/Interfaces/Services/ieditprofilepresenter.h"
#include "../EditProfile/qteditprofilepresenter.h"
#include "Application/UseCases/EditProfile/editprofileusecase.h"
#include "../SignUp/QTSignupPresenter.h"
#include "Application/UseCases/SignUp/SignUpUseCase.h"
#include "Domain/Interfaces/Services/ISignupPresenter.h"

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

    LoginPage *loginPage_;

    SignUpPage *signUpPage_;

    ResetPasswordPage *resetPasswordPage_;

    MainMenuPage *mainMenuPage_;


    EditProfilePage *editProfilePage_;

    LoadEditProfileUseCase *loadEditProfileUseCase_;

    IEditProfilePresenter *editProfilePresenter_;

    QtEditProfilePresenter *qtEditProfilePresenter_;

    EditProfileUseCase *editProfileUseCase_;

    GameMenuPage *gameMenuPage_;

    LobbyPage *lobbyPage_;

    IUserRepository *userRepo_;

    ILoginPresenter *loginPresenter_;

    QtLoginPresenter *qtLoginPresenter_;

    LoginUseCase *loginUseCase_;
     
    ISignupPresenter *signupPresenter_;

    QtSignupPresenter *qtSignupPresenter_;

    SignupUseCase*signupUseCase_;

    IHasher *hasher_;

    ISessionContext *session_;

};

#endif // MAINWINDOW_H
