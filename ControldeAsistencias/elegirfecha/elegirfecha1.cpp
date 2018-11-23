#include "elegirfecha/elegirfecha1.h"
#include "ui_elegirfecha1.h"
#include "tomarasistencia/tomarasistencia1.h"
#include "ui_tomarasistencia1.h"
#include <QDate>
#include <QDebug>
#include <QVariant>
#include <QString>
#include <QGroupBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSpinBox>

Elegirfecha1::Elegirfecha1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Elegirfecha1)
{
    ui->setupUi(this);

   QDate date = QDate::currentDate();

   QString d,m,y;
    Obtenerfecha(d,m,y);

    ui->spinBoxd->setValue(date.day());
    ui->spinBoxm->setValue(date.month());
    ui->spinBoxy->setValue(date.year());

    ui->groupBoxFecha->setTitle(""+d+"/"""+m+"/"""+y+"");

    ui->spinBoxd->setMinimum(1);
    ui->spinBoxm->setMinimum(1);
    ui->spinBoxy->setMinimum(2018);
    ui->spinBoxd->setMaximum(31);
    ui->spinBoxm->setMaximum(12);
    ui->spinBoxy->setMaximum(9999);

}


Elegirfecha1::~Elegirfecha1()
{
    delete ui;
}

void Elegirfecha1::Obtenerfecha(QString &_d, QString &_m, QString &_y)
{


QDate date = QDate::currentDate();

        int d = date.day();
        int m = date.month();
        int y = date.year();

        QVariant vard(d);
        QString stringValued = vard.toString();
        _d = ""+stringValued+"";

        QVariant varm(m);
        QString stringValuem = varm.toString();
        _m = ""+stringValuem+"";

        QVariant vary(y);
        QString stringValuey = vary.toString();
        _y = ""+stringValuey+"";


}



void Elegirfecha1::on_pushButton_clicked()
{
    QString Dia;
    QString Mes;

    int ds = ui->spinBoxd->value();
    int ms = ui->spinBoxm->value();
    int ys = ui->spinBoxy->value();

    QVariant vard(ds);
    QString stringValueds = vard.toString();

    QVariant varm(ms);
    QString stringValuems = varm.toString();

    QVariant vary(ys);
    QString stringValueys = vary.toString();

    if(ui->spinBoxd->value()<10){Dia="0"+stringValueds+"";}else{Dia=stringValueds;}
    if(ui->spinBoxm->value()<10){Mes="0"+stringValuems+"";}else{Mes=stringValuems;}

    fecha=""+Dia+"/"+Mes+"/"+stringValueys+"";

        tomarasistencia1  =new Tomarasistencia1(this);
        tomarasistencia1->showMaximized();
        tomarasistencia1->ui->groupBoxFecha->setTitle(""+fecha+"");
        close();
}
