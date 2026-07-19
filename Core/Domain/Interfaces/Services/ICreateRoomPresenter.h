#ifndef ICREATEROOMPRESENTER_H
#define ICREATEROOMPRESENTER_H
#include <string>
class ICreateRoomPresenter
{
public:
	virtual ~ICreateRoomPresenter() = default;
	virtual void presentValidationError(std::string msg) = 0;
	virtual void presentCreateRoomFailure(std::string msg) = 0;
	virtual void presentCreateRoomSuccess() = 0;

};

#endif // !ICREATEROOMPRESENTER-H
