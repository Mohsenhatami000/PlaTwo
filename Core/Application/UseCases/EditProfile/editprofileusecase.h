#ifndef EDITPROFILEUSECASE_H
#define EDITPROFILEUSECASE_H

#include "Domain/Interfaces/Services/isessioncontext.h"
#include "Domain/Interfaces/Services/ieditprofilepresenter.h"
#include "Domain/Interfaces/Repositories/IUserRepository.h"
#include "Domain/Interfaces/Services/IHasher.h"
#include "Application/DTO/Auth/EditProfileRequest.h"

class EditProfileUseCase
{

    ISessionContext *session_;
    IEditProfilePresenter *editProfilePresenter_;
    IUserRepository *userRepo_;
    IHasher *hasher_;


public:
    EditProfileUseCase(IUserRepository *userRepo, IEditProfilePresenter *editProfilePresenter, ISessionContext *session, IHasher *hasher);
    void execute(EditProfileRequest &request);
};

#endif // EDITPROFILEUSECASE_H
