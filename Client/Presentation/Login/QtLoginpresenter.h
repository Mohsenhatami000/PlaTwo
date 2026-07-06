#ifndef QTLOGINPRESENTER_H
#define QTLOGINPRESENTER_H

#include "Domain/Interfaces/Services/iloginpresenter.h"
#include "../Login/loginpage.h"
#include <qobject.h>

class QtLoginPresenter : public QObject, public ILoginPresenter
{
    Q_OBJECT
    LoginPage *loginPage_;

public:
    QtLoginPresenter(LoginPage *loginPage);
    void presentValidationError(std::string msg) override;
    void presentLoginFailure(std::string msg) override;
    void presentLoginSuccess() override;
signals:
    void LoginSucceed();
};

#endif // QTLOGINPRESENTER_H
