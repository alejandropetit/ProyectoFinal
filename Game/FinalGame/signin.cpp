#include "signin.h"
#include "ui_signin.h"

signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    ventana =  new popup(this);
    fstream file;
    string letter, word, name;// letter;
    int space = 0;

    file.open("/home/jose/Documentos/GitHub/ProyectoFinal/Game/FinalGame/Registro.txt",fstream::in);
    if(file.is_open()){
        file.seekg (0, file.end);
        unsigned long long length = file.tellg();
        file.seekg (0, file.beg);
        for(unsigned long long i = 0; i < length; i++){
            letter = file.get();
            if(letter == " " && space < 2){//letter == " " && space < 1) || letter == "\n"){
                if(space == 0) name = word, word = "";
                else if(space == 1) datos.insert ( pair<string,string>(name,word) );
                space++;
            }
            else if(letter == "\n")space = 0, word ="";
            else word.append(letter);
        }
    }
    file.close();
}

signin::~signin()
{
    delete ui;
}


void signin::closeEvent( QCloseEvent* event )
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->checkBox->setChecked(false);
    event->accept();
}


void signin::on_pushButton_clicked()
{
    bool k = 1;
    if(ui->checkBox->isChecked()){
        for(I = datos.begin(); I != datos.end(); I++){
            if(I->first == ui->lineEdit->displayText().toStdString()){
                k = 0;
            }
        }
        fstream file;
        file.open("/home/jose/Documentos/GitHub/ProyectoFinal/Game/FinalGame/Registro.txt",fstream::out |fstream::ate| fstream::app);
        if(file.is_open() && k){
            datos.insert ( pair<string,string>(ui->lineEdit->displayText().toStdString(),ui->lineEdit_2->displayText().toStdString()) );
            file << ui->lineEdit->displayText().toStdString() + " " +ui->lineEdit_2->displayText().toStdString()+" 1 0 0 0\n";
            ui->checkBox->setChecked(false);
            file.close();
        }

        else{
            ventana->show();
            ventana->setGeometry(this->x()+75,this->y()+75,250,150);
            ventana->label->setText("este usuario ya ha sido registrado");
            ventana->label->setGeometry(10,20,300,61);
        }
    }
    else{
        for(I = datos.begin(); I != datos.end(); I++){
            if(I->first == ui->lineEdit->displayText().toStdString() && I->second == ui->lineEdit_2->displayText().toStdString()){
              emit(back(ui->lineEdit->displayText()));
            }
            else if(I->first == ui->lineEdit->displayText().toStdString() && I->second != ui->lineEdit_2->displayText().toStdString()){
                ventana->show();
                ventana->setGeometry(this->x()+75,this->y()+75,250,150);
                ventana->label->setText("el usuario o la clave son erroneas");
                ventana->label->setGeometry(10,20,300,61);
            }
        }
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->checkBox->setChecked(false);
}
