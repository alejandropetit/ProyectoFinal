#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "wall.h"
#include "target.h"
#include "turret.h"
#include "howitzer.h"
#include "shell.h"
#include <QKeyEvent>
#include <list>
#include <QPushButton>

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
    void dresden();

protected:
    void keyPressEvent(QKeyEvent *press);

public slots:
    void shoot();
    void move();

private:
    Ui::MainWindow *ui;
    QGraphicsView *graphicsview;
    QGraphicsScene *scene;
    QTimer *time;
    howitzer *Howitzer;
    target *Target;
    shell *Shell;
    turret *Turret;
    list<wall *> muros;
    //list<wall *> murosb;
    list<target *> enemies;
    list<target *> friends;
    QPushButton *button[3];
    double t = 0;

};
#endif // MAINWINDOW_H
