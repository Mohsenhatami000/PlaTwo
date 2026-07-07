#include "editprofileusecase.h"
#include "Domain/ValueObjects/Name.h"
#include "Domain/ValueObjects/UserName.h"
#include "Domain/ValueObjects/Email.h"
#include "Domain/ValueObjects/PhoneNumber.h"
#include "Domain/ValueObjects/Password.h"
#include "Domain/Exceptions/Exceptions.h"

EditProfileUseCase::EditProfileUseCase(IUserRepository *userRepo
                                       , IEditProfilePresenter *editProfilePresenter
                                       , ISessionContext *session
                                       , IHasher *hasher){
    userRepo_ = userRepo;
    editProfilePresenter_ = editProfilePresenter;
    session_ = session;
    hasher_ = hasher;
}

void EditProfileUseCase::execute(EditProfileRequest &request){

    try{
        Name name_(request.name_);
        UserName username_(request.username_);
        Email email_(request.email_);
        PhoneNumber phoneNumber_(request.phoneNumber_);
    }
    catch(Exceptions &e){
        switch(e.error()){
        case DomainError::UserNameEmpty:
            editProfilePresenter_->presentValidationError("Username is empty!");
            break;
        case DomainError::NameEmpty:
            editProfilePresenter_->presentValidationError("Name is empty!");
            break;
        case DomainError::EmailEmpty:
            editProfilePresenter_->presentValidationError("Email is empty!");
            break;
        case DomainError::PhoneNumberEmpty:
            editProfilePresenter_->presentValidationError("PhoneNumber is empty!");
            break;
        case DomainError::NameInvalidLength:
            editProfilePresenter_->presentValidationError("Name invalid length!");
            break;
        case DomainError::EmailInvalidFormat:
            editProfilePresenter_->presentValidationError("Email invalid format!");
            break;
        case DomainError::PhoneNumberInvalidLength:
            editProfilePresenter_->presentValidationError("PhoneNumber invalid length!");
            break;
        case DomainError::PhoneNumberInvalidCharacter:
            editProfilePresenter_->presentValidationError("PhoneNumber invalid character");
            break;
        case DomainError::PhoneNumberInvalidStart:
            editProfilePresenter_->presentValidationError("PhoneNumber invalid start!");
            break;
        case DomainError::UserNameInvalidFormat:
            editProfilePresenter_->presentValidationError("Username invalid format!");
            break;
        case DomainError::UserNameInvalidLength:
            editProfilePresenter_->presentValidationError("Username invalid length!");
            break;
        default:
            editProfilePresenter_->presentValidationError("Unknown error!");
            break;
        }
        return;
    }
    User user = userRepo_->findByID(session_->currentUser().value().id()).value();
    if(request.confirmPassword_.empty() && request.currentPassword_.empty() && request.newPassword_.empty()){
        userRepo_->update(User(user.uID(),
                               Name(request.name_),
                               UserName(request.username_),
                               PhoneNumber(request.phoneNumber_),
                               Email(request.email_),
                               user.uPasswordHash()));

        session_->login(AuthenticatedUser(user.uID(), Name(request.name_), UserName(request.username_)));
        editProfilePresenter_->presentEditSuccess();
    }
    else if(request.newPassword_ == request.confirmPassword_){
        if(!(hasher_->verify(request.currentPassword_, user.uPasswordHash().passswordHashValue()))){
            editProfilePresenter_->presentValidationError("current password doesn't match!");
        }
        else{
            try{
                Password newPass_(request.newPassword_);
            }
            catch(Exceptions &e){
                switch(e.error()){
                case DomainError::PasswordEmpty:
                    editProfilePresenter_->presentValidationError("Password is empty!");
                    break;
                case DomainError::PasswordContainSpace:
                    editProfilePresenter_->presentValidationError("Password contains space!");
                    break;
                case DomainError::PasswordInvalidLength:
                    editProfilePresenter_->presentValidationError("Password invalid length!");
                    break;
                case DomainError::PasswordNoCharacter:
                    editProfilePresenter_->presentValidationError("Password must contain characters!");
                    break;
                case DomainError::PasswordNoNumber:
                    editProfilePresenter_->presentValidationError("Password must contain numbers!");
                    break;
                case DomainError::PasswordNoUppercase:
                    editProfilePresenter_->presentValidationError("Password must contain Uppercase letters!");
                    break;
                case DomainError::PasswordNoLowercase:
                    editProfilePresenter_->presentValidationError("Password must contain Lowercase letters!");
                    break;
                default:
                    editProfilePresenter_->presentValidationError("Unknown error!");
                    break;
                }
                return;
            }
            userRepo_->update(User(user.uID(),
                                   Name(request.name_),
                                   UserName(request.username_),
                                   PhoneNumber(request.phoneNumber_),
                                   Email(request.email_),
                                   PasswordHash(request.newPassword_)));
            session_->login(AuthenticatedUser(user.uID(), Name(request.name_), UserName(request.username_)));
            editProfilePresenter_->presentEditSuccess();
        }
    }
    else{
        editProfilePresenter_->presentValidationError("passwords do not match");
    }
}