#include "JoinRoomPage.h"
#include "ui_JoinRoomPage.h"

JoinRoomPage::JoinRoomPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::JoinRoomPage)

{

    ui->setupUi(this);
}

JoinRoomPage::~JoinRoomPage()
{
    delete ui;
}

void JoinRoomPage::setjoinRoomUseCase(JoinRoomUseCase* useCase) {
    joinRoomUseCase_ = useCase;
}
void JoinRoomPage::on_pushButton_back_clicked() {
    emit backToMenuRequested();
}

void JoinRoomPage::on_pushButton_join_clicked()
{
    std::string ip = ui->lineEdit_ip->text().toStdString();
    std::int64_t port = ui->lineEdit_port->text().toLongLong();
    std::int64_t roomID = ui->lineEdit_room_id->text().toLongLong();

    joinRoomUseCase_->execute(ip, port, roomID);

}

