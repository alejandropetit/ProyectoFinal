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
    Px = px+77*cos((-tilt-5)*M_PI/180), Py = py-77*sin((-tilt-5)*M_PI/180);
    this->setRotation(tilt);
    this->setPos(Px,Py);
}

void grafShell::move( double T)
{
    //qDebug() << "maria";
    double ax = 0, ay = 9.8;
    Vx = Vx + (ax*T);
    Vy = Vy + (ay*T);
    Px = Px + (Vx*T);
    Py = Py + (Vy*T);
    this->setPos(Px,Py);
}

void grafShell::d(double mass, double joules, double tilt)
{
    Vx = sqrt((2*joules/mass)*cos(tilt));
    Vy = -sqrt((2*joules/mass)*sin(tilt));
}


