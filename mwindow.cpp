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

void MWindow::on_lbNuevaTabla_linkActivated(const QString &link)
{
    qDebug() << "Algo";
}
