#ifndef AGREGAR2_H
#define AGREGAR2_H

#include <QDialog>
#include <ui_agregar2.h>

namespace Ui {
class Agregar2;
}

class Agregar2 : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar2(QWidget *parent = 0);
    ~Agregar2();

    void obtenerValores(QString &nombre,QString &apellido);
    void Insertaralumno();
    void IdExiste();

    QString getNombre();
    QString getApellido();
    QString _Id;


private slots:
    void on_pushButton_clicked();
    void on_lineEditApellido_cursorPositionChanged();
    void on_lineEditNombre_cursorPositionChanged();

private:
    Ui::Agregar2 *ui;
};

#endif // AGREGAR2_H
