#include "mwindow.h"
#include "ui_mwindow.h"
#include <QDebug>
#include <QMessageBox>

MWindow::MWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pgBienvenida);
}

int MWindow::obtenerPestania()
{
    return ui->stackedWidget->currentIndex();
}

MWindow::~MWindow()
{
    delete ui;
}

void MWindow::on_pbNuevaTabla_clicked()
{
    //llama a la pantalla para ingresar datos de una nueva tabla
    ui->stackedWidget->setCurrentWidget(ui->pgNuevaTabla);
}

void MWindow::on_pbAbrirTabla_clicked()
{
    //llama a la pantalla para modificar registros de una tabla

    ui->stackedWidget->setCurrentWidget(ui->pgAdicionRegistros);
}

void MWindow::on_pbCrearTabla_clicked()
{
    //llama a la pantalla para crear los campos de la taba
    ui->stackedWidget->setCurrentWidget(ui->pgAdicionCampos);
}

void MWindow::on_actionCerrar_Pesta_a_triggered()
{
    //Preguntar si ya termino y desea guardar los cambios
    int respuesta = QMessageBox::question(this, "Guardar Cambios", "Ha modificado datos, desea guardarlos?");
    if(respuesta == QMessageBox::No)
        ui->stackedWidget->setCurrentWidget(ui->pgBienvenida);
    //sino verificar en que pagina esta
}

void MWindow::on_pbGuardarDefinicionTabla_clicked()
{
    //Guardar la tabla y volver al menu
    //Ofrecer mostrar vista de datos
    int respuesta = QMessageBox::question(this, "Guardar Cambios", "Desea agregar datos a la tabla ahora mismo?", QMessageBox::Yes, QMessageBox::No,QMessageBox::Cancel);
    if(respuesta == QMessageBox::No){
        ui->stackedWidget->setCurrentWidget(ui->pgBienvenida);
    }else if(respuesta == QMessageBox::Yes){
        ui->stackedWidget->setCurrentWidget(ui->pgAdicionRegistros);
    }
    //de otra forma, cancelar la accion
}

void MWindow::on_pbGuardarRegistros_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgBienvenida);
}

void MWindow::on_pbDescartarRegistros_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgBienvenida);
}
