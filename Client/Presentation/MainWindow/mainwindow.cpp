#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginPage = new LoginPage(this);
    signUpPage = new SignUpPage(this);
    resetPasswordPage = new ResetPasswordPage(this);
    mainMenuPage = new MainMenuPage(this);
    editProfilePage = new EditProfilePage(this);
    gameMenuPage = new GameMenuPage(this);
    lobbyPage = new LobbyPage(this);


    ui->stackedWidget->addWidget(signUpPage);
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(resetPasswordPage);
    ui->stackedWidget->addWidget(mainMenuPage);
    ui->stackedWidget->addWidget(editProfilePage);
    ui->stackedWidget->addWidget(gameMenuPage);
    ui->stackedWidget->addWidget(lobbyPage);

    ui->stackedWidget->setCurrentWidget(loginPage);


    connect(loginPage,
            &LoginPage::signUpRequested,
            this,
            &MainWindow::showSignupPage);

    connect(signUpPage,
            &SignUpPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(signUpPage,
            &SignUpPage::signUpRequested,
            this,
            &MainWindow::showLoginPage); // Must be edited later

    connect(loginPage,
            &LoginPage::resetPasswordRequested,
            this,
            &MainWindow::showResetPasswordPage);

    connect(resetPasswordPage,
            &ResetPasswordPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(resetPasswordPage,
            &ResetPasswordPage::resetPasswordRequested,
            this,
            &MainWindow::showLoginPage); // Must be edited later

    connect(loginPage,
            &LoginPage::mainMenuRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(mainMenuPage,
            &MainMenuPage::quitRequested,
            this,
            &MainWindow::close);

    connect(mainMenuPage,
            &MainMenuPage::editProfileRequested,
            this,
            &MainWindow::showEditProfilePage);

    connect(editProfilePage,
            &EditProfilePage::cancelRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(editProfilePage,
            &EditProfilePage::saveChangesRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(mainMenuPage,
            &MainMenuPage::dotsAndBoxesRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(mainMenuPage,
            &MainMenuPage::nineMensMorrisRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(mainMenuPage,
            &MainMenuPage::fanoronaRequested,
            this,
            &MainWindow::showGameMenuPage);

    connect(gameMenuPage,
            &GameMenuPage::backToMainMenuRequested,
            this,
            &MainWindow::showMainMenuPage);

    connect(gameMenuPage,
            &GameMenuPage::startNewGameRequested,
            this,
            &MainWindow::showLobbyPage);

    connect(lobbyPage,
            &LobbyPage::backToGameMenuRequested,
            this,
            &MainWindow::showGameMenuPage);
}

void MainWindow::showSignupPage(){
    ui->stackedWidget->setCurrentWidget(signUpPage);

}

void MainWindow::showLoginPage(){
    ui->stackedWidget->setCurrentWidget(loginPage);
}

void MainWindow::showResetPasswordPage(){
    ui->stackedWidget->setCurrentWidget(resetPasswordPage);
}

void MainWindow::showMainMenuPage(){
    ui->stackedWidget->setCurrentWidget(mainMenuPage);
}

void MainWindow::showEditProfilePage(){
    ui->stackedWidget->setCurrentWidget(editProfilePage);
}

void MainWindow::showGameMenuPage(){
    ui->stackedWidget->setCurrentWidget(gameMenuPage);
}

void MainWindow::showLobbyPage(){
    ui->stackedWidget->setCurrentWidget(lobbyPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
