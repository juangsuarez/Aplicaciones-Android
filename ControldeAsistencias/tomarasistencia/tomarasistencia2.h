#ifndef TOMARASISTENCIA2_H
#define TOMARASISTENCIA2_H

#include <QDialog>

namespace Ui {
class Tomarasistencia2;
}

class Tomarasistencia2 : public QDialog
{
    Q_OBJECT

public:
    explicit Tomarasistencia2(QWidget *parent = 0);
    ~Tomarasistencia2();
    Ui::Tomarasistencia2 *ui;
    void Recorrertabla();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void Siguiente();


private:
    int contador;
    QString id;

};

#endif // Tomarasistencia2_H
