#ifndef ELEGIRFECHA2_H
#define ELEGIRFECHA2_H

#include <QDialog>
#include "tomarasistencia/tomarasistencia2.h"
#include "ui_tomarasistencia2.h"


namespace Ui {
class Elegirfecha2;
}

class Elegirfecha2 : public QDialog
{
    Q_OBJECT

public:
    explicit Elegirfecha2(QWidget *parent = 0);
    ~Elegirfecha2();
    void Obtenerfecha(QString &_d, QString &_m, QString &_y);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Elegirfecha2 *ui;
    Tomarasistencia2 *tomarasistencia2;
    QString fecha;

};

#endif // ELEGIRFECHA2_H
