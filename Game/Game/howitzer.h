#ifndef HOWITZER_H
#define HOWITZER_H

#include <QGraphicsPixmapItem>

class howitzer: public QGraphicsPixmapItem
{
public:
    howitzer(int px, int py,double tilt, bool spin, unsigned char efficiency);
    void Actualizar(int px, int py, double tilt ,bool spin, unsigned char efficiency);

private:
    bool Spin;
    double Px, Py, Tilt;
    unsigned char Efficiency;
    QString hr = ":/images/howitz_0r.png", hl = ":/images/howitz_0.png";
    QPixmap Howitzer ;
};

#endif // HOWITZER_H
