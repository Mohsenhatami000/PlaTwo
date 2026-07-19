#ifndef QTCREATEROOMPRESENTER_H
#define QTCREATEROOMPRESENTER_H
#include <qobject.h>
#include "Domain/Interfaces/Services/ICreateRoomPresenter.h"
#include "CreateRoomPage.h"
class QTCreateRoomPresenter : public QObject, public ICreateRoomPresenter
{
	Q_OBJECT
private:
	
	CreateRoomPage* createRoomPage_;

public:
	QTCreateRoomPresenter(CreateRoomPage* page);
	void presentValidationError(std::string msg)  override;
	void presentCreateRoomFailure(std::string msg)  override;
	void presentCreateRoomSuccess() override;

signals:
	void createRoomSuccessed();
};

#endif // !QRCREATEROOMPRESENTER_H