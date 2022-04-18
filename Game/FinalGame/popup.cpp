#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
    label = new QLabel(this);
}

popup::~popup()
{
    delete ui;
}
