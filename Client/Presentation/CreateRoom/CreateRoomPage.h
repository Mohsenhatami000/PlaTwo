#ifndef CREATEROOMPAGE_H
#define CREATEROOMPAGE_H
#include <QWidget>
#include "Application/UseCases/CreateRoom/CreateRoomUseCase.h"
#include "Domain/Enums/Enums.h"

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
    void backToMenuRequested();
    

private slots:
    void on_pushButton_back_clicked();
    void on_create_clicked();

private:
    Ui::CreateRoomPage *ui;
};


#endif // !CREATEROOMPAGE_H
