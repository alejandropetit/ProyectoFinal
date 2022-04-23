#ifndef GRAFTARGET_H
#define GRAFTARGET_H

#include <QGraphicsPixmapItem>

class grafTarget: public QGraphicsPixmapItem
{
public:
    grafTarget(int px, int py, int image, int movepattern, double tilt, double enemy, int interval);
    void move(double T);

private:
    int MovePattern, count = 1, count1 = 0 ,Interval;
    double  V = 30, Px, Py, Px_, Py_,Vx, Vy, Tilt;
    QPixmap  Target;
};
#endif // GRAFTARGET_H


