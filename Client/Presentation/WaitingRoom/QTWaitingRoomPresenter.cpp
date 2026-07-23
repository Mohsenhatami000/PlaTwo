#include "QTWaitingRoomPresenter.h"
#include <QString>
#include <QMessageBox>

QTWaitingRoomPresenter::QTWaitingRoomPresenter(WaitingRoomPage* page) :waitingRoomPage_(page) {

}
void QTWaitingRoomPresenter::presentValidationError(std::string msg) {
	QMessageBox::warning(waitingRoomPage_, "Validation Error", QString::fromStdString(msg));
}
void QTWaitingRoomPresenter::presentWaitingRoomFailure(std::string msg) {
	QMessageBox::warning(waitingRoomPage_, "Waiting Room Failure", QString::fromStdString(msg));
}
void QTWaitingRoomPresenter::presentWaitingRoomSuccess() {
	emit waitingRoomSuccessed();
}