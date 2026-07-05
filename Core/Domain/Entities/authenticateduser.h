#ifndef AUTHENTICATEDUSER_H
#define AUTHENTICATEDUSER_H

#include <cstdint>
#include "../ValueObjects/Name.h"
#include "../ValueObjects/UserName.h"

class AuthenticatedUser
{
    std::int64_t u_ID_;
    Name u_name_;
    UserName u_username_;

public:

    AuthenticatedUser(std::int64_t id, const Name& name, const UserName& username);

    std::int64_t id() const noexcept;
    const Name& name() const noexcept;
    const UserName& username() const noexcept;

    bool changeName(const Name& name);
    bool changeUserName(const UserName& username);


};

#endif // AUTHENTICATEDUSER_H
