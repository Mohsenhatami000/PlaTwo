#include "QTJoinRoomPresenter.h"
#include <QString>
#include <QMessageBox>

QTJoinRoomPresenter::QTJoinRoomPresenter(JoinRoomPage* page) :joinRoomPage_(page) {

}
void QTJoinRoomPresenter::presentValidationError(std::string msg) {
	QMessageBox::warning(joinRoomPage_, "Validation Error", QString::fromStdString(msg));
}
void QTJoinRoomPresenter::presentJoinRoomFailure(std::string msg) {
	QMessageBox::warning(joinRoomPage_, "Join Room Failure", QString::fromStdString(msg));
}
void QTJoinRoomPresenter::presentJoinRoomSuccess() {
	emit JoinRoomSuccessed();
}