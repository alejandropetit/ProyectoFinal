#include "turret.h"

turret::turret(int px, int py, bool spin)
{
    Px = px, Py = py;
    if(spin)Turret.load(":/images/right.png"), Spin = 0;
    else Turret.load(":/images/left.png"), Spin = 1;
    setPixmap(Turret.scaled(93,75));
    Actualizar(Px,Py,0,Spin);
}

void turret::Actualizar(int px, int py, double tilt, bool spin)
{

    if(Spin != spin){
        if(spin)Turret.load(":/images/right.png");
        else Turret.load(":/images/left.png");
        setPixmap(Turret.scaled(124,100));
    }
    setPos(px,py);
    Px = px, Py = py, Spin = spin;
}
