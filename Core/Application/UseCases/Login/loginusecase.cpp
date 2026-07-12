#include "Application/UseCases/Login/loginusecase.h"

#include "Domain/Interfaces/Repositories/IUserRepository.h"
#include "Domain/ValueObjects/UserName.h"
#include "Domain/ValueObjects/Password.h"
#include "Domain/ValueObjects/PasswordHash.h"
#include "Domain/Enums/Enums.h"
#include "Domain/Exceptions/Exceptions.h"


LoginUseCase::LoginUseCase(IUserRepository *userRepo, ILoginPresenter *loginPresenter, IHasher *hasher, ISessionContext *session){
    userRepo_ = userRepo;
    loginPresenter_ = loginPresenter;
    hasher_ = hasher;
    session_ = session;

}

void LoginUseCase::execute(const std::string username, const std::string password){
    try{
        UserName user(username);
        Password pass(password);
        }
    catch(Exceptions &e){
        switch(e.error()){
            case DomainError::UserNameEmpty:
            loginPresenter_->presentValidationError("Username is empty!");
                break;
            case DomainError::PasswordEmpty:
                loginPresenter_->presentValidationError("Password is empty!");
                break;
            case DomainError::UserNameInvalidFormat:
                loginPresenter_->presentValidationError("Username invalid format!");
                break;
            case DomainError::UserNameInvalidLength:
                loginPresenter_->presentValidationError("Username invalid length!");
                break;
            case DomainError::PasswordContainSpace:
                loginPresenter_->presentValidationError("Password contains space!");
                break;
            case DomainError::PasswordInvalidLength:
                loginPresenter_->presentValidationError("Password invalid length!");
                break;
            case DomainError::PasswordNoCharacter:
                loginPresenter_->presentValidationError("Password must contain characters!");
                break;
            case DomainError::PasswordNoNumber:
                loginPresenter_->presentValidationError("Password must contain numbers!");
                break;
            case DomainError::PasswordNoUppercase:
                loginPresenter_->presentValidationError("Password must contain Uppercase letters!");
                break;
            case DomainError::PasswordNoLowercase:
                loginPresenter_->presentValidationError("Password must contain Lowercase letters!");
                break;
            default:
                loginPresenter_->presentValidationError("Unknown error!");
                break;
            }
            return;
        }
        auto user = userRepo_->findByUsername(username);
        if(!user.has_value()){
            loginPresenter_->presentLoginFailure("User wasn't found!");
        }
        else{
            if(hasher_->verify(password, user.value().uPasswordHash().passswordHashValue())){
                loginPresenter_->presentLoginSuccess();
                session_->login(AuthenticatedUser(user.value().uID(), user.value().uName(), user.value().uUserName()));
            }
            else{
                loginPresenter_->presentLoginFailure("Password doesn't match!");
            }
        }
}
