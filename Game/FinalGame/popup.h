#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class popup;
}

class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = nullptr);
    ~popup();


private:
    Ui::popup *ui;
    QLabel *label;
    friend class signin;
};

#endif // POPUP_H
