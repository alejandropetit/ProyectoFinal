#ifndef GRAFHOWITZER_H
#define GRAFHOWITZER_H

//#define W ":/imagenes/howitz_0.png"
//#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <math.h>

class grafHowitzer : public QGraphicsPixmapItem, public QObject
{
public:
    grafHowitzer(int px, int py, double tilt, bool spin);
    void Actualizar(int px, int py, double tilt ,bool spin);
    void mejorar();

private slots:
    void rotate(double tilt);


private:
    int Px , Py , Spin;
    double Tilt;
    QPixmap howitzer ;//= QPixmap(":/imagenes/howitz_0.png");


};

#endif // GRAFHOWITZER_H
