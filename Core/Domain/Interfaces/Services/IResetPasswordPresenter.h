#ifndef IRESETPASSWORDPRESENTER_H
#define IRESETPASSWORDPRESENTER_H
#include <string>
class IResetPasswordPresenter
{
public:
	virtual ~IResetPasswordPresenter() = default;
	virtual void presentValidationError(std::string msg) = 0;
	virtual void presentResetPasswordFailure(std::string msg) = 0;
	virtual void presentResetPasswordSuccess() = 0;

};
#endif // !IRESETPASSWORDPRESEBTER_H
