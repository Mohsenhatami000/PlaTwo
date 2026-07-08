#ifndef QTRESETPASSWORDPRESENTER_H
#define QTRESETPASSWORDPRESENTER_H
#include <qobject.h>
#include "Domain/Interfaces/Services/IResetPasswordPresenter.h"
#include "../ResetPassword/resetpasswordpage.h"

class QTResetPasswordPresenter : public QObject, public IResetPasswordPresenter
{
private:
    Q_OBJECT
    ResetPasswordPage* resetpasswordPage_;
public:
    QTResetPasswordPresenter(ResetPasswordPage* page);
    void presentValidationError(std::string msg) override;
    void presentResetPasswordFailure(std::string msg) override;
    void presentResetPasswordSuccess() override;

signals:
    void ResetpasswordSucceed();
};

#endif // !QTRESETPASSWORDPRESENTER_H