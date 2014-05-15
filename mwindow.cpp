#include "mwindow.h"
#include "ui_mwindow.h"
#include <QDebug>
#include <QMessageBox>

MWindow::MWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);
    mostrarBienvenida();
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
    mostrarNuevaTabla();
}

void MWindow::on_pbAbrirTabla_clicked()
{
    //llama a la pantalla para modificar registros de una tabla
    mostrarAbrirTabla();
}

void MWindow::on_pbCrearTabla_clicked()
{
    //llama a la pantalla para crear los campos de la taba
    mostrarCampos(ui->leNombreTabla->text());
}

void MWindow::on_actionCerrar_Pesta_a_triggered()
{
    //Preguntar si ya termino y desea guardar los cambios
    int respuesta = QMessageBox::question(this, "Guardar Cambios", "Ha modificado datos, desea guardarlos?");
    if(respuesta == QMessageBox::No)
        mostrarBienvenida();
    //sino verificar en que pagina esta
}

void MWindow::on_pbGuardarDefinicionTabla_clicked()
{
    //Guardar la tabla y volver al menu
    //Ofrecer mostrar vista de datos
    int respuesta = QMessageBox::question(this, "Guardar Cambios", "Desea agregar datos a la tabla ahora mismo?", QMessageBox::Yes, QMessageBox::No,QMessageBox::Cancel);
    if(respuesta == QMessageBox::No){
        mostrarBienvenida();
    }else if(respuesta == QMessageBox::Yes){
        mostrarAgregarRegistros(ui->lwTablas->currentItem()->text());
    }
    //de otra forma, cancelar la accion
}

void MWindow::on_pbGuardarRegistros_clicked()
{
    mostrarBienvenida();
}

void MWindow::on_pbDescartarRegistros_clicked()
{
    mostrarBienvenida();
}

void MWindow::mostrarBienvenida()
{
    ui->stackedWidget->setCurrentWidget(ui->pgBienvenida);
    limpiarTodo();
}

void MWindow::mostrarAgregarRegistros(QString nombreTabla)
{
    ui->stackedWidget->setCurrentWidget(ui->pgAdicionRegistros);
    ui->lbNombreTablaRegistros->setText(nombreTabla);
}

void MWindow::mostrarAbrirTabla()
{
    ui->stackedWidget->setCurrentWidget(ui->pgElegirTabla);
}

void MWindow::mostrarNuevaTabla()
{

    ui->stackedWidget->setCurrentWidget(ui->pgNuevaTabla);
}

void MWindow::mostrarCampos(QString nombreTabla)
{
    ui->stackedWidget->setCurrentWidget(ui->pgAdicionCampos);
    ui->lbNombreTablaCampos->setText(nombreTabla);
}

void MWindow::limpiarTodo()
{
    ui->lbNombreTablaCampos->setText("");
    ui->cboTipoCampo->setCurrentIndex(0);
    ui->leLongitudCampo->clear();
    ui->leNombreCampo->clear();
    ui->twCampos->clearContents();

    ui->leNombreTabla->clear();

    ui->lbNombreTablaRegistros->clear();
    ui->twDatosTabla->clear();
}

void MWindow::on_pbAbrirTablaElegida_clicked()
{
    limpiarTodo();
    if(ui->lwTablas->count() == 0){
        mostrarBienvenida();
        return;
    }
    ui->stackedWidget->setCurrentWidget(ui->pgAdicionRegistros);
    mostrarAgregarRegistros(ui->lwTablas->currentItem()->text());
}
