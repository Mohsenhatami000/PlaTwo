#ifndef QTJOINROOMPRESENTER_H
#define QTJOINROOMPRESENTER_H
#include <qobject.h>
#include "Domain/Interfaces/Services/IJoinRoomPresenter.h"
#include "JoinRoomPage.h"
class QTJoinRoomPresenter : public QObject, public IJoinRoomPresenter
{
	Q_OBJECT
private:

	JoinRoomPage* joinRoomPage_;

public:
	QTJoinRoomPresenter(JoinRoomPage* page);
	void presentValidationError(std::string msg)  override;
	void presentJoinRoomFailure(std::string msg)  override;
	void presentJoinRoomSuccess() override;

signals:
	void JoinRoomSuccessed();
};

#endif // !QRJOINROOMPRESENTER_H

