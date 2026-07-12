#include "databasemanager.h"
#include <QSqlQuery>
#include <QDir>
#include <QDebug>


bool DatabaseManager::initialize(){
    db_ = QSqlDatabase::addDatabase("QSQLITE");

    db_.setDatabaseName("database.db");
    qDebug() << QDir::currentPath();

    if(db_.open()){

        createTable();
        return true;
    }
    else return false;
}

void DatabaseManager::createTable(){
    QSqlQuery query(db_);
    if(!query.exec("CREATE TABLE IF NOT EXISTS Users (ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Username TEXT UNIQUE, PhoneNumber TEXT UNIQUE, Email TEXT UNIQUE, PasswordHash TEXT);")){
        qDebug() << "Error";
    }
}

QSqlDatabase &DatabaseManager::database(){
    return db_;
}
