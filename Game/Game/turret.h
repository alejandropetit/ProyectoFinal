#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsPixmapItem>

class turret: public QGraphicsPixmapItem
{
public:
    turret(int px, int py, bool spin);
    void Actualizar(int px, int py, double tilt, bool spin);

private:
    int Px, Py, Spin;
    QPixmap Turret;
};

#endif // TURRET_H
