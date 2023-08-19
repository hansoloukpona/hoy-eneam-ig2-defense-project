#include "database.h"

Database::Database(QString initType, QString initHostName, QString initDatabaseName,
                   QString initUserName, qint16 initPort, QString initTableName,
                   QString columnId, QString columnText, QString initPassword):
    tableName(initTableName), columnOfId(columnId), columnOfText(columnText)
{
    db = QSqlDatabase::addDatabase(initType);
    db.setHostName(initHostName);
    db.setDatabaseName(initDatabaseName);
    db.setUserName(initUserName);
    db.setPassword(initPassword);
    db.setPort(initPort);
    qDebug() << db.database() << " " << initHostName <<" " << initDatabaseName << " " << initUserName << " " << initPort << " " << initPassword;

}

Database::Database(QString initType, QString initHostName, QString initDatabaseName,
                   QString initUserName, QString initTableName, QString columnId, QString columnText,
                   QString initPassword):
    tableName(initTableName), columnOfId(columnId), columnOfText(columnText)
{
    db = QSqlDatabase::addDatabase(initType);
    db.setHostName(initHostName);
    db.setDatabaseName(initDatabaseName);
    db.setUserName(initUserName);
    db.setPassword(initPassword);
    db.setPort(3306);

    qDebug() << db.database() <<" " << initDatabaseName << " " << initUserName << " " << db.port() << " " << initPassword;

}


const QString &Database::getColumnOfId() const
{
    return columnOfId;
}

const QString &Database::getColumnOfText() const
{
    return columnOfText;
}

QSqlDatabase &Database::getDb()
{
    return db;
}

const QString &Database::getTableName() const
{
    return tableName;
}
