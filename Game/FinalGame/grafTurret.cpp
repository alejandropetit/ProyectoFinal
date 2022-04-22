#include "grafTurret.h"

grafTurret::grafTurret(int px, int py, bool spin)
{
    Px = px, Py = py;
    if(spin)Turret.load(":/images/right.png"), Spin = 0;
    else Turret.load(":/images/left.png"), Spin = 1;
    setPixmap(Turret.scaled(93,75));
    Howitzer = new grafHowitzer(px+20,py+30,0,spin,2);
    Actualizar(px,py,45,spin);
}

void grafTurret::Actualizar(int px, int py, double tilt, bool spin)
{
    if(Spin != spin){
        if(spin)Turret.load(":/images/right.png");
        else Turret.load(":/images/left.png");
        setPixmap(Turret.scaled(124,100));
    }
    setPos(px,py);
    if(spin) Howitzer->Actualizar(px+60,py+60,-tilt,spin,2);
    else Howitzer->Actualizar(px-73,py+60,tilt,spin,2);
    Px = px, Py = py, Spin = spin;
}

void grafTurret::add(QGraphicsScene *scene)
{
    scene->addItem(Howitzer);
    scene->addItem(this);
    scene->addItem(Howitzer->bullet);
}


/*
grafTurret::grafTurret(int px, int py, bool spin)
{
    Px = px, Py = py, Spin = spin;
    if(spin)Turret.load(":/images/right.png");
    else Turret.load(":/images/left.png");
    this->setPos(px, py);
    setPixmap(Turret.scaled(62,50));
    howitzer = new grafHowitzer(px+20,py+30,0,spin,0);
    //howitzer = new grafHowitzer(px+111,py+35,0,spin);
    //shell = new grafShell();
    //howitzer(px+20, py+30, );


}

void grafTurret::add(QGraphicsScene *scene)
{

    scene->addItem(howitzer);
    scene->addItem(this);
    //scene->addItem(howitzer->bullet);


}

void grafTurret::Actualizar(int px, int py, double tilt, bool spin)
{

    if(Spin != spin){
        if(spin)Turret.load(":/images/right.png");
        else Turret.load(":/images/left.png");
        setPixmap(Turret.scaled(62,50));
    }
    setPos(px,py);
    if(spin) howitzer->Actualizar(px+20,py+30,-tilt,spin,2);
    else howitzer->Actualizar(px-49,py+30,tilt,spin,2);//-29


    Px = px, Py = py;
    Spin = spin;
}
*/
