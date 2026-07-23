#ifndef WAITINGROOMPAGE_H
#define WAITINGROOMPAGE_H

#include <QWidget>
#include <QButtonGroup>
#include "Application/UseCases/WaitingRoom/WaitingRoomUseCase.h"

namespace Ui {
    class WaitingRoomPage;
}

class WaitingRoomPage : public QWidget
{
    Q_OBJECT
        WaitingRoomUseCase* waitingRoomUseCase_;


public:
    explicit WaitingRoomPage(QWidget* parent = nullptr);
    void setwaitingRoomUseCase(WaitingRoomUseCase* useCase);
    ~WaitingRoomPage();

//private signals:

    //void waitingRoomRequested();

//private slots:

   // void on_pushButton_go_clicked();

private:
    Ui::WaitingRoomPage* ui;

};

#endif // !WAITINGROOMPAGE_H

