#include "text.h"

Text::Text(int number, QString entry): ownNumber(number), ownEntry(entry)
{

}

bool Text::separationTreatment()
{
    bool itWork = false;
    QRegularExpression separators("[^a-zA-Z]");
    QString tempWord("");
    QStringList suggestListOfWord;

    for(int i(0); i < ownEntry.size(); i++ )
    {
        if(separators.match(ownEntry[i]).hasMatch())
        {
            if(tempWord.size() > 2)
            {
                suggestListOfWord << tempWord;
                tempWord = "";
            }

        } else
        {
            tempWord = tempWord + ownEntry[i];
        }
    }
    ownEntry = suggestListOfWord.join(" ");
    if(ownEntry.isEmpty() == false)
        itWork = true;

    return itWork;
}

QMap<int, quint64> Text::Scanner(QMultiMap<int, QRegularExpression> map)
{
    //bool done = false;
    QList<QRegularExpression> stringList;
    QMap<int, quint64> themeClassement;
    int count(0);
    //QList<int> keysList = map.uniqueKeys();
    for(int i(0); i < map.uniqueKeys().size(); i++)
    {
        //QList<QRegularExpression> regexList = map.values(map.keys().at(i));
        qDebug() <<" " << map.uniqueKeys().at(i) << "\n";
        stringList = map.values(map.uniqueKeys().at(i));
        qDebug() << stringList;
        for(int j(0); j < stringList.size(); j++)
        {
            count = count + ownEntry.count(stringList.at(j));//précisez un match ne tenant pas compte de la casse
            //qDebug() << ownEntry.count(stringList.at(j)) <<"*****"<< stringList.at(j);
        }
        if(count > 0)
        {
            themeClassement.insert(map.uniqueKeys().at(i), count);
            //qDebug() << map.uniqueKeys().at(i) <<"*****"<< count;

        }
        count = 0;

    }//Lecteur de flux RSS

    /*Une requête qui renvoie dans la base de donnée des informations que le coté client pourra utiluser pour présenter
    des résultats et c'est le resultat de cette requête qui ettribue une valeur au bool done*/

    return themeClassement;

}
