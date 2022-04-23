#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "grafWall.h"
#include "grafTurret.h"
#include "grafHowitzer.h"
#include "grafTarget.h"
#include <QLabel>
#include <QPushButton>
#include "grafShell.h"
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QGraphicsView>
#include <QDebug>
#include "signin.h"
#include <QTimer>
#include <list>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inicio();
    void ocultar();
    void dresden();
    void sarajevo();
    void grozni();
    void aleppo();

//protected:
    //void keyPressEvent(QKeyEvent *press);


private slots:
    void registro();
    void mostrar(QString t);
    void rotate();
    void total();
    void disparar();
    void Actualizar();
    void mover();
    void change();

    void on_actionDresden_triggered();

    void on_actionSarajevo_triggered();

    void on_actionGrozni_triggered();

    void on_actionAleppo_triggered();

    void on_actionSalir_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    //grafWall *muro[2];
    grafTurret *turret;
    QPushButton *button[4];
    QLabel *label[5];
    QDoubleSpinBox *spinbox[3];
    QGraphicsView *graphicsview;
    QGroupBox *box;
    //grafShell *shell;
    //grafHowitzer *howitzer;
    //grafTarget *school;
    //grafTarget *tank;
    signin *ventana;
    QTimer *time;
    QTimer *time1;
    QString nivel;
    int i = 0;
    double T, win ;
    bool k = 1;

    list<grafWall *> murosb;
    list<grafWall *> murosg;
    list<grafTarget *> enemies;
    list<grafTarget *> friends;

};
#endif // MAINWINDOW_H
