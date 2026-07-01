#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginPage = new LoginPage(this);
    signUpPage = new SignUp(this);
    resetPasswordPage = new ResetPasswordPage(this);

    ui->stackedWidget->addWidget(signUpPage);
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(resetPasswordPage);

    ui->stackedWidget->setCurrentWidget(loginPage);


    connect(loginPage,
            &LoginPage::signUpRequested,
            this,
            &MainWindow::showSignupPage);

    connect(signUpPage,
            &SignUp::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

    connect(loginPage,
            &LoginPage::resetPasswordRequested,
            this,
            &MainWindow::showResetPasswordPage);

    connect(resetPasswordPage,
            &ResetPasswordPage::backToLoginRequested,
            this,
            &MainWindow::showLoginPage);

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

MainWindow::~MainWindow()
{
    delete ui;
}
