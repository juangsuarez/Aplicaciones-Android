#include "asistencias2.h"
#include "ui_asistencias2.h"
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <QMessageBox>
#include <QVariant>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QSqlRecord>
#include <QDate>



Asistencias2::Asistencias2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Asistencias2)
{
    ui->setupUi(this);
    Mostrardatos();
}

Asistencias2::~Asistencias2()
{
    delete ui;
}


//---------------------------------START DATE SHOW---------------------------------
void Asistencias2::Mostrardatos()
{
    QString consulta;
    consulta.append("SELECT * FROM alumnos WHERE MateriaID=2");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    if(consultar.exec())
    {
        qDebug()<<"Se ha consultado correctamente MOSTRAR DATOS";

    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << consultar.lastError();
    }

    int fila = 0;

    //limpia la tabla
    ui->tableWidgetDatosa->setRowCount(0);

    while(consultar.next()){

        QTableWidgetItem *columna1 = new QTableWidgetItem(consultar.value(0).toByteArray().constData());
        columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
        columna1->setTextAlignment (Qt :: AlignCenter);

        QTableWidgetItem *columna2= new QTableWidgetItem(consultar.value(1).toByteArray().constData());
        columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
        columna2->setTextAlignment (Qt :: AlignCenter);

        QTableWidgetItem *columna3 = new QTableWidgetItem(consultar.value(2).toByteArray().constData());
        columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
        columna3->setTextAlignment (Qt :: AlignCenter);


        ui->tableWidgetDatosa->insertRow(fila);
        ui->tableWidgetDatosa->setItem(fila,0,columna1);
        ui->tableWidgetDatosa->setItem(fila,1,columna2);
        ui->tableWidgetDatosa->setItem(fila,2,columna3);
        QStringList headers = { "ID", "Apellido/s", "Nombre/s"};
        ui->tableWidgetDatosa->setHorizontalHeaderLabels(headers);
        fila++;
    }
}
void Asistencias2::Mostrardatos1()
{
    QString consulta;
    consulta.append("SELECT * FROM Asistencias WHERE (AlumnoId="+ui->lineEditId->text()+") and (MateriaID=2)");
    QSqlQuery select;
        select.prepare(consulta);

        if(select.exec())
        {
            qDebug()<<"Se ha consultado correctamente MOSTRAR DATOS 1";

        }
        else{
        }
        int fila = 0;

        //limpia la tabla
        ui->tableWidgetDatosa->setRowCount(0);

        while(select.next()){

            QTableWidgetItem *columna1 = new QTableWidgetItem(select.value(1).toByteArray().constData());
            columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
            columna1->setTextAlignment (Qt :: AlignCenter);

            QTableWidgetItem *columna2 = new QTableWidgetItem(""+_Apellido+", """+_Nombre+"");
            columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
            columna2->setTextAlignment (Qt :: AlignCenter);

            QTableWidgetItem *columna3= new QTableWidgetItem(select.value(2).toByteArray().constData());
            columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
            columna3->setTextAlignment (Qt :: AlignCenter);


            ui->tableWidgetDatosa->insertRow(fila);
            ui->tableWidgetDatosa->setItem(fila,0,columna1);
            ui->tableWidgetDatosa->setItem(fila,1,columna2);
            ui->tableWidgetDatosa->setItem(fila,2,columna3);
            QStringList headers = { "Fecha", "Alumno/a", "Asistencia"};
            ui->tableWidgetDatosa->setHorizontalHeaderLabels(headers);
            fila++;
        }
}

void Asistencias2::Mostrardatos2()
{
    int fila = 0;

    //limpia la tabla
    ui->tableWidgetDatosa->setRowCount(0);
    QString consulta;
    consulta.append("SELECT *FROM Asistencias Where MateriaID=2");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    if(consultar.exec())
    {
        qDebug()<<"Se ha consultado correctamente MOSTRAR DATOS DE FECHA";

    }else{
    }

    while(consultar.next()){
        if(_Fechaselect==consultar.value(1).toString()){

//---------------------------------START SECOND QUERY ------------------------------------
        _Idcurrent = ""+consultar.value(3).toString()+"";

            QString consulta90;
            consulta90.append("SELECT * FROM alumnos WHERE (MateriaID=2) and (AlumnoID="+_Idcurrent+")");
            QSqlQuery consultar70;
            consultar70.prepare(consulta90);

            if(consultar70.exec())
            {
                qDebug()<<"Se ha consultado correctamente OBTENER VALORES";

            }else{
            }


            while(consultar70.next()){

                _Nombre = consultar70.value(2).toString();
                _Apellido = consultar70.value(1).toString();

                qDebug() <<_Apellido;
                qDebug() <<_Nombre;

                QTableWidgetItem *columna1 = new QTableWidgetItem(consultar.value(1).toByteArray().constData());
                columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
                columna1->setTextAlignment (Qt :: AlignCenter);
                qDebug() <<consultar.value(1).toString();

                QTableWidgetItem *columna2= new QTableWidgetItem(""+_Apellido+", """+_Nombre+"");
                columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
                columna2->setTextAlignment (Qt :: AlignCenter);
                qDebug() <<consultar.value(3).toString();

                QTableWidgetItem *columna3 = new QTableWidgetItem(consultar.value(2).toByteArray().constData());
                columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
                columna3->setTextAlignment (Qt :: AlignCenter);
                qDebug() <<consultar.value(2).toString();


                ui->tableWidgetDatosa->insertRow(fila);
                ui->tableWidgetDatosa->setItem(fila,0,columna1);
                ui->tableWidgetDatosa->setItem(fila,1,columna2);
                ui->tableWidgetDatosa->setItem(fila,2,columna3);
                QStringList headers = { "Fecha", "Alumno/a", "Estado"};
                ui->tableWidgetDatosa->setHorizontalHeaderLabels(headers);
                fila++;

            }



//---------------------------------FINISH ALL QUERY ------------------------------------

    }}
}
//---------------------------------START GET INFORMATION---------------------------------

