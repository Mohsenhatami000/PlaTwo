#ifndef SESSIONCONTEXT_H
#define SESSIONCONTEXT_H

#include "Domain/Interfaces/Services/isessioncontext.h"
#include "Domain/Entities/authenticateduser.h"
#include "optional"

class SessionContext : public ISessionContext{

    std::optional<AuthenticatedUser> currentUser_;

public:

    bool isAuthenticated() const noexcept override;

    const std::optional<AuthenticatedUser> currentUser() noexcept override;

    void login(const AuthenticatedUser& user) override;

    void logout() override;
};

#endif // SESSIONCONTEXT_H
