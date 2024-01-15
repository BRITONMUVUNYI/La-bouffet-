#include "Fenetre.h"
#include "./ui_Fenetre.h"
#include <QDebug>
#include "fonctionalite.h"
#include <QLabel>
#include <QPushButton>
#include <QtWidgets>

using namespace std;
Fenetre::Fenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fenetre)
{
    ui->setupUi(this);

}

Fenetre::~Fenetre()
{
    delete ui;
}
QGridLayout *Layout=new  QGridLayout;
int compteur=0;
void Fenetre::input(){
    QNetworkAccessManager * manager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&Fenetre::display );
    QString request = url + "?type=public&q=" +reqentre()  + "&app_id=" + appid + "&app_key=" + apikey;
    const QUrl url(request);
    QNetworkRequest REQ(url);
    manager->get(REQ);


}
void Fenetre::display(QNetworkReply *reply){

    QByteArray responseData = reply->readAll();

    // Assuming the response is in plain text, you can treat it as a QString
    QString treatedData = QString::fromUtf8(responseData);

    Fonctionalite f;
    f.decoupage(treatedData);
   //ui->label1->setText(data);
   //POUR LES URL DES PHOTOS
   // const QString str("https://edamam-product-images.s3.amazonaws.com");
   // const QString size("REGULAR");
   // for(size_t i=0;i<data.size();i++){
   //     if((data.at(i).startsWith(str))&&(size==data.at(i-4))){
   //         qDebug()<<data.at(i);
   //     }
   // }
   //POUR LES NOMS DES RECETTES
   // const QString st("label");
   // const QString dd("uri");
   // for(size_t i=0;i<data.size();i++){
   //     if((st==data.at(i))&&(dd==data.at(i-4))){
   //         qDebug()<<data.at(i+2);
   //     }
   // }
    // for(const QString part:data){

    //            qDebug()<<part;

    //    }
    //QGridLayout *Layout=new  QGridLayout;
    f.nomdurecette();
    f.photo();
   //pour la source
   // const QString st("source");
   // for(size_t i=0;i<data.size();i++){
   //     if((st==data.at(i))){
   //         qDebug()<<data.at(i+2);
   //     }
   // }
   //pour la source de l'auteur
    // const QString st("source");
    //     for(size_t i=0;i<data.size();i++){
    //         if((st==data.at(i))){
    //             qDebug()<<data.at(i+6);
    //          }
    //     }
   //pour le base de donnees edaman
   // const QString st("source");
   //     for(size_t i=0;i<data.size();i++){
   //         if((st==data.at(i))){
   //             qDebug()<<data.at(i+10);
   //         }
   //     }
   //cuisine type
    // const QString st("cuisineType");
    //     for(size_t i=0;i<data.size();i++){
    //         if((st==data.at(i))){
    //           qDebug()<<data.at(i+2);
    //             }
    //         }
   //mealType
    // const QString st("mealType");
    // for(size_t i=0;i<data.size();i++){
    //     if((st==data.at(i))){
    //         qDebug()<<data.at(i+2);
    //       }
    //   }
    //dishType
    // const QString gg("dishType");
    // for(size_t i=0;i<data.size();i++){
    //     if((gg==data.at(i))){
    //         qDebug()<<data.at(i+2);
    //     }
    // }
   //ingredients
   // const QString gg("],");
   // const QString jj("ingredientLines");
   //     for(size_t i=0;i<data.size();i++){
   //         if((jj==data.at(i))){
   //             for (size_t u=i;u<data.size();u++){
   //                 if (data.at(u)==gg){
   //                     break;
   //                 }
   //                 qDebug()<<data.at(u);
   //             }
   //         }
   //     }\
   //cautions pour les allergies
   // const QString gg("],");
   //     const QString jj("cautions");
   //         for(size_t i=0;i<data.size();i++){
   //             if((jj==data.at(i))){
   //                 for (size_t u=i;u<data.size();u++){
   //                     if (data.at(u)==gg){
   //                         break;
   //                     }
   //                     qDebug()<<data.at(u);
   //                 }
   //             }
   //         }
   //pour healthlabels

   // const QString gg("],");
   //     const QString jj("healthLabels");
   //         for(size_t i=0;i<data.size();i++){
   //             if((jj==data.at(i))){
   //                 for (size_t u=i;u<data.size();u++){
   //                     if (data.at(u)==gg){
   //                         break;
   //                     }
   //                     qDebug()<<data.at(u);
   //                 }
   //             }
   //         }



    // Layout->addWidget(ui->label,0,0,Qt::AlignTop | Qt::AlignLeft);
    // Layout->addWidget(ui->text,0,1,Qt::AlignTop | Qt::AlignLeft);
    // Layout->addWidget(ui->pushButton,0,2,Qt::AlignTop | Qt::AlignLeft);
    // // for(int i=0;i<f.photo1().size();i++){
    // //     QLabel * label=new QLabel("  ",this);

    // //     Layout->addWidget(label,2, i, Qt::AlignTop | Qt::AlignLeft);
    // // }
    // //nom du recette;
    for(int i=0;i<f.nomdurecettliste().size();i++){
        QPushButton *button=new QPushButton(f.nomdurecettliste()[i],this);
        Layout->addWidget(button,0, (i%4)+100, Qt::AlignTop | Qt::AlignLeft);
        networkImage(f.photo1(),i);
    }
    // QWidget *centralWidget = new QWidget(this);
    // centralWidget->setLayout(Layout);
    // setCentralWidget(centralWidget);
    placement();

}

QString Fenetre::reqentre(){
    return ui->text->text();
}
void Fenetre::networkImage(const QStringList &phot01,int it){

        QNetworkAccessManager *manag=new QNetworkAccessManager(this);
        connect(manag,&QNetworkAccessManager::finished,this,&Fenetre::displayimage);
        const QUrl url1(phot01.at(it));
        QNetworkRequest req(url1);
        manag->get(req);
        // QLabel * label=new QLabel("  ",this);

        // Layout->addWidget(label,2, i, Qt::AlignTop | Qt::AlignLeft);
        //qDebug()<<"PHOTO"<<phot01.at(i);

    //placement();


}
void Fenetre::displayimage(QNetworkReply *image){
    QPixmap pic;
    pic.loadFromData(image->readAll());
   QLabel * label=new QLabel(" yess ",this);
    pic = pic.scaled(150,100, Qt::KeepAspectRatio);
    label->setPixmap(pic);
    // int compteurcol=(compteur%4)*10;
    //label->resize(50,50);
    Layout->addWidget(label,compteur/4,compteur%4,Qt::AlignTop | Qt::AlignLeft);
    compteur=compteur+1;
   // // qDebug()<<label->width()<<" "<<label->height();

  }
void Fenetre::placement(){
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(Layout);
    setCentralWidget(centralWidget);
}
