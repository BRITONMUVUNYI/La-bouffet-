#include "Fenetre.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenetre w;
    w.show();
    return a.exec();
}
