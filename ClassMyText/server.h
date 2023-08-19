#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QRegularExpression>
#include <QTimer>
#include "text.h"
#include "database.h"


class Server: public QObject
{
    Q_OBJECT
public:
    Server(Database initialDb);

signals:
    void newRequestSignal();
    void periodicequestError(QSqlError);
    void callOfSuggestTreatment(QSqlQuery);

public slots:
    bool themeRefresh();
    bool dbPeriodicRequest();
    bool suggestTreatment(QSqlQuery);

private:
    QMultiMap<int, QRegularExpression> actualThemesList;
    qint64 lastSuggestId;
    Database serverDb;
    //QSqlTableModel dbModel;
    //static const qint32 TwentyFourHourInterval = 86400000;
};

#endif // SERVER_H


