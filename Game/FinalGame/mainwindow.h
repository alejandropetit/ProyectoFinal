#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "grafWall.h"
#include "grafTurret.h"
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QGraphicsView>
#include "signin.h"


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


private slots:
    void registro();
    void mostrar(QString t);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    grafWall *muro;
    grafTurret *turret;
    QPushButton *button[3];
    QLabel *label[5];
    QDoubleSpinBox *spinbox[3];
    QGraphicsView *graphicsview;
    signin *ventana;

};
#endif // MAINWINDOW_H
