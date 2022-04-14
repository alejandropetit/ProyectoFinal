#include "grafTurret.h"

grafTurret::grafTurret(int px, int py, bool spin)
{
    Px = px, Py = py, Spin = spin;
    if(spin)Turret.load(":/images/right.png");
    else Turret.load(":/images/left.png");
    this->setPos(px, py);
    setPixmap(Turret.scaled(62,50));
}

