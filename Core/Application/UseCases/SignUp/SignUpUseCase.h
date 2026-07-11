#ifndef SIGNUPUSECASE_H
#define SIGNUPUSECASE_H
#include "Application/DTO/Auth/SignUpDTO.h"
#include "Domain/Interfaces/Repositories/IUserRepository.h"
#include "Domain/Interfaces/Services/IHasher.h"
#include "Domain/Interfaces/Services/ISignupPresenter.h"


class SignupUseCase
{
private:
	IUserRepository *userRepo_;
	IHasher *hasher_;
	ISignupPresenter *presenter_;

public:
	SignupUseCase(IUserRepository *repo, IHasher *hasher, ISignupPresenter *pre);
	void execute(const SignUpRequest& request);

};

#endif