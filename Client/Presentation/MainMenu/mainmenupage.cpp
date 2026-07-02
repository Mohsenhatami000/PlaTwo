#include "mainmenupage.h"
#include "ui_mainmenupage.h"

MainMenuPage::MainMenuPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuPage)
{
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
}


void MainMenuPage::on_pushButton_dots_and_boxes_clicked()
{
    emit dotsAndBoxesRequested();
}


void MainMenuPage::on_pushButton_nine_mens_morris_clicked()
{
    emit nineMensMorrisRequested();
}


void MainMenuPage::on_pushButton_fanorona_clicked()
{
    emit fanoronaRequested();
}

