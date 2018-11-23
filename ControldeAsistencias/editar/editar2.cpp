#include "editar2.h"
#include "ui_editar2.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <QMessageBox>
#include "ui_gestionalumnos2.h"
#include "gestionalumnos/gestionalumnos2.h"
#include <QPlainTextEdit>




Editar2::Editar2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editar2)
{
    ui->setupUi(this);

}

Editar2::~Editar2()
{
    delete ui;
}

void Editar2::IdExiste()
{
    _Id = "";
    QString consulta;
    consulta.append("SELECT * FROM alumnos WHERE MateriaID=2");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    if(consultar.exec())
    {
        qDebug()<<"Se ha consultado correctamente";
    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << consultar.lastError();
    }

    while(consultar.next()){

        if (ui->lineEditApellido->text()==consultar.value(1).toString() &&
            ui->lineEditNombre->text()==consultar.value(2).toString()    )
        {   _Id = "NOTNULL";
            qDebug()<<"EL ID EXISTE";}

        qDebug()<<"DATO 1" << ui->lineEditApellido->text();
        qDebug()<<"DATO 2" << ui->lineEditNombre->text();
        qDebug()<<"DATO 1" << consultar.value(1).toString();
        qDebug()<<"DATO 2" << consultar.value(2).toString();



    }
}

void Editar2::IdExiste1()
{
    _Idselection = ""+ui->plainTextEdit->toPlainText()+"";
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("El ID Seleccionado es :"+_Idselection+"");
    _Id1 = "";
    QString consulta;
    consulta.append("SELECT * FROM alumnos WHERE MateriaID=2");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    if(consultar.exec())
    {
        qDebug()<<"Se ha consultado correctamente";
    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << consultar.lastError();
    }

    while(consultar.next()){

        if (_Idselection == consultar.value(0).toString())
        {   _Id1 = "NOTNULL";
            qDebug()<<"EL ID EXISTE";}
    }
}


void Editar2::on_pushButton_clicked()
{
    if (_Id1 == "NOTNULL"){
    IdExiste();
    if (_Id == "NOTNULL"){
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Los Datos Ingresados Ya están En la Base de Datos / Hay Campos Vacíos");}
    else {
        if (ui->lineEditNombre->text() != "" && ui->lineEditApellido->text() != ""){


        QString consulta;
        consulta.append ("UPDATE 'Alumnos' SET 'Nombre' = '"+ui->lineEditNombre->text()+"',"
                         "'Apellido' ='"+ui->lineEditApellido->text()+"'WHERE 'Alumnos'.'AlumnoID'="+_Idselection+";");

        QSqlQuery actualizar;
            actualizar.prepare(consulta);

            if(actualizar.exec()){
                qDebug()<<"Se ha actualizado correctamente.";
                close();

            } else {
                qDebug()<<"No se ha podido actualizar.";
                qDebug()<<"Se ha producido un ERROR" << actualizar.lastError();

            }}
        else {ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText("Nombre o Apellido está incompleto");}
}}
else {ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Error Vuelva a la Pantalla Anterior y Seleccione una Fila");}

}
