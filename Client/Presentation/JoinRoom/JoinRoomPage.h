#ifndef JOINROOMPAGE_H
#define JOINROOMPAGE_H
#include <QWidget>
#include "Application/UseCases/JoinRoom/JoinRoomUseCase.h"
#include "Domain/Enums/Enums.h"

namespace Ui {
    class JoinRoomPage;
}

class JoinRoomPage : public QWidget
{
    Q_OBJECT
        JoinRoomUseCase* joinRoomUseCase_;


public:
    explicit JoinRoomPage(QWidget* parent = nullptr);
    void setjoinRoomUseCase(JoinRoomUseCase* useCase);
    ~JoinRoomPage();

signals:
    void backToMenuRequested();
    

private slots:
    void on_pushButton_back_clicked();
    void on_join_clicked();

private:
    Ui::JoinRoomPage* ui;
};

#endif // !JOINROOMPAGE_H

