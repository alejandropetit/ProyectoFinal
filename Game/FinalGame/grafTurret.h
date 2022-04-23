#ifndef GRAFTURRET_H
#define GRAFTURRET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "grafHowitzer.h"

class grafTurret: public QGraphicsPixmapItem
{
public:
    grafTurret(int px, int py, bool spin);
    void Actualizar(int px, int py, double tilt, bool spin);
    void add(QGraphicsScene *scene);
    grafHowitzer *Howitzer;
    int Px, Py, Spin;

private:
    QPixmap Turret;
};
#endif // GRAFTURRET_H

