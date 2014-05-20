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
    control.inicializarMaster();
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
        mostrarAgregarRegistros(QString(temp_Tabla.nombre));
    }
    if(respuesta != QMessageBox::Cancel){
        //temp_Tabla.defCampos.insert(temp_Tabla.defCampos.begin(), temp_defCampos.begin(), temp_defCampos.end());
        char* array = new char[temp_Tabla.totalTamanio()];
        temp_Tabla.aBytes(array);
        control.agregarTabla(temp_Tabla);
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
    if(nombreTabla.isEmpty()){
        QMessageBox::warning(this, "Error", "Debe elegir un nombre para la tabla");
        return;
    }
    //verfiicar que la tabla no existe primer
    ui->stackedWidget->setCurrentWidget(ui->pgAdicionCampos);
    ui->lbNombreTablaCampos->setText(nombreTabla);
    temp_Tabla.setNombre(nombreTabla.toStdString());
}

void MWindow::limpiarTodo()
{
    ui->lbNombreTablaCampos->setText("");
    ui->cboTipoCampo->setCurrentIndex(0);
    ui->leLongitudCampo->setText("4");
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

void MWindow::on_pbAgregarCampo_clicked()
{
    //Validar informacion primero.
    bool correct = true;
    int longitud = ui->leLongitudCampo->text().toInt(&correct);
    if(!correct){
        QMessageBox::warning(this, "Error", "La longitud del campo es invalida.");
        return;
    }
    string nombre = ui->leNombreCampo->text().toStdString();

    DefCampo newOne;
    newOne.Longitud = longitud;
    newOne.setNombre(nombre);
    newOne.Tipo = ui->cboTipoCampo->currentIndex();

    //si todo esta bien agregar a la lista
    temp_Tabla.defCampos.push_back(newOne);
    int row = ui->twCampos->rowCount();
    ui->twCampos->insertRow(row);
    ui->twCampos->setItem(row,0, new QTableWidgetItem(ui->cboTipoCampo->currentText()));
    ui->twCampos->setItem(row,1,new QTableWidgetItem(ui->leLongitudCampo->text()));
    ui->twCampos->setItem(row,2, new QTableWidgetItem(ui->leNombreCampo->text()));
}

void MWindow::on_cboTipoCampo_currentIndexChanged(int index)
{
    //1 stands for String
    if(index == 0){
        ui->leLongitudCampo->setText("4");
        ui->leLongitudCampo->setEnabled(false);
    }else
        ui->leLongitudCampo->setEnabled(true);
}
