#ifndef CREATEROOMPAGE_H
#define CREATEROOMPAGE_H
#include <QWidget>
#include "Application/UseCases/CreateRoom/CreateRoomUseCase.h"


namespace Ui {
    class CreateRoomPage;
}

class CreateRoomPage : public QWidget
{
    Q_OBJECT
    CreateRoomUseCase* createRoomUseCase_;


public:
    explicit CreateRoomPage(QWidget* parent = nullptr);
    void setcreateRoomUseCase(CreateRoomUseCase* useCase);
    ~CreateRoomPage();

signals:
    void backToLobbyRequested();
    

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_create_clicked();

    void on_checkBox_time_limit_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::CreateRoomPage *ui;
};


#endif // !CREATEROOMPAGE_H
