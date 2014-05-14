#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>
#include "controlador.h"

namespace Ui {
class MWindow;
}

class MWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MWindow(QWidget *parent = 0);
    int obtenerPestania();
    ~MWindow();

private slots:
    void on_pbNuevaTabla_clicked();
    void on_pbAbrirTabla_clicked();
    void on_pbCrearTabla_clicked();
    void on_actionCerrar_Pesta_a_triggered();
    void on_pbGuardarDefinicionTabla_clicked();
    void on_pbGuardarRegistros_clicked();
    void on_pbDescartarRegistros_clicked();

    void on_pbAbrirTablaElegida_clicked();

private:
    Ui::MWindow *ui;
    void mostrarBienvenida();
    void mostrarAgregarRegistros(QString nombreTabla);
    void mostrarAbrirTabla();
    void mostrarNuevaTabla();
    void mostrarCampos(QString nombreTabla);
    void limpiarTodo();
};

#endif // MWINDOW_H
