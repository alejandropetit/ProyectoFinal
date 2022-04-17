#ifndef GRAFSHELL_H
#define GRAFSHELL_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>


class grafShell: public QObject, public QPixmap, public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    grafShell(int px, int py, double tilt, bool spin);
    void Actualizar( int px, int py , double tilt,bool spin);
    void move(double T);



private:
    double Px , Py , Spin;
    double Tilt;
    double Vx = 20, Vy =-40;
    double Mass, Wind ;
    QPixmap kugeln;

};

#endif // GRAFSHELL_H
