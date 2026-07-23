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
#include "../CreateRoom/CreateRoomPage.h"
#include "../JoinRoom/JoinRoomPage.h"
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
#include "../ResetPassword/QTResetPasswordPresenter.h"
#include "Application/UseCases/ResetPassword/ResetPasswordUsecase.h"
#include "DataBase/databasemanager.h"
#include "Application/UseCases/CreateRoom/CreateRoomUseCase.h"
#include "../CreateRoom/QTCreateRoomPresenter.h"
#include "Domain/Interfaces/Services/ICreateRoomPresenter.h"
#include "Domain/Interfaces/Services/inetworkclient.h"
#include "Application/UseCases/JoinRoom/JoinRoomUseCase.h"
#include "../JoinRoom/QTJoinRoomPresenter.h"
#include "Domain/Interfaces/Services/IJoinRoomPresenter.h"
#include "Application/UseCases/WaitingRoom/WaitingRoomUseCase.h"
#include "../WaitingRoom/QTWaitingRoomPresenter.h"
#include "Domain/Interfaces/Services/IWaitingRoomPresenter.h"


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
    void showCreateRoomPage();
    void showJoinRoomPage();
    void showWaitingRoomPage();

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
    
    CreateRoomPage *createRoomPage_;

    CreateRoomUseCase* createRoomUsecase_;

    QTCreateRoomPresenter* qtCreateRoomPresenter_;

    ICreateRoomPresenter* createRoomPresenter_;

    JoinRoomPage* joinRoomPage_;

    JoinRoomUseCase* joinRoomUseCase_;

    QTJoinRoomPresenter* qtJoinRoompresenter_;

    IJoinRoomPresenter* joinRoomPresenter_;
    
    IUserRepository *userRepo_;

    DatabaseManager *db_;
    
    ILoginPresenter *loginPresenter_;

    QtLoginPresenter *qtLoginPresenter_;

    LoginUseCase *loginUseCase_;
     
    ISignupPresenter *signupPresenter_;
    
    QtSignupPresenter *qtSignupPresenter_;

    SignupUseCase *signupUseCase_;
    
    IResetPasswordPresenter *resetpasswordPresenter_;

    QTResetPasswordPresenter* qtResetpasswordPresenter_;

    ResetPasswordUsecase* resetpasswordUsecase_;

    IHasher *hasher_;

    ISessionContext *session_;

    INetworkClient* networkclient_;

    WaitingRoomPage  *waitingRoomPage_;

    WaitingRoomUseCase *waitingRoomUseCase_;

    QTWaitingRoomPresenter* qtWaitingRoomPresenter_;

    IWaitingRoomPresenter* waitingRoomPresenter_;
};

#endif // MAINWINDOW_H
