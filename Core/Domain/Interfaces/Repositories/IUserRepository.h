#pragma once
#include <optional>
#include "Domain/Entities/User.h"
class IUserRepository
{
public:
    virtual ~IUserRepository() = default;
    virtual void save(const std::string& name, const std::string& username, const std::string& number, const std::string& email,
        const std::string& passHash) = 0;
    virtual void update(std::int64_t id, const std::string& name, const std::string& username, const std::string& number, const std::string& email,
                        const std::string& passHash) = 0;
    virtual void remove(std::int64_t id) = 0;
    virtual std::optional<User> findByID(std::int64_t id) const = 0;
    virtual std::optional<User> findByUsername(std::string username) const = 0;
    virtual std::optional<User> findByPhoneNumber(std::string number) const = 0;
    virtual void updatePassword(const std::string& number, const std::string& newPassword) = 0;

};