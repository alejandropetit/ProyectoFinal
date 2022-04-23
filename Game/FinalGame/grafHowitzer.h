#ifndef GRAFHOWITZER_H
#define GRAFHOWITZER_H

#include "grafShell.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <math.h>
#include <QGraphicsScene>

class grafHowitzer : public QGraphicsPixmapItem, public QObject
{
public:
    grafHowitzer(int px, int py,double tilt, bool spin, unsigned char efficiency);
    void Actualizar(int px, int py, double tilt ,bool spin, unsigned char efficiency);
    grafShell *bullet;
    double Px, Py, Tilt;


private:
    bool Spin;
    double  vx,vy;
    QString hr = ":/images/howitz_0r.png", hl = ":/images/howitz_0.png";
    QPixmap howitzer ;//= QPixmap(":/imagenes/howitz_0.png");
    QPixmap sh;
    friend class grafTurret;


};

#endif // GRAFHOWITZER_H
