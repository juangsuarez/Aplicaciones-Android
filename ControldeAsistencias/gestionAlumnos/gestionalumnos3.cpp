#include "gestionalumnos/gestionalumnos3.h"
#include "ui_gestionalumnos3.h"
#include <QDebug>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <QMessageBox>
#include <QVariant>
#include <QString>
#include <QDialog>

Gestionalumnos3::Gestionalumnos3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestionalumnos3)
{
    ui->setupUi(this);
    Mostrardatos();
}

Gestionalumnos3::~Gestionalumnos3()
{
    delete ui;
}


void Gestionalumnos3::Mostrardatos()
{
    QString consulta;
    consulta.append("SELECT * FROM alumnos WHERE MateriaID=3");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    if(consultar.exec())
    {
        qDebug()<<"Se ha consultado correctamente";
    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << consultar.lastError();
    }

    int fila = 0;

    //limpia la tabla
    ui->tableWidgetDatos->setRowCount(0);

    while(consultar.next()){

        QTableWidgetItem *columna1 = new QTableWidgetItem(consultar.value(0).toByteArray().constData());
        columna1->setTextAlignment (Qt :: AlignCenter);
        columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura

        QTableWidgetItem *columna2= new QTableWidgetItem(consultar.value(1).toByteArray().constData());
        columna2->setTextAlignment (Qt :: AlignCenter);
        columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura

        QTableWidgetItem *columna3 = new QTableWidgetItem(consultar.value(2).toByteArray().constData());
        columna3->setTextAlignment (Qt :: AlignCenter);
        columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura


        ui->tableWidgetDatos->insertRow(fila);
        ui->tableWidgetDatos->setItem(fila,0,columna1);
                                      //new QTableWidgetItem(consultar.value(0).toByteArray().constData()));

        ui->tableWidgetDatos->setItem(fila,1,columna2);
                                   //   new QTableWidgetItem(consultar.value(1).toByteArray().constData()));

        ui->tableWidgetDatos->setItem(fila,2,columna3);
                                  //    new QTableWidgetItem(consultar.value(2).toByteArray().constData()));
        fila++;
    }
}
void Gestionalumnos3::Eliminaralumno()
{

    int id_alumno = Obteneridalumno();
    qDebug()<<"El id del alumno seleccionado es: " << id_alumno;
    QString consulta;

    consulta.append("DELETE FROM 'Alumnos' WHERE 'Alumnos'.'AlumnoID' = " + QString::number(id_alumno));

    QSqlQuery eliminar;
    eliminar.prepare(consulta);

    if(eliminar.exec()){
        qDebug()<<"Se ha eliminado correctamente.";
        QMessageBox::information(this,tr("Mensaje"),tr("Se ha eliminado correctamente."));

    } else {
        qDebug()<<"No se ha podido eliminar.";
        qDebug()<<"Se ha producido un ERROR" << eliminar.lastError();

    }
}

int Gestionalumnos3::Obteneridalumno()
{
    /*qDebug()<<"alumno es; " << ui->tableWidgetDatos->selectionModel()->currentIndex().sibling(
              ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();*/

    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();

    //int num_fila = indice.row();
    //qDebug()<<"el número de fila es: " << num_fila;

    int id_alumno = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();

    //qDebug()<<"el id de alumno es; " << id_alumno;

    return id_alumno;
}

void Gestionalumnos3::Editaralumno(int id, QString nombre, QString apellido)
{
    QString consulta;

    consulta.append("UPDATE Alumnos "
                    "SET Apellido ='" + apellido + "',Nombre = '" + nombre +"'"
                    " WHERE AlumnoID = " + QString::number(id));

    QSqlQuery actualizar;
    actualizar.prepare(consulta);

    if(actualizar.exec()){
        qDebug()<<"Se ha actualizado correctamente.";
        QMessageBox::information(this,tr("Mensaje"),tr("Se ha actualizado correctamente."));

    } else {
        qDebug()<<"No se ha podido actualizar.";
        qDebug()<<"Se ha producido un ERROR" << actualizar.lastError();

    }

}

void Gestionalumnos3::Obtenercampo(QString &_apellido, QString &_nombres)
{

    //índice seleccionado de la tabla
    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();

    _nombres = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),2).data().toString();
    _apellido = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),1).data().toString();

}

void Gestionalumnos3::on_pushButtonAgregar_clicked()
{
    agregar3 = new Agregar3(this); //Crea un diálogo
    agregar3->showMaximized();
    if(agregar3->exec()){          //se ejecuta después de cerrar la ventana
    } Mostrardatos();
}


void Gestionalumnos3::on_pushButtonEliminar_clicked()
{
        Eliminaralumno();
        Mostrardatos();
}

void Gestionalumnos3::on_pushButtonEditar_clicked()
{


        QString nombres, apellido;
        int id;

        Obtenercampo(apellido, nombres);

        id = Obteneridalumno();

        QVariant var(id);
        QString stringValue = var.toString();

        qDebug() << "el id seleccionado es: " <<id;

        editar3 = new Editar3(this);
        editar3->ui->lineEditNombre->setText(""+nombres+"");
        editar3->ui->lineEditApellido->setText(""+apellido+"");
        editar3->ui->plainTextEdit->appendPlainText(""+stringValue+"");
        editar3->IdExiste1();
        editar3->showMaximized();
        if(editar3->exec()){          //se ejecuta después de cerrar la ventana
        } Mostrardatos();

}

