#ifndef GRAFHOWITZER_H
#define GRAFHOWITZER_H

//#define W ":/imagenes/howitz_0.png"
//#include <QGraphicsItem>
#include "grafShell.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <math.h>
#include <QGraphicsScene>

class grafHowitzer : public QGraphicsPixmapItem, public QObject
{
public:
    grafHowitzer(int px, int py,double tilt, bool spin, unsigned char efficiency);
    //int px, int py, double joules, double shellMass,double tilt, bool spin, unsigned char efficiency
    void Actualizar(int px, int py, double tilt ,bool spin, unsigned char efficiency);
    void shoot(QGraphicsScene *scene,double mass, double joules, double tilt, double T);
    grafShell *bullet;


private:
    //grafShell *bullet;
    double Px , Py ;
    bool Spin;
    double Tilt, vx,vy;
    QString hr = ":/images/howitz_0r.png", hl = ":/images/howitz_0.png";
    QPixmap howitzer ;//= QPixmap(":/imagenes/howitz_0.png");
    QPixmap sh;
    friend class grafTurret;


};

#endif // GRAFHOWITZER_H
