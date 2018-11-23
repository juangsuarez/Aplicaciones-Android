#ifndef ASISTENCIAS3_H
#define ASISTENCIAS3_H

#include <QDialog>
#include <ui_asistencias3.h>

namespace Ui {
class Asistencias3;
}

class Asistencias3 : public QDialog
{
    Q_OBJECT

public:
    explicit Asistencias3(QWidget *parent = 0);
    ~Asistencias3();
    void Mostrardatos();
    void Mostrardatos1();
    void Mostrardatos2();
    void Obtenervalores();
    void Obtenervalores1();
    void Idexiste();
    void Fechaexiste();
    void Fecha();
    QString _Nombre;
    QString _Apellido;
    QString _Id;
    QString _Fecha;
    QString _Fechaselect;
    QString _Idcurrent;

private slots:   
    void on_pushButtonID_clicked();
    void on_pushButtonFecha_clicked();

private:
    Ui::Asistencias3 *ui;
};

#endif // Asistencias3_H
