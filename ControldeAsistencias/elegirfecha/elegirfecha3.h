#ifndef ELEGIRFECHA3_H
#define ELEGIRFECHA3_H

#include <QDialog>
#include "tomarasistencia/tomarasistencia3.h"
#include "ui_tomarasistencia3.h"


namespace Ui {
class Elegirfecha3;
}

class Elegirfecha3 : public QDialog
{
    Q_OBJECT

public:
    explicit Elegirfecha3(QWidget *parent = 0);
    ~Elegirfecha3();
    void Obtenerfecha(QString &_d, QString &_m, QString &_y);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Elegirfecha3 *ui;
    Tomarasistencia3 *tomarasistencia3;
    QString fecha;

};

#endif // ELEGIRFECHA3_H
