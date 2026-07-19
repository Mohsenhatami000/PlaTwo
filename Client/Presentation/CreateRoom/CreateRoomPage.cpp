#include "CreateRoomPage.h"
#include "ui_CreateRoomPage.h"

CreateRoomPage::CreateRoomPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::CreateRoomPage)

{

    ui->setupUi(this);
}

CreateRoomPage::~CreateRoomPage()
{
    delete ui;
}

void CreateRoomPage::setcreateRoomUseCase(CreateRoomUseCase* useCase) {
    createRoomUseCase_ = useCase;
}
void CreateRoomPage::on_pushButton_back_clicked() {
    emit backToMenuRequested();
}
void CreateRoomPage::on_create_clicked() {
    int width = ui->spinBox_width->value();
    int height = ui->spinBox_height->value();
    int timeLimit = ui->horizontalSlider_time->value();
    GameType gameType = static_cast<GameType>(ui->comboBox_type->currentData().toInt());
    if (createRoomUseCase_) {
        createRoomUseCase_->execute(width, height, timeLimit, gameType);
    }
}