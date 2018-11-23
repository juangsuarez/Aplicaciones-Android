#ifndef TOMARASISTENCIA1_H
#define TOMARASISTENCIA1_H

#include <QDialog>

namespace Ui {
class Tomarasistencia1;
}

class Tomarasistencia1 : public QDialog
{
    Q_OBJECT

public:
    explicit Tomarasistencia1(QWidget *parent = 0);
    ~Tomarasistencia1();
    Ui::Tomarasistencia1 *ui;
    void Recorrertabla();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void Siguiente();


private:
    int contador;
    QString id;

};

#endif // TOMARASISTENCIA1_H
