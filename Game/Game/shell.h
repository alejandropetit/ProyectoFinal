#ifndef SHELL_H
#define SHELL_H

#include <QGraphicsPixmapItem>

class shell: public QGraphicsPixmapItem
{
public:
    shell(int px, int py, double tilt, bool spin);
    void Actualizar( int px, int py , double tilt,bool spin);
    void move(double T);
    double Px, Py, Vx = 10, Vy = -10;

private:
    double Tilt;
    bool Spin;
    QPixmap Shell;

};

#endif // SHELL_H
