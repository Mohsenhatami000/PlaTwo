#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H

#include <QWidget>

namespace Ui {
class MainMenuPage;
}

class MainMenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuPage(QWidget *parent = nullptr);
    ~MainMenuPage();
signals:
    void quitRequested();

private slots:
    void on_pushButton_quit_clicked();

private:
    Ui::MainMenuPage *ui;
};

#endif // MAINMENUPAGE_H
