#include "grafHowitzer.h"

grafHowitzer::grafHowitzer(int px, int py,double tilt, bool spin, unsigned char efficiency)
{
    tilt = -tilt;
    Px = px, Py = py, Tilt = tilt;
    howitzer.load(hr);
    if(spin)Spin = 0;
    else Spin = 1;
    bullet = new grafShell(px,py,tilt,spin);
    Actualizar(px, py, tilt, spin, efficiency);


}


void grafHowitzer::Actualizar(int px, int py, double tilt, bool spin, unsigned char efficiency)
{
    if(efficiency == 0) hr = ":/images/howitz_0r.png", hl = ":/images/howitz_0.png";
    else if(efficiency == 1) hr = ":/images/howitz_1r.png", hl = ":/images/howitz_1.png";
    else if(efficiency == 2) hr = ":/images/howitz_2r.png", hl = ":/images/howitz_2.png";
    else if(efficiency == 3) hr = ":/images/howitz_3r.png", hl = ":/images/howitz_3.png";
    if(Spin != spin){
        if(spin) howitzer.load(hr);
        else howitzer.load(hl);
        setPixmap(howitzer.scaled(137,30));
    }
    if(spin){
        this->setTransformOriginPoint(0,0);
        this->setRotation(tilt);
    }
    else{
        this->setTransformOriginPoint(137,0);
        this->setRotation(tilt);
    }
    bullet->Actualizar(px,py,tilt,spin);
    Px = px, Py = py, Spin = spin, Tilt = tilt;
    this->setPos(px,py);
}




