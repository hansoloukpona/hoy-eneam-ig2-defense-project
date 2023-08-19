#include "server.h"

Server::Server(Database initialDb):
    serverDb(initialDb)
{
    lastSuggestId = 0;

    connect(this, SIGNAL(newRequestSignal()), this, SLOT(dbPeriodicRequest()));
    connect(this, SIGNAL(callOfSuggestTreatment(QSqlQuery)), this, SLOT(suggestTreatment(QSqlQuery)));
}

bool Server::themeRefresh()
{
    if (serverDb.getDb().open())
    {
        QSqlQuery patternUpdate("SELECT theme, words FROM Dictionnaire");
        while (patternUpdate.next()) {
            actualThemesList.insert(patternUpdate.value(0).toInt(), QRegularExpression(patternUpdate.value(1).toString()));
            qDebug() << patternUpdate.value(0).toString() << " "<< patternUpdate.value(1).toString();
        }
        serverDb.getDb().close();
        QTimer::singleShot(86400000, this, SLOT(themeRefresh()));
    } else
    {
        qDebug() << serverDb.getDb().lastError() ; //On va changer ce by en quelque chose d'accèssible après pour maintenance
    }
    return true;
}

bool Server::dbPeriodicRequest()
{
    bool itWork = false;
    if (serverDb.getDb().open())
    {
        //le nom de la table doit être entré
        QSqlQuery suggestCollect;
        QString requestString = "SELECT " + serverDb.getColumnOfId()
                + ", " + serverDb.getColumnOfText() + " FROM "
                + serverDb.getTableName() + " WHERE "
                +  serverDb.getColumnOfId()+ " > ?";
        suggestCollect.prepare(requestString);
        suggestCollect.addBindValue(lastSuggestId);
        itWork = suggestCollect.exec();
        serverDb.getDb().close();

        if(itWork == true){
            qDebug() << "dbPeriodic :" << itWork;
            emit callOfSuggestTreatment(suggestCollect);
            qDebug() << "\n\n Paaaaate";

        }else{
            emit periodicequestError(serverDb.getDb().lastError());//Un moyen de faire notifier ça
            qDebug() << serverDb.getDb().lastError() <<"erreure";//Créer une fonction de notification d'erreur//Rendre ça compréhensible à un humain

        }
    }else
    {
        qDebug() << serverDb.getDb().lastError() <<".........";//Créer une fonction de notification d'erreur//Rendre ça compréhensible à un humain
        emit periodicequestError(serverDb.getDb().lastError());//Un moyen de faire notifier ça
    }
    QTimer::singleShot(3600000, this, SLOT(dbPeriodicRequest()));
    return itWork;
}


bool Server::suggestTreatment(QSqlQuery suggestCollect)
{
    if(!suggestCollect.record().isEmpty())
    {
        QString requestString;
        while(suggestCollect.next())
        {
            qDebug() << "\n\n Sauuuuce";
            lastSuggestId = suggestCollect.value(0).toInt();
            Text scannedSuggestion(suggestCollect.value(0).toInt(), suggestCollect.value(1).toString());/*.split(QLatin1Char(' '), Qt::SkipEmptyParts)*/
            qDebug() << suggestCollect.value(0).toInt() << " " <<  suggestCollect.value(1).toString() ;
            scannedSuggestion.separationTreatment();
            QMap<int, quint64> forResultQuery = scannedSuggestion.Scanner(actualThemesList);//
            //Requète
            QMapIterator<int, quint64> k(forResultQuery);
            bool cool;

            while (k.hasNext()) {
                k.next();
                if(serverDb.getDb().open())
                {
                    QSqlQuery insertionOfResult;
                    insertionOfResult.prepare("INSERT INTO result VALUES(:numberOfSuggestion, :themeIdentityKey, :numberofWordMatch )");
                    insertionOfResult.bindValue(":numberOfSuggestion", suggestCollect.value(0).toInt());
                    insertionOfResult.bindValue(":themeIdentityKey", k.key());
                    insertionOfResult.bindValue(":numberofWordMatch", k.value());
                    cool = insertionOfResult.exec();
                    serverDb.getDb().close();
                }

                qDebug() << "\n\n" << cool;
            }
        }
        //appel de bddperiodicRequest avec en paramètre lastSuggestTime
        //emit newRequestSignal();
        return lastSuggestId;

    } else
    {
        //l'ancien id de référence est toujours enrégistré
        return 0;
        qDebug() << "\n\n" << 0;

    }
}
