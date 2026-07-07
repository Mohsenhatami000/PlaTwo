#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H

#include <QWidget>
#include "Application/UseCases/EditProfile/loadeditprofileusecase.h"

namespace Ui {
class MainMenuPage;
}

class MainMenuPage : public QWidget
{
    Q_OBJECT
    LoadEditProfileUseCase *loadEditProfileUseCase_;

public:
    explicit MainMenuPage(QWidget *parent = nullptr);
    void setLoadEditProfileUseCase(LoadEditProfileUseCase *loadEditProfileUseCase);
    ~MainMenuPage();
signals:
    void quitRequested();
    void editProfileRequested();
    void dotsAndBoxesRequested();
    void nineMensMorrisRequested();
    void fanoronaRequested();

private slots:
    void on_pushButton_quit_clicked();

    void on_pushButton_edit_profile_clicked();

    void on_pushButton_dots_and_boxes_clicked();

    void on_pushButton_nine_mens_morris_clicked();

    void on_pushButton_fanorona_clicked();

private:
    Ui::MainMenuPage *ui;
};

#endif // MAINMENUPAGE_H
