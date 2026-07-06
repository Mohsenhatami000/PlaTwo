#ifndef ILOGINPRESENTER_H
#define ILOGINPRESENTER_H

#include <string>
;class ILoginPresenter {
public:
    virtual ~ILoginPresenter() = default;
    virtual void presentValidationError(std::string msg) = 0;
    virtual void presentLoginFailure(std::string msg) = 0;
    virtual void presentLoginSuccess() = 0;
};

#endif // ILOGINPRESENTER_H
