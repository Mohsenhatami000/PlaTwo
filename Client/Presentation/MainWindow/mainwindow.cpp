#include "mainwindow.h"
#include "Presentation/MainWindow/ui_mainwindow.h"
#include "../Login/QtLoginpresenter.h"
#include "Encryption/Argon2ID.h"
#include "Repository/sqliteuserrepository.h"
#include "sessioncontext.h"
#include "../Infrastructure/Network/Client/qtcpnetworkclient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db_ = new DatabaseManager;
    db_->initialize();
    userRepo_ = new SQLiteUserRepository(db_->database());

    hasher_ = new Argon2ID();
    session_ = new SessionContext;
    signUpPage_ = new SignUpPage(this);
    resetPasswordPage_ = new ResetPasswordPage(this);
    loginPage_ = new LoginPage(this);
    mainMenuPage_ = new MainMenuPage(session_, this);
    editProfilePage_ = new EditProfilePage(this);
    createRoomPage_ = new CreateRoomPage(this);
    networkclient_ = new QTcpNetworkClient(this);
    joinRoomPage_ = new JoinRoomPage(this);
    waitingRoomPage_ = new WaitingRoomPage(this);

    qtLoginPresenter_ = new QtLoginPresenter(loginPage_);
    loginPresenter_ = qtLoginPresenter_;
    loginUseCase_ = new LoginUseCase(userRepo_, loginPresenter_, hasher_, session_);
    loginPage_->setLoginUseCase(loginUseCase_);


    qtEditProfilePresenter_ = new QtEditProfilePresenter(editProfilePage_);
    editProfilePresenter_ = qtEditProfilePresenter_;
    loadEditProfileUseCase_ = new LoadEditProfileUseCase(userRepo_, editProfilePresenter_, session_);
    mainMenuPage_->setLoadEditProfileUseCase(loadEditProfileUseCase_);
    editProfileUseCase_ = new EditProfileUseCase(userRepo_, editProfilePresenter_, session_, hasher_);
    editProfilePage_->setEditProfileUseCase(editProfileUseCase_);

    gameMenuPage_ = new GameMenuPage(this);
    lobbyPage_ = new LobbyPage(this);

    qtSignupPresenter_ = new QtSignupPresenter(signUpPage_);
    signupPresenter_ = qtSignupPresenter_;
    signupUseCase_ = new SignupUseCase(userRepo_, hasher_, signupPresenter_);
    signUpPage_->setSignupUsecase(signupUseCase_);

    qtResetpasswordPresenter_ = new QTResetPasswordPresenter(resetPasswordPage_);
    resetpasswordPresenter_ = qtResetpasswordPresenter_;
    resetpasswordUsecase_ = new ResetPasswordUsecase(userRepo_, hasher_, resetpasswordPresenter_);
    resetPasswordPage_->setResetpasswordUsecase(resetpasswordUsecase_);

    qtCreateRoomPresenter_ = new QTCreateRoomPresenter(createRoomPage_);
    createRoomPresenter_ = qtCreateRoomPresenter_;
    createRoomUsecase_ = new CreateRoomUseCase(createRoomPresenter_, networkclient_, session_);
    createRoomPage_->setcreateRoomUseCase(createRoomUsecase_);

    qtJoinRoompresenter_ = new QTJoinRoomPresenter(joinRoomPage_);
    joinRoomPresenter_ = qtJoinRoompresenter_;
    joinRoomUseCase_ = new JoinRoomUseCase(joinRoomPresenter_,networkclient_,session_);
    joinRoomPage_->setjoinRoomUseCase(joinRoomUseCase_);

    qtWaitingRoomPresenter_ = new QTWaitingRoomPresenter(waitingRoomPage_);
    waitingRoomPresenter_ = qtWaitingRoomPresenter_;
    waitingRoomUseCase_ = new WaitingRoomUseCase(waitingRoomPresenter_, networkclient_, session_);
    waitingRoomPage_->setwaitingRoomUseCase(waitingRoomUseCase_);

    ui->stackedWidget->addWidget(signUpPage_);
    ui->stackedWidget->addWidget(loginPage_);
    ui->stackedWidget->addWidget(resetPasswordPage_);
    ui->stackedWidget->addWidget(mainMenuPage_);
    ui->stackedWidget->addWidget(editProfilePage_);
    ui->stackedWidget->addWidget(gameMenuPage_);
    ui->stackedWidget->addWidget(lobbyPage_);
    ui->stackedWidget->addWidget(createRoomPage_);
    ui->stackedWidget->addWidget(joinRoomPage_);
    ui->stackedWidget->addWidget(waitingRoomPage_);
    ui->stackedWidget->setCurrentWidget(loginPage_);


    connect(loginPage_,
            &LoginPage::signUpRequested,
            this,
            &MainWindow::showSignupPage);

    connect(signUpPage_,
            &SignUpPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(qtSignupPresenter_,
            &QtSignupPresenter::SignUpSucceed,
            this,
            &MainWindow::showLoginPage);

    connect(loginPage_,
            &LoginPage::resetPasswordRequested,
            this,
            &MainWindow::showResetPasswordPage);

    connect(resetPasswordPage_,
            &ResetPasswordPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(qtResetpasswordPresenter_,
            &QTResetPasswordPresenter::ResetpasswordSucceed,
            this,
            &MainWindow::showLoginPage);

    connect(qtLoginPresenter_,
            &QtLoginPresenter::LoginSucceed,
            this,
            &MainWindow::showMainMenuPage);

    connect(mainMenuPage_,
            &MainMenuPage::quitRequested,
            this,
            &MainWindow::close);

    connect(mainMenuPage_,
            &MainMenuPage::editProfileRequested,
            this,
            &MainWindow::showEditProfilePage);

    connect(editProfilePage_,
            &EditProfilePage::cancelRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(qtEditProfilePresenter_,
            &QtEditProfilePresenter::saveChangesRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(mainMenuPage_,
            &MainMenuPage::dotsAndBoxesRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(mainMenuPage_,
            &MainMenuPage::nineMensMorrisRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(mainMenuPage_,
            &MainMenuPage::fanoronaRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(gameMenuPage_,
            &GameMenuPage::backToMainMenuRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(gameMenuPage_,
            &GameMenuPage::startNewGameRequested,
            this,
            &MainWindow::showLobbyPage);

    connect(lobbyPage_,
            &LobbyPage::backToGameMenuRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(lobbyPage_, &LobbyPage::createRoomRequested,
        this, &MainWindow::showCreateRoomPage);

    connect(createRoomPage_, &CreateRoomPage::backToLobbyRequested,
        this, &MainWindow::showLobbyPage);

    connect(lobbyPage_, &LobbyPage::joinRoomRequested,
        this, &MainWindow::showJoinRoomPage);

    connect(joinRoomPage_, &JoinRoomPage::backToMenuRequested,
        this, &MainWindow::showLobbyPage);
    
    connect(qtCreateRoomPresenter_, &QTCreateRoomPresenter::createRoomSuccessed, 
        this, &MainWindow::showWaitingRoomPage);

    connect(qtJoinRoompresenter_, &QTJoinRoomPresenter::JoinRoomSuccessed,
        this, &MainWindow::showWaitingRoomPage);

}

void MainWindow::showSignupPage(){
    ui->stackedWidget->setCurrentWidget(signUpPage_);

}

void MainWindow::showLoginPage(){
    ui->stackedWidget->setCurrentWidget(loginPage_);
}

void MainWindow::showResetPasswordPage(){
    ui->stackedWidget->setCurrentWidget(resetPasswordPage_);
}

void MainWindow::showMainMenuPage(){
    ui->stackedWidget->setCurrentWidget(mainMenuPage_);
}

void MainWindow::showEditProfilePage(){
    ui->stackedWidget->setCurrentWidget(editProfilePage_);

}

void MainWindow::showGameMenuPage(){
    ui->stackedWidget->setCurrentWidget(gameMenuPage_);
}

void MainWindow::showLobbyPage(){
    ui->stackedWidget->setCurrentWidget(lobbyPage_);
}

void MainWindow::showCreateRoomPage() {
    ui->stackedWidget->setCurrentWidget(createRoomPage_);
}

void MainWindow::showJoinRoomPage() {
    ui->stackedWidget->setCurrentWidget(joinRoomPage_);
}

void MainWindow::showWaitingRoomPage() {
    ui->stackedWidget->setCurrentWidget(waitingRoomPage_);
}

MainWindow::~MainWindow()
{
    delete ui;
    db_->database().close();
}