void Asistencias2::Obtenervalores1()
{
    QString consulta;
        consulta.append("SELECT * FROM alumnos WHERE (MateriaID=2) and (Fecha="+ui->lineEditFecha->text()+")");
        QSqlQuery consultar;
        consultar.prepare(consulta);

        if(consultar.exec())
        {
            qDebug()<<"Se ha consultado correctamente OBTENER VALORES";

        }else{
            qDebug()<<"No se ha podido realizar la consulta";
            qDebug()<<"ERROR" << consultar.lastError();
        }
        int fila = 0;

        //limpia la tabla
        ui->tableWidgetDatosa->setRowCount(0);

        while(consultar.next()){

            QTableWidgetItem *columna1 = new QTableWidgetItem(consultar.value(1).toByteArray().constData());
            columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
            columna1->setTextAlignment (Qt :: AlignCenter);

            QTableWidgetItem *columna2 = new QTableWidgetItem(""+_Apellido+", """+_Nombre+"");
            columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
            columna2->setTextAlignment (Qt :: AlignCenter);

            QTableWidgetItem *columna3= new QTableWidgetItem(consultar.value(2).toByteArray().constData());
            columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura
            columna3->setTextAlignment (Qt :: AlignCenter);


            ui->tableWidgetDatosa->insertRow(fila);
            ui->tableWidgetDatosa->setItem(fila,0,columna1);
            ui->tableWidgetDatosa->setItem(fila,1,columna2);
            ui->tableWidgetDatosa->setItem(fila,2,columna3);
            QStringList headers = { "Fecha", "Alumno/a", "Asistencia"};
            ui->tableWidgetDatosa->setHorizontalHeaderLabels(headers);
            fila++;
        }
}

void Asistencias2::Obtenervalores()
{
    QString consulta;
        consulta.append("SELECT * FROM alumnos WHERE (MateriaID=2) and (AlumnoID="+ui->lineEditId->text()+")");
        QSqlQuery consultar;
        consultar.prepare(consulta);

        if(consultar.exec())
        {
            qDebug()<<"Se ha consultado correctamente OBTENER VALORES";

        }else{
            qDebug()<<"No se ha podido realizar la consulta";
            qDebug()<<"ERROR" << consultar.lastError();
        }
        //limpia la tabla
        ui->tableWidgetDatosa->setRowCount(0);

        while(consultar.next()){

            _Nombre = consultar.value(2).toString();
            _Apellido = consultar.value(1).toString();

        }
}
//---------------------------------START IF EXIST---------------------------------
void Asistencias2::Idexiste()
{   _Id = "";
    QSqlQuery q("SELECT * FROM asistencias WHERE MateriaID=2;");
    QSqlRecord rec = q.record();

    qDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("AlumnoID"); // index of the field "name"
    while (q.next())
        if (ui->lineEditId->text()==q.value(nameCol).toString())
        {   _Id = "NOTNULL";
            qDebug()<<"EL ID EXISTE";}
        qDebug() << q.value(nameCol).toString(); // output all names
}

void Asistencias2::Fechaexiste()
{
    _Fecha = "";
    QSqlQuery q("SELECT * FROM Asistencias WHERE MateriaID=2;");
    QSqlRecord rec = q.record();

    qDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("Fecha"); // index of the field "name"
    while (q.next())
        if (ui->lineEditFecha->text()==q.value(nameCol).toString())
        {   _Fecha = "NOTNULL";
            qDebug()<<"LA FECHA EXISTE";}
        qDebug() << q.value(nameCol).toString(); // output all names
}
//---------------------------------START DATE---------------------------------
void Asistencias2::Fecha()
{
    QDate date = QDate::currentDate();

    int d = date.day();
    int m = date.month();
    int y = date.year();

    QVariant vard(d);
    QString stringValued = vard.toString();

    QVariant varm(m);
    QString stringValuem = varm.toString();

    QVariant vary(y);
    QString stringValuey = vary.toString();

    ui->lineEditFecha->setText(""+stringValued+"/"+stringValuem+"/"+stringValuey+"");
}

//---------------------------------START BUTONNS---------------------------------
void Asistencias2::on_pushButtonID_clicked()
{
    Idexiste();
    if (_Id == "NOTNULL"){
    ui->groupBoxId->setTitle("El Resultado se Muestra en Pantalla");
	ui->groupBoxFecha->setTitle("Fecha");
    Obtenervalores();
    Mostrardatos1();}
    else {
        ui->groupBoxId->setTitle("El ID Seleccionado No Existe");
		ui->groupBoxFecha->setTitle("Fecha");
        Mostrardatos();
    }
}

void Asistencias2::on_pushButtonFecha_clicked()
{
    _Fechaselect = ""+ui->lineEditFecha->text()+"";

        Fechaexiste();
        if (_Fecha == "NOTNULL"){
        ui->groupBoxFecha->setTitle("El Resultado se Muestra en Pantalla");
		ui->groupBoxId->setTitle("ID");
        Mostrardatos2();}
        else {
            ui->groupBoxFecha->setTitle("La Fecha Introducida No Existe");
			ui->groupBoxId->setTitle("ID");
            Mostrardatos();
        }

}
