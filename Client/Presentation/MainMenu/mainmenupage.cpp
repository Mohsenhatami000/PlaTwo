#include "mainmenupage.h"
#include "ui_mainmenupage.h"

MainMenuPage::MainMenuPage(ISessionContext *session, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuPage)
{
    session_ = session;
    ui->setupUi(this);
}

MainMenuPage::~MainMenuPage()
{
    delete ui;
}

void MainMenuPage::on_pushButton_quit_clicked()
{
    emit quitRequested();
}


void MainMenuPage::on_pushButton_edit_profile_clicked()
{
    emit editProfileRequested();
    loadEditProfileUseCase_->execute();
}


void MainMenuPage::on_pushButton_dots_and_boxes_clicked()
{
    session_->setGameType(GameType::DotsAndBoxes);
    emit dotsAndBoxesRequested();
}


void MainMenuPage::on_pushButton_nine_mens_morris_clicked()
{
    session_->setGameType(GameType::Mills);
    emit nineMensMorrisRequested();
}


void MainMenuPage::on_pushButton_fanorona_clicked()
{
    session_->setGameType(GameType::Fanorona);
    emit fanoronaRequested();
}

void MainMenuPage::setLoadEditProfileUseCase(LoadEditProfileUseCase *loadEditProfileUseCase){
    loadEditProfileUseCase_ = loadEditProfileUseCase;
}