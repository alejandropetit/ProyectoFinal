#include "grafHowitzer.h"

grafHowitzer::grafHowitzer(int px, int py,double tilt, bool spin, unsigned char efficiency)
{
    tilt = -tilt;
    Px = px, Py = py, Tilt = tilt;
    howitzer.load(hr);
    if(spin)Spin = 0;
    else Spin = 1;
    bullet = new grafShell(px+91,py+5,tilt,spin);
    Actualizar(px, py, tilt, spin, efficiency);
}


void grafHowitzer::Actualizar(int px, int py, double tilt, bool spin, unsigned char efficiency)
{
    qDebug() << "PIPO";
    if(efficiency == 0) hr = ":/images/howitz_0r.png", hl = ":/images/howitz_0.png";
    else if(efficiency == 1) hr = ":/images/howitz_1r.png", hl = ":/images/howitz_1.png";
    else if(efficiency == 2) hr = ":/images/howitz_2r.png", hl = ":/images/howitz_2.png";
    else if(efficiency == 3) hr = ":/images/howitz_3r.png", hl = ":/images/howitz_3.png";
    if(Spin != spin){
        if(spin) howitzer.load(hr);
        else howitzer.load(hl);
        setPixmap(howitzer.scaled(91,20));
    }
    if(spin){
        this->setTransformOriginPoint(0,0);
        this->setRotation(tilt);
    }
    else{
        this->setTransformOriginPoint(91,0);
        this->setRotation(tilt);
    }
    Px = px, Py = py, Spin = spin, Tilt = tilt;
    this->setPos(px,py);
    bullet->Actualizar(px,py,tilt,spin);//+91,py+5,tilt,spin);

}

void grafHowitzer::shoot(double mass, double joules, double tilt, double T)
{
    vx = (2*joules)/(mass*cos(tilt));
    vy = (2*joules)/(mass*sin(tilt));
    //bullet -> move(T);



}


