#ifndef IWAITINGROOMPRESENTER_H
#define IWAITINGROOMPRESENTER_H
#include <string>
class IWaitingRoomPresenter
{
public:
	virtual ~IWaitingRoomPresenter() = default;
	virtual void presentValidationError(std::string msg) = 0;
	virtual void presentWaitingRoomFailure(std::string msg) = 0;
	virtual void presentWaitingRoomSuccess() = 0;

};

#endif // !IWAITINGROOMPRESENTER_H

