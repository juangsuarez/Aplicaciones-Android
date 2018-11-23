#ifndef EDITAR2_H
#define EDITAR2_H

#include <QDialog>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
#include <ui_editar2.h>


namespace Ui {
class Editar2;
}

class Editar2 : public QDialog
{
    Q_OBJECT

public:
    explicit Editar2(QWidget *parent = 0);
    ~Editar2();
    Ui::Editar2 *ui;
    void IdExiste();
    void IdExiste1();
    QString _Id;
    QString _Id1;
    QString _Idselection;

private slots:
    void on_pushButton_clicked();

private:
};

#endif // Editar2_H
