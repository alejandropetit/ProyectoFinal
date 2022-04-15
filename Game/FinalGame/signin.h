#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <list>
#include <fstream>
#include <map>
#include <QString>

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

signals:
    void back(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::signin *ui;
    std::list<QString> nombres;
    map <string, string> datos;
    map <string, string>::iterator I;
};

#endif // SIGNIN_H
