#include "grafHowitzer.h"

grafHowitzer::grafHowitzer(int px, int py, double tilt, bool spin)
{
    Px = px, Py = py, Tilt = tilt, Spin = spin;
    howitzer.load(hr);
    //sh.load(":/images/shell.png");
    bullet = new grafShell(px+91,py+5,tilt,spin);
    //this->setPos(px,py);
    setPixmap(howitzer.scaled(91,20));
    this->setPos(px,py);
    //setPixmap(sh.scaled(14,3));
    //bullet = new shell(px, py, 0, 0,0);
}


void grafHowitzer::Actualizar(int px, int py, double tilt, bool spin)
{
    qDebug() << "PIPO";
    double tilt1 = tilt;
    tilt =  tilt - Tilt , Tilt = tilt1;
    tilt = tilt * M_PI/180;
    this->setTransformOriginPoint(169,130);
    this->setTransform(QTransform(cos(tilt), sin(tilt), -sin(tilt), cos(tilt), px-Px, py-Py),true);
    if(Spin != spin){
        if(spin) howitzer.load(hr);
        else howitzer.load(hl);
        setPixmap(howitzer.scaled(91,20));
    }
    Px = px, Py = py;
    Spin = spin;
    //this->setPos(px,py);

}

void grafHowitzer::mejorar()
{

}

void grafHowitzer::rotate(double tilt)
{


}
