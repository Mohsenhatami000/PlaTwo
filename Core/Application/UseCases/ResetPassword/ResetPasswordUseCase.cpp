#include "ResetPasswordUsecase.h"
#include <stdexcept>

ResetPasswordUsecase::ResetPasswordUsecase(IUserRepository* repo, IHasher* hasher, IResetPasswordPresenter* pre):
                     userRepo_(repo),hasher_(hasher),presenter_(pre){
}
void ResetPasswordUsecase::execute(const ResetPasswordRequest& request) {
	try
	{
		if (request.newpass_ != request.newpassconfirm_) {
			throw std::invalid_argument("Passwords do not match!");
		}
        PhoneNumber phonenumber(request.phoneNumber_);
		Password newpass(request.newpass_);
		PasswordHash hash(hasher_->hash(request.newpass_));
        auto user = userRepo_->findByPhoneNumber(request.phoneNumber_);
        if (!user.has_value()) {
            presenter_->presentResetPasswordFailure("User does not exist!");
        }
        else {
            userRepo_->updatePassword(phonenumber.phoneNumerValue(), hash.passswordHashValue());
            presenter_->presentResetPasswordSuccess();
        }
	}
	catch (const std::invalid_argument& e)
	{
		std::string str(e.what());
		presenter_->presentValidationError(str);
	}
    catch(const std::runtime_error& e)
    {
        std::string str(e.what());
        presenter_->presentValidationError(str);
    }
    catch (Exceptions& e) 
    {
        switch (e.error()) {
        case DomainError::PhoneNumberEmpty:
            presenter_->presentValidationError("Please enter a phonenumber!");
            break;
        case DomainError::PhoneNumberInvalidLength:
            presenter_->presentValidationError("Please enter in format 09... or 98 ... with right length");
            break;
        case DomainError::PhoneNumberInvalidCharacter:
            presenter_->presentValidationError("Phonenumber can not have chracter!");
            break;
        case DomainError::PhoneNumberInvalidStart:
            presenter_->presentValidationError("Please start your phone number with 09 or 98 !");
            break;
        case DomainError::PasswordEmpty:
            presenter_->presentValidationError("Password is empty!");
            break;
        case DomainError::PasswordContainSpace:
            presenter_->presentValidationError("Password should not contain space!");
            break;
        case DomainError::PasswordInvalidLength:
            presenter_->presentValidationError("Password length should be between 8 to 64 chracters!");
            break;
        case DomainError::PasswordNoCharacter:
            presenter_->presentValidationError("Password should have a character!");
            break;
        case DomainError::PasswordNoLowercase:
            presenter_->presentValidationError("Password should have a lowercase!");
            break;
        case DomainError::PasswordNoUppercase:
            presenter_->presentValidationError("Password should have a uppercase!");
            break;
        case DomainError::PasswordNoNumber:
            presenter_->presentValidationError("Password should have a number!");
            break;
        default:
            presenter_->presentValidationError("Unknown error!");
            break;
        }
        return;
    }
}

