#pragma once
#include <optional>
#include "Domain/Entities/User.h"

class IUserRepository
{
public:
    virtual ~IUserRepository() = default;
    virtual void save(const User& user) = 0;
    virtual void update(const User& user) = 0;
    virtual void remove(std::int64_t id) = 0;
    virtual std::optional<User> findByID(std::int64_t id) const = 0;
    virtual std::optional<User> findByUsername(const std::string username) const = 0;

};