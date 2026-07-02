#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginPage_ = new LoginPage(this);
    signUpPage_ = new SignUpPage(this);
    resetPasswordPage_ = new ResetPasswordPage(this);
    mainMenuPage_ = new MainMenuPage(this);
    editProfilePage_ = new EditProfilePage(this);
    gameMenuPage_ = new GameMenuPage(this);
    lobbyPage_ = new LobbyPage(this);


    ui->stackedWidget->addWidget(signUpPage_);
    ui->stackedWidget->addWidget(loginPage_);
    ui->stackedWidget->addWidget(resetPasswordPage_);
    ui->stackedWidget->addWidget(mainMenuPage_);
    ui->stackedWidget->addWidget(editProfilePage_);
    ui->stackedWidget->addWidget(gameMenuPage_);
    ui->stackedWidget->addWidget(lobbyPage_);

    ui->stackedWidget->setCurrentWidget(loginPage_);


    connect(loginPage_,
            &LoginPage::signUpRequested,
            this,
            &MainWindow::showSignupPage);

    connect(signUpPage_,
            &SignUpPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(signUpPage_,
            &SignUpPage::signUpRequested,
            this,
            &MainWindow::showLoginPage); // Must be edited later

    connect(loginPage_,
            &LoginPage::resetPasswordRequested,
            this,
            &MainWindow::showResetPasswordPage);

    connect(resetPasswordPage_,
            &ResetPasswordPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(resetPasswordPage_,
            &ResetPasswordPage::resetPasswordRequested,
            this,
            &MainWindow::showLoginPage); // Must be edited later

    connect(loginPage_,
            &LoginPage::mainMenuRequested,
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

    connect(editProfilePage_,
            &EditProfilePage::saveChangesRequested,
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

MainWindow::~MainWindow()
{
    delete ui;
}
