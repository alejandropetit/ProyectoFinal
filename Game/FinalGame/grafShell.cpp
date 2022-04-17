#include "grafShell.h"

grafShell::grafShell(int px, int py, double tilt, bool spin)
{
    Px = px, Py = py, Tilt = tilt, Spin = spin;
    kugeln.load(":/images/shell.png");
    setPixmap(kugeln.scaled(14,3));
    this->setPos(px-14,py);
}

void grafShell::Actualizar( int px, int py , double tilt,bool spin)
{
    double tilt1 = tilt;
    tilt =  tilt - Tilt , Tilt = tilt1;
    tilt = tilt * M_PI/180;
    Px = 120+77*cos((Tilt-5)*M_PI/180), Py = 130-77*sin((Tilt-5)*M_PI/180);
    this->setPos(Px,Py);
    this->setTransform(QTransform(cos(-tilt), sin(-tilt), -sin(-tilt), cos(-tilt), 0, 0),true);
}

void grafShell::move(double T)
{
    qDebug() << "maria";
    double ax = 0, ay = 9.8;//9;
    Vx = Vx + (ax*T);
    Vy = Vy + (ay*T);
    Px = Px + (Vx*T);
    Py = Py + (Vy*T);
    this->setPos(Px,Py);
}


