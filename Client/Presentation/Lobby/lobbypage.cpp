#include "lobbypage.h"
#include "ui_lobbypage.h"

LobbyPage::LobbyPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LobbyPage)
{
    ui->setupUi(this);
}

LobbyPage::~LobbyPage()
{
    delete ui;
}

void LobbyPage::on_pushButton_back_clicked()
{
    emit backToGameMenuRequested();
}

