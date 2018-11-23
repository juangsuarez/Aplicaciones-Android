#ifndef AGREGAR3_H
#define AGREGAR3_H

#include <QDialog>
#include <ui_agregar3.h>

namespace Ui {
class Agregar3;
}

class Agregar3 : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar3(QWidget *parent = 0);
    ~Agregar3();

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
    Ui::Agregar3 *ui;
};

#endif // AGREGAR3_H
