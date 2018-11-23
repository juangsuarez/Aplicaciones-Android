#ifndef GESTIONALUMNOS2_H
#define GESTIONALUMNOS2_H

#include <QDialog>
#include <agregar/agregar2.h>
#include <editar/editar2.h>
#include <QMainWindow>

namespace Ui {
class Gestionalumnos2;
}

class Gestionalumnos2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionalumnos2(QWidget *parent = 0);
    ~Gestionalumnos2();
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
    Ui::Gestionalumnos2 *ui;
    Agregar2 *agregar2;
    Editar2 *editar2;
};

#endif // Gestionalumnos2_H
