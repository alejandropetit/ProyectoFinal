#include "signin.h"
#include "ui_signin.h"

signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_clicked()
{
    nombres.push_back("jose");
    nombres.push_back("Daniel");\
    nombres.push_back("dorotea");
    qDebug() << ui->lineEdit->displayText();
    if(ui->lineEdit->displayText() == "jose")
      emit(back(ui->lineEdit->displayText()));
    else qDebug() << "datos incorrectos";
    //std::fstream k;
    //k.open("Registro", std::fstream::in | std::fstream::binary);
    //if(k.is_open()){

    //}

    //for(){
    //    if(ui->lineEdit->displayText() ==)
    //       emit(back(ui->lineEdit->displayText()));
    //    else qDebug() << "datos incorrectos";
    //}
}

