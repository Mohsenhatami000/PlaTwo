#ifndef SQLITEUSERREPOSITORY_H
#define SQLITEUSERREPOSITORY_H

#include <QSqlDatabase>
#include "Domain/Entities/User.h"
#include "Domain/Interfaces/Repositories/IUserRepository.h"

class SQLiteUserRepository : public IUserRepository
{
    QSqlDatabase db_;

public:

    void save(const std::string& name, const std::string& username, const std::string& number, const std::string& email,
                      const std::string& passHash);
    void update(std::int64_t id, const std::string& name, const std::string& username, const std::string& number, const std::string& email,
                const std::string& passHash);
    void remove(std::int64_t id);
    std::optional<User> findByID(std::int64_t id) const;
    std::optional<User> findByUsername(std::string username) const;
    std::optional<User> findByPhoneNumber(std::string number) const;
    void updatePassword(const std::string& number, const std::string& newPasswordHash);

    SQLiteUserRepository(QSqlDatabase db);
};

#endif // SQLITEUSERREPOSITORY_H
