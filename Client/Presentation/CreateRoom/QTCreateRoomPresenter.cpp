#include "QTCreateRoomPresenter.h"
#include <QString>
#include <QMessageBox>

QTCreateRoomPresenter::QTCreateRoomPresenter(CreateRoomPage *page) :createRoomPage_(page){

}
void QTCreateRoomPresenter::presentValidationError(std::string msg) {
	QMessageBox::warning(createRoomPage_, "Validation Error", QString::fromStdString(msg));
}
void QTCreateRoomPresenter::presentCreateRoomFailure(std::string msg) {
	QMessageBox::warning(createRoomPage_, "Create Room Failure", QString::fromStdString(msg));
}
void QTCreateRoomPresenter::presentCreateRoomSuccess() {
	emit createRoomSuccessed();
}