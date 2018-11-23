#ifndef EDITAR1_H
#define EDITAR1_H

#include <QDialog>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <ui_editar1.h>


namespace Ui {
class Editar1;
}

class Editar1 : public QDialog
{
    Q_OBJECT

public:
    explicit Editar1(QWidget *parent = 0);
    ~Editar1();
    Ui::Editar1 *ui;
    void IdExiste();
    void IdExiste1();
    QString _Id;
    QString _Id1;
    QString _Idselection;

private slots:
    void on_pushButton_clicked();

private:
};

#endif // EDITAR1_H
