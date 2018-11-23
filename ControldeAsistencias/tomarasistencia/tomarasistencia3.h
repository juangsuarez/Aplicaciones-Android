#ifndef TOMARASISTENCIA3_H
#define TOMARASISTENCIA3_H

#include <QDialog>

namespace Ui {
class Tomarasistencia3;
}

class Tomarasistencia3 : public QDialog
{
    Q_OBJECT

public:
    explicit Tomarasistencia3(QWidget *parent = 0);
    ~Tomarasistencia3();
    Ui::Tomarasistencia3 *ui;
    void Recorrertabla();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void Siguiente();


private:
    int contador;
    QString id;

};

#endif // Tomarasistencia3_H
