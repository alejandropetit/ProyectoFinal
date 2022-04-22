#include "grafShell.h"
grafShell::grafShell(int px, int py, double tilt, bool spin)
{
    Px = px, Py = py, Tilt = tilt, Spin = spin;
    Shell.load(":/images/shell.png");

    setPixmap(Shell.scaled(28,6));
    Actualizar(px+13,py+38,tilt,spin);
    //Actualizar(px-213,py+42,tilt,spin);
}

void grafShell::Actualizar( int px, int py , double tilt,bool spin)
{
    Px = px+137*cos((tilt+3)*M_PI/180), Py = py+137*sin((tilt+3)*M_PI/180);
    this->setRotation(tilt);
    this->setPos(Px,Py);
}

void grafShell::move( double T)
{
    double ax = 0, ay = 9.8;
    if(Py < 600){
        Vx = Vx + (ax*T);
        Vy = Vy + (ay*T);
        Px = Px + (Vx*T);
        Py = Py + (Vy*T);
        if(Vx>=0) this->setRotation(atan(Vy/Vx)*180/M_PI);
        else this->setRotation(atan(Vy/Vx)*180/M_PI+180);
    }
    this->setPos(Px,Py);
}

void grafShell::values(double joules, double mass, double tilt)
{
    Vx = sqrt((2*0.1*joules/mass)*cos(tilt));
    Vy = -sqrt((2*0.1*joules/mass)*sin(tilt));
}

void grafShell::explosion()
{
    Shell.load(":/images/explosion.png");
    a++;
    setPixmap(Shell.copy(a,0,79,79));
}

/*
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
*/

