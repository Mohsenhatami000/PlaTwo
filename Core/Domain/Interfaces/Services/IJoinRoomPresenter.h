#ifndef IJOINROOMPRESENTER_H
#define IJOINROOMPRESENTER_H
#include <string>
class IJoinRoomPresenter
{
public:
	virtual ~IJoinRoomPresenter() = default;
	virtual void presentValidationError(std::string msg) = 0;
	virtual void presentJoinRoomFailure(std::string msg) = 0;
	virtual void presentJoinRoomSuccess() = 0;

};

#endif // !IJOINROOMPRESENTER_H

