#include "agregar1.h"
#include "ui_agregar1.h"
#include "gestionalumnos/gestionalumnos1.h"
#include "QMessageBox"
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <QSqlRecord>
#include <QPlainTextEdit>

Agregar1::Agregar1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar1)
{
    ui->setupUi(this);
}

Agregar1::~Agregar1()
{
    delete ui;
}



void Agregar1::obtenerValores(QString &nombre, QString &apellido)
{
    nombre = ui->lineEditNombre->text();
    apellido = ui->lineEditApellido->text();


}
void Agregar1::Insertaralumno()
{
    QString consulta;
    consulta.append("INSERT INTO Alumnos(Nombre,Apellido,MateriaID)"
                    "VALUES("
                    "'"+ui->lineEditNombre->text()+"',"
                    "'"+ui->lineEditApellido->text()+"',"
                    "'1'"
                    ");"
                    );

    QSqlQuery insertar;
    insertar.prepare(consulta);

    if (insertar.exec())
    {   ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText(""+ui->lineEditNombre->text()+", "+ui->lineEditApellido->text()+" Se Agregó Correctamente");
        ui->lineEditApellido->setText("");
        ui->lineEditNombre->setText("");
        qDebug()<<"Se agregó correctamente";

    }else{
        qDebug()<<"ERROR, no se ha agregado correctamente";
        qDebug()<<"ERROR!"<< insertar.lastError();
    }
}



void Agregar1::on_lineEditNombre_cursorPositionChanged()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Ingrese Los Datos");

}

void Agregar1::on_lineEditApellido_cursorPositionChanged()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Ingrese Los Datos");
}

void Agregar1::on_pushButton_clicked()
{
    IdExiste();
    if (_Id == "NOTNULL"){
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Los Datos Ingresados Ya están En la Base de Datos / Hay Campos Vacíos");}
    else {
        QString N = ui->lineEditNombre->text();
        QString A = ui->lineEditApellido->text();
        if (ui->lineEditNombre->text() != "" && ui->lineEditApellido->text() != ""){
            Insertaralumno();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->appendPlainText(""+N+", "+A+" Se Agregó Correctamente");
        }
        else {  ui->plainTextEdit->clear();
                ui->plainTextEdit->appendPlainText("Nombre o Apellido está incompleto");}
    }
}

void Agregar1::IdExiste()
{
    _Id = "";
    QString consulta;
    consulta.append("SELECT * FROM alumnos WHERE MateriaID=1");
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
    }
}
