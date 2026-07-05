#ifndef ISESSIONCONTEXT_H
#define ISESSIONCONTEXT_H

#include "Domain/Entities/authenticateduser.h"
#include <optional>

class ISessionContext
{
public:
    virtual ~ISessionContext() = default;

    virtual bool isAuthenticated() const noexcept = 0;

    virtual const std::optional<AuthenticatedUser> currentUser() const noexcept = 0;

    virtual void login(const AuthenticatedUser& user) = 0;

    virtual void logout() = 0;
};

#endif // ISESSIONCONTEXT_H
