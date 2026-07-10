#include <stdexcept>
#include "SignUpUseCase.h"
#include "Domain/ValueObjects/Password.h"
SignupUseCase::SignupUseCase(IUserRepository *repo, IHasher *hasher, ISignupPresenter *pre):userRepo_(repo),
               presenter_(pre),hasher_(hasher) {

}
void SignupUseCase::execute(const SignUpRequest& request) {
	try
	{
		if (request.password_ != request.confirmPassword_) {
			throw std::invalid_argument("Passwords do not match");
		}
		Name name(request.name_);
		UserName username(request.username_);
        PhoneNumber phonenumber(request.phoneNumber_);
		Email email(request.email_);
		Password password(request.password_);
		PasswordHash hashed(hasher_->hash(request.password_));
        auto user1 = userRepo_->findByUsername(request.username_);
        if (user1.has_value()) {
            presenter_->presentSignupFailure("User with this username already exists!");
        }
        auto user2 = userRepo_->findByPhoneNumber(request.phoneNumber_);
        if (user2.has_value()) {
            presenter_->presentSignupFailure("User with this phonenumber already exists!");
        }
        auto user3 = userRepo_->findByEmail(request.email_);
        if (user3.has_value()) {
            presenter_->presentSignupFailure("User with this email already exists!");
        }
        else {
            User user = userRepo_->save(name, username, phonenumber, email, hashed);
            presenter_->presentSignUpSuccess();
        }
	}
	catch(const std::invalid_argument& e)
	{
		std::string str(e.what());
		presenter_->presentValidationError(str);
	}
    catch (const std::runtime_error& e)
    {
        std::string str(e.what());
        presenter_->presentValidationError(str);
    }
	catch (Exceptions& e) 
    {
        switch (e.error()) {
        case DomainError::NameEmpty:
            presenter_->presentValidationError("Name is empty!");
            break;
        case DomainError::NameInvalidLength:
            presenter_->presentValidationError("Name length should be between 3 and 20!");
            break;
        case DomainError::UserNameEmpty:
            presenter_->presentValidationError("Username is empty!");
            break;
        case DomainError::UserNameInvalidLength:
            presenter_->presentValidationError("Username invalid length!");
            break;
        case DomainError::UserNameInvalidFormat:
            presenter_->presentValidationError("Username invalid format!");
            break;
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
        case DomainError::EmailEmpty:
            presenter_->presentValidationError("email is empty!");
            break;
        case DomainError::EmailInvalidFormat:
            presenter_->presentValidationError("Email invalid format!");
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