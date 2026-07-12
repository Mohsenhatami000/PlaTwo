#include "loadeditprofileusecase.h"

LoadEditProfileUseCase::LoadEditProfileUseCase(IUserRepository *userRepo
                                               , IEditProfilePresenter *editProfilePresenter
                                               ,ISessionContext *session){
    userRepo_ = userRepo;
    editProfilePresenter_ = editProfilePresenter;
    session_ = session;
}

void LoadEditProfileUseCase::execute(){
    AuthenticatedUser TmpUser = session_->currentUser().value();
    User user = userRepo_->findByID(TmpUser.id()).value();
    editProfilePresenter_->LoadEditProfilePage(user);
}