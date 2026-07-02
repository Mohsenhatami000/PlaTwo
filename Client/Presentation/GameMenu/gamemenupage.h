#ifndef GAMEMENUPAGE_H
#define GAMEMENUPAGE_H

#include <QWidget>

namespace Ui {
class GameMenuPage;
}

class GameMenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit GameMenuPage(QWidget *parent = nullptr);
    ~GameMenuPage();

signals:
    void backToMainMenuRequested();
    void startNewGameRequested();

private slots:

    void on_pushButton_back_clicked();

    void on_pushButton_start_new_game_clicked();

private:
    Ui::GameMenuPage *ui;
};

#endif // GAMEMENUPAGE_H
