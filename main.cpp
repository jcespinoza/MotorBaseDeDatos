#include "mwindow.h"
#include <iostream>
#include <string>
#include "defcampo.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    //HCER UN TABLA
    DefCampo def1;
    def1.Tipo = 0;
    def1.Longitud = 36;
    string n = "direccion";
    strcpy(def1.Nombre,n.c_str());
    cout << def1.Nombre;
}
