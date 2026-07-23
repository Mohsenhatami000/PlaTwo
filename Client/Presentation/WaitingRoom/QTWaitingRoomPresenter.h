#ifndef QTWAITINGROOMPRESENTER_H
#define QTWAITINGROOMPRESENTER_H
#include "Domain/Interfaces/Services/IWaitingRoomPresenter.h"
#include "WaitingRoomPage.h"
class QTWaitingRoomPresenter : public QObject, public IWaitingRoomPresenter
{
	Q_OBJECT
private:

	WaitingRoomPage* waitingRoomPage_;

public:
	QTWaitingRoomPresenter(WaitingRoomPage* page);
	void presentValidationError(std::string msg)  override;
	void presentWaitingRoomFailure(std::string msg)  override;
	void presentWaitingRoomSuccess() override;

signals:
	void waitingRoomSuccessed();
};
#endif // !QTWAITINGROOMPRESENTER_H

