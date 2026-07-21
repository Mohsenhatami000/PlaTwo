#ifndef ISESSIONCONTEXT_H
#define ISESSIONCONTEXT_H

#include "Domain/Entities/authenticateduser.h"
#include "Domain/Enums/Enums.h"
#include <optional>

class ISessionContext
{
public:
    virtual ~ISessionContext() = default;

    virtual bool isAuthenticated() const noexcept = 0;

    virtual const std::optional<AuthenticatedUser> currentUser() noexcept = 0;

    virtual void login(const AuthenticatedUser& user) = 0;

    virtual void logout() = 0;

    virtual void setGameType(const GameType gameType) = 0;

    virtual const GameType gameType() const = 0;

};

#endif // ISESSIONCONTEXT_H
