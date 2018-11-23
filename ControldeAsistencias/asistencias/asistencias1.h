#ifndef ASISTENCIAS1_H
#define ASISTENCIAS1_H

#include <QDialog>
#include <ui_asistencias1.h>

namespace Ui {
class Asistencias1;
}

class Asistencias1 : public QDialog
{
    Q_OBJECT

public:
    explicit Asistencias1(QWidget *parent = 0);
    ~Asistencias1();
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
    Ui::Asistencias1 *ui;
};

#endif // ASISTENCIAS1_H
