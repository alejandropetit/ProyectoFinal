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
    void move( double T);
    void d(double mass, double joules, double tilt);



private:
    double Px , Py;
    bool Spin;
    double Tilt;
    double Vx = 20, Vy =-40;
    double Mass, Wind ;
    QString br, bl;
    QPixmap kugeln;

};

#endif // GRAFSHELL_H
