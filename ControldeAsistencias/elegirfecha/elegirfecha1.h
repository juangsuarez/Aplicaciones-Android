#ifndef ELEGIRFECHA1_H
#define ELEGIRFECHA1_H

#include <QDialog>
#include "tomarasistencia/tomarasistencia1.h"
#include "ui_tomarasistencia1.h"


namespace Ui {
class Elegirfecha1;
}

class Elegirfecha1 : public QDialog
{
    Q_OBJECT

public:
    explicit Elegirfecha1(QWidget *parent = 0);
    ~Elegirfecha1();
    void Obtenerfecha(QString &_d, QString &_m, QString &_y);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Elegirfecha1 *ui;
    Tomarasistencia1 *tomarasistencia1;
    QString fecha;

};

#endif // ELEGIRFECHA1_H
