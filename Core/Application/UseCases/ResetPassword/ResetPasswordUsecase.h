#pragma once
#include "Application/DTO/Auth/ResetPasswordDTO.h"
#include "Domain/Interfaces/Repositories/IUserRepository.h"
#include "Domain/Interfaces/Services/IHasher.h"
#include "Domain/Interfaces/Services/IResetPasswordPresenter.h"
#include "Domain/Enums/Enums.h"
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/ValueObjects/Password.h"

class ResetPasswordUsecase
{
private:
	IUserRepository *userRepo_;
	IHasher *hasher_;
	IResetPasswordPresenter* presenter_;

public:
	ResetPasswordUsecase(IUserRepository *repo, IHasher *hasher,IResetPasswordPresenter *pre);
	void execute(const ResetPasswordRequest& request);
};