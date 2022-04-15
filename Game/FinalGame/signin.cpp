#include "signin.h"
#include "ui_signin.h"

signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    fstream file;
    string letter, word, name;// letter;
    int space = 0;


    file.open("/home/jose/Documentos/GitHub/ProyectoFinal/Game/FinalGame/Registro.txt",fstream::in | fstream::binary);
    if(file.is_open()){
        file.seekg (0, file.end);
        unsigned long long length = file.tellg();
        file.seekg (0, file.beg);
        for(unsigned long long i = 0; i < length; i++){
            letter = file.get();
            if(letter == " " && space < 1 || letter == "\n"){
                if(space == 0) name = word, word = "";
                if(letter == "\n") datos.insert ( pair<string,string>(name,word) ), word = "", space = 0;
                space++;
            }
            else word.append(letter);
        }
    }
    file.close();
}

signin::~signin()
{
    delete ui;
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
            file << ui->lineEdit->displayText().toStdString() + " " +ui->lineEdit_2->displayText().toStdString()+"\n";
            ui->checkBox->setChecked(false);
        }
        else{

        }
    }
    else{
        for(I = datos.begin(); I != datos.end(); I++){
            if(I->first == ui->lineEdit->displayText().toStdString() && I->second == ui->lineEdit_2->displayText().toStdString())
              emit(back(ui->lineEdit->displayText()));
        }
        qDebug() << "datos incorrectos";
    }

}

