#ifndef GESTIONALUMNOS1_H
#define GESTIONALUMNOS1_H

#include <QDialog>
#include <agregar/agregar1.h>
#include <editar/editar1.h>
#include <QMainWindow>

namespace Ui {
class Gestionalumnos1;
}

class Gestionalumnos1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionalumnos1(QWidget *parent = 0);
    ~Gestionalumnos1();
    void Mostrardatos();
    int Obteneridalumno();
    void Eliminaralumno();
    void Editaralumno(int id, QString nombre, QString apellido);
    void Obtenercampo(QString &_apellido, QString &_nombres);

private slots:
    void on_pushButtonAgregar_clicked();
    void on_pushButtonEliminar_clicked();
    void on_pushButtonEditar_clicked();

private:
    Ui::Gestionalumnos1 *ui;
    Agregar1 *agregar1;
    Editar1 *editar1;
};

#endif // GESTIONALUMNOS1_H
