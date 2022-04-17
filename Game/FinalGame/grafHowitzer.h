#ifndef GRAFHOWITZER_H
#define GRAFHOWITZER_H

//#define W ":/imagenes/howitz_0.png"
//#include <QGraphicsItem>
#include "grafShell.h"
#include "shell.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <math.h>

class grafHowitzer : public QGraphicsPixmapItem, public QObject
{
public:
    grafHowitzer(int px, int py, double tilt, bool spin);
    //int px, int py, double joules, double shellMass,double tilt, bool spin, unsigned char efficiency
    void Actualizar(int px, int py, double tilt ,bool spin);
    void mejorar();
    //shell *bullet;
    grafShell *bullet;

private slots:
    void rotate(double tilt);


private:
    //grafShell *bullet;
    int Px , Py , Spin;
    double Tilt;
    QString hr = ":/images/howitz_0r.png", hl = ":/images/howitz_0.png";
    QPixmap howitzer ;//= QPixmap(":/imagenes/howitz_0.png");
    QPixmap sh;
    friend class grafTurret;


};

#endif // GRAFHOWITZER_H
