#include "shell.h"

shell::shell(int px, int py, int vx, int vy, double tilt,double spin, double mass , double wind )
{
    grafshell1 = new grafShell(px, py, tilt, spin);
}

void shell::Actualizar(int px, int py, double tilt,double spin, double mass , double wind)
{

    qDebug() << "si llegue perro";
}

void shell::disparar()
{
    //vx =
    //vy =
    //ax =
    //ay =
    qDebug() << "fuego pa las brujas";
}
