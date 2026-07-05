#ifndef AUTHENTICATEDUSER_H
#define AUTHENTICATEDUSER_H

#include <cstdint>
#include "../ValueObjects/Name.h"
#include "../ValueObjects/UserName.h"

class AuthenticatedUser
{
    std::int64_t ID_;
    Name name_;
    UserName username_;

public:

    AuthenticatedUser(std::int64_t id, const Name& name, const UserName& username);

    std::int64_t ID() const noexcept;
    const Name& Name() const noexcept;
    const UserName& UserName() const noexcept;

    bool changeName(const Name& name);
    bool changeUserName(const UserName& username);


};

#endif // AUTHENTICATEDUSER_H
