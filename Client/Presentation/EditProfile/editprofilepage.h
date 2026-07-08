#ifndef EDITPROFILEPAGE_H
#define EDITPROFILEPAGE_H

#include <QWidget>
#include "Application/UseCases/EditProfile/editprofileusecase.h"


namespace Ui {
class EditProfilePage;
}

class EditProfilePage : public QWidget
{
    Q_OBJECT
    EditProfileUseCase *editProfileUseCase_;


public:
    explicit EditProfilePage(QWidget *parent = nullptr);
    Ui::EditProfilePage* getUiEditProfilePage();
    void setEditProfileUseCase(EditProfileUseCase *editProfileUseCase);
    ~EditProfilePage();

signals:
    void cancelRequested();

private slots:
    void on_pushButton_cancel_clicked();
    void on_pushButton_save_changes_clicked();

private:
    Ui::EditProfilePage *ui;
};

#endif // EDITPROFILEPAGE_H
