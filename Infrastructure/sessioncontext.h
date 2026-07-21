#ifndef SESSIONCONTEXT_H
#define SESSIONCONTEXT_H

#include "Domain/Interfaces/Services/isessioncontext.h"
#include "Domain/Entities/authenticateduser.h"
#include "Domain/Enums/Enums.h"
#include "optional"

class SessionContext : public ISessionContext{

    std::optional<AuthenticatedUser> currentUser_;
    GameType gameType_;

public:

    bool isAuthenticated() const noexcept override;

    const std::optional<AuthenticatedUser> currentUser() noexcept override;

    void login(const AuthenticatedUser& user) override;

    void logout() override;

    void setGameType(const GameType gameType) override;

    const GameType gameType() const override;

};

#endif // SESSIONCONTEXT_H
