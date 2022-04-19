#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "howitzer.h"

class turret: public QGraphicsPixmapItem
{
public:
    turret(int px, int py, bool spin);
    void Actualizar(int px, int py, double tilt, bool spin);
    void add(QGraphicsScene *scene);

private:
    int Px, Py, Spin;
    QPixmap Turret;
    howitzer *Howitzer;
};

#endif // TURRET_H
