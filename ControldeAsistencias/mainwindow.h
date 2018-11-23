#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <QMessageBox>
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
#include <ui_asistencias2.h>
#include <ui_asistencias3.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




private slots:

    void on_pushButtonGestionar1_clicked();
    void on_pushButtonAsistencia1_clicked();
    void on_pushButtonVerasistencias1_clicked();
    void on_pushButtonGestionar2_clicked();
    void on_pushButtonAsistencia2_clicked();
    void on_pushButtonVerasistencias2_clicked();
    void on_pushButtonGestionar3_clicked();
    void on_pushButtonAsistencia3_clicked();
    void on_pushButtonVerasistencias3_clicked();

    void crearTablaAlumnos();
    void crearTablaAsistencias();

private:
    Ui::MainWindow *ui;
    Agregar3 *agregar3;
    Gestionalumnos3 *gestionalumnos3;
    Tomarasistencia3 *tomarasistencia3;
    Elegirfecha3 *elegirfecha3;
    Asistencias3 *asistencias3;
    Agregar2 *agregar2;
    Gestionalumnos2 *gestionalumnos2;
    Tomarasistencia2 *tomarasistencia2;
    Elegirfecha2 *elegirfecha2;
    Asistencias2 *asistencias2;
    Agregar1 *agregar1;
    Gestionalumnos1 *gestionalumnos1;
    Tomarasistencia1 *tomarasistencia1;
    Elegirfecha1 *elegirfecha1;
    Asistencias1 *asistencias1;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
