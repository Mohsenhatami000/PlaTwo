#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>


class DatabaseManager
{
    QSqlDatabase db_;


public:

    bool initialize();

    void createTable();

    QSqlDatabase& database();


};

#endif // DATABASEMANAGER_H
