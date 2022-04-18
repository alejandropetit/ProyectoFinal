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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ocultar();
    void nivel();
    void dresden();
    void sarajevo();
    void grozni();
    void aleppo();

protected:
    void keyPressEvent(QKeyEvent *press);


private slots:
    void registro();
    void mostrar(QString t);
    void rotate();
    void total();
    void disparar();
    void Actualizar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    grafWall *muro[2];
    grafTurret *turret;
    QPushButton *button[3];
    QLabel *label[5];
    QDoubleSpinBox *spinbox[3];
    QGraphicsView *graphicsview;
    QGroupBox *box;
    grafShell *shell;
    grafHowitzer *howitzer;
    grafTarget *school;
    grafTarget *tank;
    signin *ventana;
    QTimer *time;
    int i = 1;
    double T ;

};
#endif // MAINWINDOW_H
