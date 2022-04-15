#ifndef SHELL_H
#define SHELL_H

#include "grafShell.h"
#include <QDebug>

class shell
{
public:
    shell(int px, int py, int vx, int vy,double tilt, double spin, double mass, double wind = 0);
    void Actualizar(int px, int py, double tilt,double spin, double mass , double wind);
    void disparar();

private:
    grafShell *grafshell1;
};

#endif // SHELL_H
