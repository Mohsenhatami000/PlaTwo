#ifndef LOGINUSECASE_H
#define LOGINUSECASE_H

#include "Domain/Interfaces/Repositories/IUserRepository.h"
#include "Domain/Interfaces/Services/iloginpresenter.h"
#include "Domain/Interfaces/Services/IHasher.h"
#include "Domain/Interfaces/Services/isessioncontext.h"

class LoginUseCase
{
    IUserRepository *userRepo_;
    ILoginPresenter *loginPresenter_;
    IHasher *hasher_;
    ISessionContext *session_;

public:
    LoginUseCase(IUserRepository *userRepo, ILoginPresenter *loginPresenter, IHasher *hasher, ISessionContext *session);

    void execute(const std::string username, const std::string password);
};

#endif // LOGINUSECASE_H
