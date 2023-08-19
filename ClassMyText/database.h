#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class Database:public QSqlDatabase
{
public:
    Database(QString initType, QString initHostName, QString initDatabaseName,
             QString initUserName, qint16 initPort, QString initTableName,
             QString columnId, QString columnText, QString initPassword = "");
    Database(QString initType, QString initHostName, QString initDatabaseName,
             QString initUserName, QString initTableName,
             QString columnId, QString columnText,
             QString initPassword = "");

    const QString &getColumnOfId() const;

    const QString &getColumnOfText() const;

    QSqlDatabase &getDb();

    const QString &getTableName() const;

private:
    QSqlDatabase db;
    QString tableName;
    QString columnOfId;
    QString columnOfText;
};

#endif // DATABASE_H
