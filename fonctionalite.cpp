#include "fonctionalite.h"
#include <QDebug>

Fonctionalite::Fonctionalite() {

}
void Fonctionalite::decoupage(QString &dat){
    data=dat.split("\"");
}
void Fonctionalite::photo(){
    const QString str("https://edamam-product-images.s3.amazonaws.com");
        const QString size("SMALL");
        for(size_t i=0;i<data.size();i++){
            if((data.at(i).startsWith(str))&&(size==data.at(i-4))){
                phot01.append(data.at(i));
            }
        }

}
void  Fonctionalite::nomdurecette(){
    const QString st("label");
        const QString dd("uri");
        for(size_t i=0;i<data.size();i++){
            if((st==data.at(i))&&(dd==data.at(i-4))){
                nomdurecette1.append(data.at(i+2));
            }
        }

}
void  Fonctionalite::auteur(){
    const QString st("source");
        for(size_t i=0;i<data.size();i++){
            if((st==data.at(i))){
                auteur1.append(data.at(i+2));
            }
        }

}
void Fonctionalite::lienauteur(){
    const QString st("source");
        for(size_t i=0;i<data.size();i++){
            if((st==data.at(i))){
                lienauteur1.append(data.at(i+6));
             }
        }
}
void Fonctionalite::edaman(){
    const QString st("source");
        for(size_t i=0;i<data.size();i++){
            if((st==data.at(i))){
                edaman1.append(data.at(i+10));
            }
        }

}
void Fonctionalite::cuisinetype(){
    const QString st("cuisineType");
            for(size_t i=0;i<data.size();i++){
                if((st==data.at(i))){
                    cuisinetype1.append(data.at(i+2));
                    }
                }
}
void Fonctionalite::mealtype(){
    const QString st("mealType");
        for(size_t i=0;i<data.size();i++){
            if((st==data.at(i))){
                mealtype1.append(data.at(i+2));
              }
          }
}
void Fonctionalite::dishtype(){
    const QString gg("dishType");
        for(size_t i=0;i<data.size();i++){
            if((gg==data.at(i))){
                dishtype1.append(data.at(i+2));
            }
        }

}
void  Fonctionalite::ingredients(){
    const QString gg("],");
    int y=0;
        const QString jj("ingredientLines");
            for(size_t i=0;i<data.size();i++){
                if((jj==data.at(i))){
                    y++;
                    for (size_t u=i;u<data.size();u++){
                        if (data.at(u)==gg){
                            break;
                        }
                        ingredients1.append(data.at(u));
                    }
                    ingre[y]=ingredients1;
                }
            }


}
void  Fonctionalite::cautions(){
    int y=0;
    const QString gg("],");
            const QString jj("cautions");
                for(size_t i=0;i<data.size();i++){
                    if((jj==data.at(i))){
                        y++;
                        for (size_t u=i;u<data.size();u++){
                            if (data.at(u)==gg){
                                break;
                            }
                            cautions1.append(data.at(u));
                        }
                        cauti[y]=cautions1;
                    }

                }
}
void Fonctionalite::healthlabels(){
    int y=0;
    const QString gg("],");
            const QString jj("healthLabels");
                for(size_t i=0;i<data.size();i++){
                    if((jj==data.at(i))){
                        y++;
                        for (size_t u=i;u<data.size();u++){
                            if (data.at(u)==gg){
                                break;
                            }
                            healthlabels1.append(data.at(u));
                        }
                        health[y]=healthlabels1;
                    }
                }

}
QStringList Fonctionalite::auteuliste(){
    return auteur1;
}
QStringList Fonctionalite::nomdurecettliste(){
    return nomdurecette1;
}
QStringList Fonctionalite::photo1(){
    return phot01;
}
