#include "shell.h"

shell::shell(int px, int py, double tilt, bool spin)
{
    Px = px, Py = py, Tilt = tilt, Spin = spin;
    Shell.load(":/images/shell.png");
    setPixmap(Shell.scaled(28,6));
    Actualizar(px+13,py+38,tilt,spin);
    //Actualizar(px-213,py+42,tilt,spin);
}

void shell::Actualizar(int px, int py, double tilt, bool spin)
{
    Px = px+109*cos((tilt+4)*M_PI/180), Py = py+109*sin((tilt+4)*M_PI/180);
    this->setRotation(tilt);
    this->setPos(Px,Py);
}

void shell::move(double T)
{
    double ax = 0, ay = 9.8;
    if(Py < 500){
        Vx = Vx + (ax*T);
        Vy = Vy + (ay*T);
        Px = Px + (Vx*T);
        Py = Py + (Vy*T);
        if(Vx>=0) this->setRotation(atan(Vy/Vx)*180/M_PI);
        else this->setRotation(atan(Vy/Vx)*180/M_PI+180);
    }
    this->setPos(Px,Py);
}
