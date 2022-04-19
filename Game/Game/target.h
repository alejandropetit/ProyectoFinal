#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class target: public QGraphicsPixmapItem, public QObject
{
public:
    target(int px, int py, int image, int movepattern, double tilt, double enemy, int interval);
    void move(double T);

private:
    int MovePattern, count = 1, Interval;
    double Vx = 6, Vy = -20, Px, Py, V = 6;
    QPixmap  Target;
};

#endif // TARGET_H
