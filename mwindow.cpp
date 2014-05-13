#include "mwindow.h"
#include "ui_mwindow.h"
#include <QDebug>

MWindow::MWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);
}

MWindow::~MWindow()
{
    delete ui;
}

void MWindow::on_pbNuevaTabla_clicked()
{
    //llama a la pantalla para ingresar datos de una nueva tabla
    ui->stackedWidget->setCurrentIndex(1);
}

void MWindow::on_pbAbrirTabla_clicked()
{
    //llama a la pantalla para modificar datos de una tabla
    ui->stackedWidget->setCurrentIndex(2);
}
