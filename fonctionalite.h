#ifndef FONCTIONALITE_H
#define FONCTIONALITE_H
#include <QStringList>
#include <QMap>

class Fonctionalite
{
public:
    Fonctionalite();
    void decoupage(QString & dat);
    void photo();
    void  nomdurecette();
    void  auteur();
    void lienauteur();
    void edaman();
    void cuisinetype();
    void dishtype();
    void mealtype();
    void ingredients();
    void cautions();
    void healthlabels();
    QStringList auteuliste();
    QStringList nomdurecettliste();
    QStringList photo1();
private:
    QStringList data;
    QStringList phot01;
    QStringList nomdurecette1;
    QStringList auteur1;
    QStringList lienauteur1;
    QStringList edaman1;
    QStringList cuisinetype1;
    QStringList dishtype1;
    QStringList ingredients1;
    QStringList cautions1;
    QStringList healthlabels1;
    QStringList mealtype1;
    QMap<int,QStringList> ingre;
    QMap<int,QStringList> cauti;
    QMap<int,QStringList> health;


};
#endif // FONCTIONALITE_H
