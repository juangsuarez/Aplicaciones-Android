#ifndef EDITAR3_H
#define EDITAR3_H

#include <QDialog>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <ui_editar3.h>


namespace Ui {
class Editar3;
}

class Editar3 : public QDialog
{
    Q_OBJECT

public:
    explicit Editar3(QWidget *parent = 0);
    ~Editar3();
    Ui::Editar3 *ui;
    void IdExiste();
    void IdExiste1();
    QString _Id;
    QString _Id1;
    QString _Idselection;

private slots:
    void on_pushButton_clicked();

private:
};

#endif // Editar3_H
