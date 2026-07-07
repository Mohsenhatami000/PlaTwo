#ifndef QTSIGNUPPRESENTER_H
#define QTSIGNUPPRESENTER_H

#include <qobject.h>
#include "Domain/Interfaces/Services/ISignupPresenter.h"
#include "../SignUp/signuppage.h"

class QtSignupPresenter : public QObject , public ISignupPresenter
{
	Q_OBJECT
	SignUpPage *signupPage_;

public:
    QtSignupPresenter(SignUpPage *page);
    void presentValidationError(std::string msg) override;
    void presentSignupFailure(std::string msg) override;
    void presentSignUpSuccess() override;

signals:
    void SignUpSucceed();
};

#endif 