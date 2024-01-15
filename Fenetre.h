#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class Fenetre;
}
QT_END_NAMESPACE

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    Fenetre(QWidget *parent = nullptr);
    ~Fenetre();
    QString reqentre();
    void networkImage(const QStringList &phot01,int it);
    void placement();
private slots:
    void input();
    void display(QNetworkReply *reply);
    void displayimage(QNetworkReply *image);

private:
    Ui::Fenetre *ui;
    QString url="https://api.edamam.com/api/recipes/v2";
    QString appid="";
    QString apikey="";
    //QVBoxLayout *Layout;
};
#endif // FENETRE_H
