#include "sqliteuserrepository.h"
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>
#include "Domain/Exceptions/Exceptions.h"

SQLiteUserRepository::SQLiteUserRepository(QSqlDatabase db){
    db_ = db;
}

void SQLiteUserRepository::save(const std::string& name, const std::string& username, const std::string& number, const std::string& email,
                                const std::string& passHash){
    QSqlQuery query(db_);
    query.prepare("INSERT INTO Users (Name, Username, PhoneNumber, Email, PasswordHash) VALUES (?, ?, ?, ?, ?);"); //UNIQUE handels later
    query.bindValue(0, QString::fromStdString(name));
    query.bindValue(1, QString::fromStdString(username));
    query.bindValue(2, QString::fromStdString(number));
    query.bindValue(3, QString::fromStdString(email));
    query.bindValue(4, QString::fromStdString(passHash));
    if(!query.exec()){
        if(query.lastError().text().contains("UNIQUE") && query.lastError().text().contains("PhoneNumber")){
            throw Exceptions(DomainError::PhoneNumberNotUnique);
        }
        else if(query.lastError().text().contains("UNIQUE") && query.lastError().text().contains("Email")){
            throw Exceptions(DomainError::EmailNotUnique);

        }
        else if(query.lastError().text().contains("UNIQUE") && query.lastError().text().contains("Username")){
            throw Exceptions(DomainError::UsernameNotUnique);
        }
        else{
            qDebug() << query.lastError().text();
            throw Exceptions(DomainError::UnknownError);
        }
    }

}

void SQLiteUserRepository::update(std::int64_t id, const std::string& name, const std::string& username, const std::string& number, const std::string& email,
                                  const std::string& passHash){
    QSqlQuery query(db_);
    query.prepare("UPDATE Users SET Name = ?, Username = ?, PhoneNumber = ?, Email = ?, PasswordHash = ? WHERE ID = ?;"); //UNIQUE handels later
    query.bindValue(0, QString::fromStdString(name));
    query.bindValue(1, QString::fromStdString(username));
    query.bindValue(2, QString::fromStdString(number));
    query.bindValue(3, QString::fromStdString(email));
    query.bindValue(4, QString::fromStdString(passHash));
    query.bindValue(5, id);
    if(!query.exec()){
        if(query.lastError().text().contains("UNIQUE") && query.lastError().text().contains("PhoneNumber")){
            throw Exceptions(DomainError::PhoneNumberNotUnique);
        }
        else if(query.lastError().text().contains("UNIQUE") && query.lastError().text().contains("Email")){
            throw Exceptions(DomainError::EmailNotUnique);

        }
        else if(query.lastError().text().contains("UNIQUE") && query.lastError().text().contains("Username")){
            throw Exceptions(DomainError::UsernameNotUnique);
        }
        else{
            qDebug() << query.lastError().text();
            throw Exceptions(DomainError::UnknownError);
        }
    }

}

void SQLiteUserRepository::remove(std::int64_t id){
    QSqlQuery query(db_);
    query.prepare("DELETE FROM Users WHERE ID = ?;");
    query.bindValue(0, id);
    if(!query.exec()){
        qDebug() << query.lastError().text();
        throw Exceptions(DomainError::UnknownError);
    }
}

std::optional<User> SQLiteUserRepository::findByID(std::int64_t id) const{
    QSqlQuery query(db_);
    query.prepare("SELECT * FROM Users WHERE ID = ?;");
    query.bindValue(0, id);
    if(!query.exec()){
        qDebug() << query.lastError().text();
        throw Exceptions(DomainError::UnknownError);
    }
    if(!query.next()){
        std::optional<User> user;
        return user;
    }

    Name name(query.value(1).toString().toStdString());
    UserName username(query.value(2).toString().toStdString());
    PhoneNumber number(query.value(3).toString().toStdString());
    Email email(query.value(4).toString().toStdString());
    PasswordHash pass(query.value(5).toString().toStdString());


    std::optional<User> user;
    user = User(id, name, username, number, email, pass);
    return user;
}

std::optional<User> SQLiteUserRepository::findByUsername(std::string username) const{
    QSqlQuery query(db_);
    query.prepare("SELECT * FROM Users WHERE Username = ?;");
    query.bindValue(0, QString::fromStdString(username));
    if(!query.exec()){
        qDebug() << query.lastError().text();
        throw Exceptions(DomainError::UnknownError);
    }

    if(!query.next()){
        std::optional<User> user;
        return user;
    }

    int64_t id = query.value(0).toInt();
    Name name(query.value(1).toString().toStdString());
    PhoneNumber number(query.value(3).toString().toStdString());
    Email email(query.value(4).toString().toStdString());
    PasswordHash pass(query.value(5).toString().toStdString());
    UserName u_name(username);


    std::optional<User> user;
    user = User(id, name, u_name, number, email, pass);
    return user;
}

std::optional<User> SQLiteUserRepository::findByPhoneNumber(std::string number) const{
    QSqlQuery query(db_);
    query.prepare("SELECT * FROM Users WHERE PhoneNumber = ?;");
    query.bindValue(0, QString::fromStdString(number));
    if(!query.exec()){
        qDebug() << query.lastError().text();
        throw Exceptions(DomainError::UnknownError);
    }

    if(!query.next()){
        std::optional<User> user;
        return user;
    }

    int64_t id = query.value(0).toInt();
    Name name(query.value(1).toString().toStdString());
    UserName username(query.value(2).toString().toStdString());
    PhoneNumber u_number(number);
    Email email(query.value(4).toString().toStdString());
    PasswordHash pass(query.value(5).toString().toStdString());


    std::optional<User> user;
    user = User(id, name, username, u_number, email, pass);
    return user;
}

void SQLiteUserRepository::updatePassword(const std::string& number, const std::string& newPasswordHash){
    QSqlQuery query(db_);
    query.prepare("UPDATE Users SET PasswordHash = ? WHERE PhoneNumber = ?");
    query.bindValue(0, QString::fromStdString(newPasswordHash));
    query.bindValue(1, QString::fromStdString(number));
    if(!query.exec()){
        qDebug() << query.lastError().text();
        throw Exceptions(DomainError::UnknownError);
    }
}

















