#ifndef GRAFSHELL_H
#define GRAFSHELL_H


class grafShell
{
public:
    grafShell(int px, int py, double tilt, bool spin);
    void actualizar(int px, int py, int vx, int vy, double mass, double wind = 0);

private:
    int Px, Py, Vx, Vy;
    double Mass, Wind ;
};

#endif // GRAFSHELL_H
