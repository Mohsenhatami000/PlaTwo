#include "editprofilepage.h"
#include "ui_editprofilepage.h"

EditProfilePage::EditProfilePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditProfilePage)
{
    ui->setupUi(this);
}

EditProfilePage::~EditProfilePage()
{
    delete ui;
}

void EditProfilePage::on_pushButton_cancel_clicked()
{
    emit cancelRequested();
}


void EditProfilePage::on_pushButton_save_changes_clicked()
{
    emit saveChangesRequested();
}

