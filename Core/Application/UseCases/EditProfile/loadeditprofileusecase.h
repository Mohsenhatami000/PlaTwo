#ifndef LOADEDITPROFILEUSECASE_H
#define LOADEDITPROFILEUSECASE_H

#include "Domain/Interfaces/Services/isessioncontext.h"
#include "Domain/Interfaces/Services/ieditprofilepresenter.h"
#include "Domain/Interfaces/Repositories/IUserRepository.h"

class LoadEditProfileUseCase
{

    ISessionContext *session_;
    IEditProfilePresenter *editProfilePresenter_;
    IUserRepository *userRepo_;

public:
    LoadEditProfileUseCase(IUserRepository *userRepo, IEditProfilePresenter *editProfilePresenter, ISessionContext *session);

    void execute();
};

#endif // LOADEDITPROFILEUSECASE_H
