#include "CreateRoomPage.h"
#include "Presentation/CreateRoom/ui_CreateRoomPage.h"

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
    emit backToLobbyRequested();
}

void CreateRoomPage::on_pushButton_create_clicked()
{
    int width = ui->spinBox_width->value();
    int height = ui->spinBox_height->value();
    int timeLimit;
    if(ui->checkBox_time_limit->isChecked()){
        timeLimit = ui->spinBox_time->value();
    }
    else{
        timeLimit = 0;
    }

    createRoomUseCase_->execute(width, height, timeLimit);

}


void CreateRoomPage::on_checkBox_time_limit_checkStateChanged(const Qt::CheckState &arg1)
{
    ui->spinBox_time->setEnabled(arg1);
}

