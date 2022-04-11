#ifndef GRAFTURRET_H
#define GRAFTURRET_H

#include <QGraphicsPixmapItem>

class grafTurret: public QGraphicsPixmapItem
{
public:
    grafTurret(int px, int py, bool spin);

private:
    int Px , Py;
    bool Spin;
    QPixmap Turret;
};

#endif // GRAFTURRET_H
