#include "sessioncontext.h"

bool SessionContext::isAuthenticated() const noexcept{
    if(currentUser_.has_value()) return true;
    else return false;
}

const std::optional<AuthenticatedUser> SessionContext::currentUser() noexcept{
    return currentUser_.value();
}

void SessionContext::login(const AuthenticatedUser& user){
    currentUser_ = user;
}

void SessionContext::logout(){
    currentUser_.reset();
}
