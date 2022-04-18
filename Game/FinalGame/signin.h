#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <fstream>
#include <map>
#include <QString>
#include "popup.h"
#include <QCloseEvent>

using namespace std;

namespace Ui {
class signin;
}

class signin : public QDialog
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();
    void closeEvent(QCloseEvent *event);

signals:
    void back(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::signin *ui;
    popup *ventana;
    map <string, string> datos;
    map <string, string>::iterator I;
};

#endif // SIGNIN_H
