#ifndef GRAFSHELL_H
#define GRAFSHELL_H

#include <QGraphicsPixmapItem>


class grafShell: public QGraphicsPixmapItem
{
public:
    grafShell(int px, int py, double tilt, bool spin);
    void Actualizar( int px, int py , double tilt,bool spin);
    void move(double T);
    void values(double joules, double mass, double tilt);
    void Velocities(double v);
    void explosion();
    double Px, Py, Vx = 40, Vy = -40;
    int a = 0;

private:
    double Tilt;
    bool Spin;
    QPixmap Shell;

};
#endif // GRAFSHELL_H


