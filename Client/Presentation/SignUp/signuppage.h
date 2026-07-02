#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUpPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

signals:
    void backToLoginRequested();
    void signUpRequested();

private slots:
    void on_pushButton_back_clicked();

    void on_signup_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUPPAGE_H
