#ifndef ISIGNUPPRESENTER_H
#define ISIGNUPPRESENTER_H
#include <string>
class ISignupPresenter
{
public:
	virtual ~ISignupPresenter() = default;
	virtual void presentValidationError(std::string msg) = 0;
	virtual void presentSignupFailure(std::string msg) = 0;
	virtual void presentSignUpSuccess() = 0;

};

#endif // ISIGNUPPRESENTER_H
