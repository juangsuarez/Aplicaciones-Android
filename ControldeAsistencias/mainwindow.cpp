#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <agregar/agregar1.h>
#include <gestionalumnos/gestionalumnos1.h>
#include <tomarasistencia/tomarasistencia1.h>
#include <elegirfecha/elegirfecha1.h>
#include <asistencias/asistencias1.h>
#include <agregar/agregar2.h>
#include <gestionalumnos/gestionalumnos2.h>
#include <tomarasistencia/tomarasistencia2.h>
#include <elegirfecha/elegirfecha2.h>
#include <asistencias/asistencias2.h>
#include <agregar/agregar3.h>
#include <gestionalumnos/gestionalumnos3.h>
#include <tomarasistencia/tomarasistencia3.h>
#include <elegirfecha/elegirfecha3.h>
#include <asistencias/asistencias3.h>
#include <ui_gestionalumnos1.h>
#include <ui_gestionalumnos2.h>
#include <ui_gestionalumnos3.h>
#include <ui_elegirfecha1.h>
#include <ui_elegirfecha2.h>
#include <ui_elegirfecha3.h>
#include <ui_asistencias1.h>
#include <ui_asistencias1.h>
#include <ui_asistencias1.h>

#include <QDebug>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //este código se ejecuta cuando se inicializa la aplicación
    qDebug()<<"Aplicación iniciada...";

    QString nombre;
    nombre.append("baseDatos.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db. setDatabaseName("baseDatos");

    if (db.open()) {qDebug()<<"Se ha conectado a la base de datos";
    }
    else
    {
     qDebug()<<"ERROR, no se ha podido conectar";
    }
    crearTablaAlumnos();
    crearTablaAsistencias();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearTablaAsistencias()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS Asistencias ( `AsistenciaID` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "`Fecha` TEXT NOT NULL, `Estado` TEXT NOT NULL,"
                    "'AlumnoID' INT,"
                    "`MateriaID` INT,"
                    "CONSTRAINT FK_AlumnoAsistencia FOREIGN KEY (AlumnoID)"
                    "REFERENCES Alumnos(AlumnoID)"
                    ");"
                    );

    QSqlQuery crear;
    crear.prepare(consulta);

    if (crear.exec())
        {
        qDebug()<<"Se creó Asistencias correctamente";
        }
    else
        {
        qDebug()<<"ERROR, no se ha creado Asistencias correctamente";
    }

}
void MainWindow::crearTablaAlumnos()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS Alumnos ( `AlumnoID` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "`Apellido` TEXT, `Nombre` TEXT,`MateriaID` INT "
                   ");"
                    );

    QSqlQuery crear;
    crear.prepare(consulta);

    if (crear.exec())
        {
        qDebug()<<"Se creó Alumnos correctamente";
        }
    else
        {
        qDebug()<<"ERROR, no se ha creado Alumnos correctamente";
    }

}


//---------------------------------START FIRST---------------------------------

void MainWindow::on_pushButtonGestionar1_clicked()
{
    gestionalumnos1  =new Gestionalumnos1(this);
    gestionalumnos1->showMaximized();
}

void MainWindow::on_pushButtonVerasistencias1_clicked()
{
    asistencias1  =new Asistencias1(this);
    asistencias1->Fecha();
    asistencias1->showMaximized();
}

void MainWindow::on_pushButtonAsistencia1_clicked()
{
    elegirfecha1  =new Elegirfecha1(this);
    elegirfecha1->showMaximized();
}

//---------------------------------START SECOND---------------------------------

void MainWindow::on_pushButtonGestionar2_clicked()
{
    gestionalumnos2  =new Gestionalumnos2(this);
    gestionalumnos2->showMaximized();
}

void MainWindow::on_pushButtonVerasistencias2_clicked()
{
    asistencias2  =new Asistencias2(this);
    asistencias2->Fecha();
    asistencias2->showMaximized();
}

void MainWindow::on_pushButtonAsistencia2_clicked()
{
    elegirfecha2  =new Elegirfecha2(this);
    elegirfecha2->showMaximized();
}

//---------------------------------START THREE---------------------------------

void MainWindow::on_pushButtonGestionar3_clicked()
{
    gestionalumnos3  =new Gestionalumnos3(this);
    gestionalumnos3->showMaximized();
}

void MainWindow::on_pushButtonVerasistencias3_clicked()
{
    asistencias3  =new Asistencias3(this);
    asistencias3->Fecha();
    asistencias3->showMaximized();
}

void MainWindow::on_pushButtonAsistencia3_clicked()
{
    elegirfecha3  =new Elegirfecha3(this);
    elegirfecha3->showMaximized();
}
