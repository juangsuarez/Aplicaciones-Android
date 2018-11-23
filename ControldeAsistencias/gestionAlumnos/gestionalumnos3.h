#ifndef GESTIONALUMNOS3_H
#define GESTIONALUMNOS3_H

#include <QDialog>
#include <agregar/agregar3.h>
#include <editar/editar3.h>
#include <QMainWindow>

namespace Ui {
class Gestionalumnos3;
}

class Gestionalumnos3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionalumnos3(QWidget *parent = 0);
    ~Gestionalumnos3();
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
    Ui::Gestionalumnos3 *ui;
    Agregar3 *agregar3;
    Editar3 *editar3;
};

#endif // Gestionalumnos3_H
