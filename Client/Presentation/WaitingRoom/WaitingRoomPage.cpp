#include "WaitingRoomPage.h"
#include "ui_WaitingRoomPage.h"

WaitingRoomPage::WaitingRoomPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::WaitingRoomPage)

{
   
    ui->setupUi(this);
    std::string color = ui->comboBox_color->currentText().toStdString();
    //waitingRoomUseCase_->execute(color);
}

WaitingRoomPage::~WaitingRoomPage()
{
    delete ui;
}

void WaitingRoomPage::setwaitingRoomUseCase(WaitingRoomUseCase* useCase) {
    waitingRoomUseCase_ = useCase;
}


