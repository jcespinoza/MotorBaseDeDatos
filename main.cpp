#include "mwindow.h"
#include "defcampo.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //HCER UN TABLA
    DefCampo def1;
    def1.Tipo = 1;
    def1.Longitud = 36;
    string n = "direccion";
    strcpy(def1.Nombre,n.c_str());

    char* tes = new char[58];
    def1.aByteArray(tes);

    cout << "\n\n\n";
    Campo c1(def1.Tipo, def1.Longitud);
    string dir = "La celeo";
    strcpy(c1.data, dir.c_str());

    char* tes2 = new char[c1.total()];
    c1.aBytes(tes2);

}
