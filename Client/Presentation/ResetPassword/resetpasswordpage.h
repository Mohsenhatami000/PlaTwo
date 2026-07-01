#ifndef RESETPASSWORDPAGE_H
#define RESETPASSWORDPAGE_H

#include <QWidget>

namespace Ui {
class ResetPasswordPage;
}

class ResetPasswordPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPasswordPage(QWidget *parent = nullptr);
    ~ResetPasswordPage();

signals:
    void backToLoginRequested();
    void resetPasswordRequested();

private slots:

    void on_pushButton_back_clicked();

    void on_pushButton_reset_password_clicked();

private:
    Ui::ResetPasswordPage *ui;
};

#endif // RESETPASSWORDPAGE_H
