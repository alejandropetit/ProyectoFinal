#include "grafTurret.h"

grafTurret::grafTurret(int px, int py, bool spin)
{
    Px = px, Py = py, Spin = spin;
    if(spin)Turret.load(":/images/right.png");
    else Turret.load(":/images/left.png");
    this->setPos(px, py);
    setPixmap(Turret.scaled(62,50));
    howitzer = new grafHowitzer(px+20,py+30,0,spin);
    //shell = new grafShell();
    //howitzer(px+20, py+30, );


}

void grafTurret::add(QGraphicsScene *scene)
{

    scene->addItem(howitzer);
    scene->addItem(this);

}

void grafTurret::Actualizar(int px, int py, double tilt, bool spin)
{
    howitzer->Actualizar(px,py,-tilt,spin);
}

