#ifndef ASISTENCIAS2_H
#define ASISTENCIAS2_H

#include <QDialog>
#include <ui_asistencias2.h>

namespace Ui {
class Asistencias2;
}

class Asistencias2 : public QDialog
{
    Q_OBJECT

public:
    explicit Asistencias2(QWidget *parent = 0);
    ~Asistencias2();
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
    Ui::Asistencias2 *ui;
};

#endif // Asistencias2_H
