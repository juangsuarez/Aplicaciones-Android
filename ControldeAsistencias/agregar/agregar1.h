#ifndef AGREGAR1_H
#define AGREGAR1_H

#include <QDialog>
#include <ui_agregar1.h>

namespace Ui {
class Agregar1;
}

class Agregar1 : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar1(QWidget *parent = 0);
    ~Agregar1();

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
    Ui::Agregar1 *ui;
};

#endif // AGREGAR1_H
