#include "tomarasistencia3.h"
#include "ui_Tomarasistencia3.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <QDebug>
#include <QGroupBox>
#include <QString>
#include <QDate>

Tomarasistencia3::Tomarasistencia3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tomarasistencia3)
{
    ui->setupUi(this);
    contador=0;

    QString consulta;
    consulta.append("SELECT * FROM alumnos WHERE MateriaID=3");
    QSqlQuery query;
    query.prepare(consulta);

    if(query.exec())
    { query.first();
        ui->lineEdit->setText(""+query.value(1).toString()+", "+query.value(2).toString()+"");
        id =query.value(0).toString();
 }

}

Tomarasistencia3::~Tomarasistencia3()
{
    delete ui;
}


void Tomarasistencia3::Siguiente()
{
    contador++;
    Recorrertabla();
    if (ui->lineEdit->text()== ", "){
        ui->lineEdit->setText("No hay Más Alumnos");
        close();
    }

}

void Tomarasistencia3::Recorrertabla()
{
     QString consulta;
     consulta.append("SELECT * FROM alumnos WHERE MateriaID=3");
     QSqlQuery query;
     query.prepare(consulta);

     if(query.exec())
     {

        for (int n = 0; contador >= n++;){

         query.next();
         id = query.value(0).toString();
         ui->lineEdit->setText(""+query.value(1).toString()+", "+query.value(2).toString()+"");
         }
     }

     else{
         qDebug()<<"No se ha podido realizar la consulta";
         qDebug()<<"ERROR" << query.lastError();
     }
}


void Tomarasistencia3::on_pushButton_2_clicked()
{

    if (ui->lineEdit->text() != "No hay Más Alumnos"){

    QString consulta;
    consulta.append("INSERT INTO Asistencias(Fecha,Estado,AlumnoID,MateriaID)"
                    "VALUES("
                    "'"+ui->groupBoxFecha->title()+"',"
                    "'Presente',"
                   "'"+id+"',"
                   "'3'"
                   ");"
                    );

    QSqlQuery insertar;
    insertar.prepare(consulta);

    if (insertar.exec())
    {
        qDebug()<<"Se agregó correctamente";

    }else{
        qDebug()<<"ERROR, no se ha agregado correctamente";
        qDebug()<<"ERROR!"<< insertar.lastError();
    }
    }
    Siguiente();

}

void Tomarasistencia3::on_pushButton_clicked()
{

    if (ui->lineEdit->text() != "No hay Más Alumnos"){

    QString consulta;
    consulta.append("INSERT INTO Asistencias(Fecha,Estado,AlumnoID,MateriaID)"
                    "VALUES("
                    "'"""+ui->groupBoxFecha->title()+"""',"
                    "'Ausente',"
                    "'"+id+"',"
                    "'3'"
                    ");"
                    );

    QSqlQuery insertar;
    insertar.prepare(consulta);

    if (insertar.exec())
    {
        qDebug()<<"Se agregó correctamente";

    }else{
        qDebug()<<"ERROR, no se ha agregado correctamente";
        qDebug()<<"ERROR!"<< insertar.lastError();
    }
    }
    Siguiente();
}

