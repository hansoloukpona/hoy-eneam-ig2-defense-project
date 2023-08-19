#ifndef TEXT_H
#define TEXT_H

#include <QObject>
#include <QRegularExpression>

class Text
{
public:
    Text(int number, QString entry);

    bool separationTreatment();
    QMap<int, quint64> Scanner(QMultiMap<int, QRegularExpression> map);

private:
    int ownNumber;
    QString ownEntry;
    //QList<Theme> ownThemes;
    /*Il faudra s'arranger pour que le thème
    le plus pertinent soit en premier dans la liste puis les autres si il y en a*/

};

#endif // TEXT_H



