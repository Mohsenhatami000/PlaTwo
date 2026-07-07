#pragma once
#include <optional>
#include "Domain/Entities/User.h"
#include "Domain/ValueObjects/Name.h"
#include "Domain/ValueObjects/UserName.h"
#include "Domain/ValueObjects/Email.h"
#include "Domain/ValueObjects/PhoneNumber.h"
#include "Domain/ValueObjects/PasswordHash.h"
class IUserRepository
{
public:
    virtual ~IUserRepository() = default;
    virtual User save(const Name& name, const UserName& username, const PhoneNumber& number, const Email& email,
        const PasswordHash& pass) = 0;
    virtual void update(const User& user) = 0;
    virtual void remove(std::int64_t id) = 0;
    virtual std::optional<User> findByID(std::int64_t id) const = 0;
    virtual std::optional<User> findByUsername(std::string username) const = 0;
    virtual std::optional<User> findByPhoneNumber(std::string number) const = 0;
    virtual std::optional<User> findByEmail(std::string email) const = 0;
    virtual void updatePassword(const PhoneNumber& number, const PasswordHash& newPassword) = 0;

};