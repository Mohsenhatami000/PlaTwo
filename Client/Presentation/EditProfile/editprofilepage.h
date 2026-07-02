#ifndef EDITPROFILEPAGE_H
#define EDITPROFILEPAGE_H

#include <QWidget>

namespace Ui {
class EditProfilePage;
}

class EditProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit EditProfilePage(QWidget *parent = nullptr);
    ~EditProfilePage();

signals:
    void cancelRequested();
    void saveChangesRequested();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_save_changes_clicked();

private:
    Ui::EditProfilePage *ui;
};

#endif // EDITPROFILEPAGE_H
