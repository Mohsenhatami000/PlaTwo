#pragma once
#include <optional>
#include "Entities/User.h"
class IUserRepository
{
public:
    virtual ~IUserRepository() = default;
    virtual void save(const User& user) = 0;
    virtual void update(const User& user) = 0;
    virtual void remove(std::int64_t id) = 0;
    virtual std::optional<User> findByID(std::int64_t id) const = 0;

};