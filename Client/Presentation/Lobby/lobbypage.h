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

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::LobbyPage *ui;
};

#endif // LOBBYPAGE_H
