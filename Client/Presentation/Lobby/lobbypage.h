#ifndef LOBBYPAGE_H
#define LOBBYPAGE_H

#include <QWidget>

namespace Ui {
class LobbyPage;
}

class LobbyPage : public QWidget
{
    Q_OBJECT

public:
    explicit LobbyPage(QWidget *parent = nullptr);
    ~LobbyPage();

signals:
    void backToGameMenuRequested();
    void createRoomRequested();
    void joinRoomRequested();

private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_create_room_clicked();
    void on_pushButton_join_room_clicked();

private:
    Ui::LobbyPage *ui;
};

#endif // LOBBYPAGE_H
