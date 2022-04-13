#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

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
};

#endif // SIGNIN_H
