#include "mwindow.h"
#include <string>
#include <iostream>
#include <cstdio>
#include "deftabla.h"
#include <QApplication>
using namespace std;

void testFunction();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MWindow w;
    w.show();

    return a.exec();

}

void testFunction(){
    //HCER UN TABLA
    DefCampo def1;
    def1.Tipo = 1;
    def1.Longitud = 36;
    string n = "Direccion";
    strcpy(def1.Nombre,n.c_str());
    char* tes = new char[58];
    def1.aBytes(tes);

    DefCampo def2;
    def2.Tipo = 0;
    def2.Longitud = 4;
    string n2 = "Telefono";
    strcpy(def2.Nombre,n2.c_str());
    char* tes2 = new char[58];
    def2.aBytes(tes2);

    cout << "\n";
    Campo c1(def1.Tipo, def1.Longitud);
    string dir = "La celeo";
    strcpy(c1.data, dir.c_str());

    char* tes3 = new char[c1.total()];
    c1.aBytes(tes3);

    DefTabla det1;
    det1.defCampos.push_back(def1);
    string nom = "Holis";
    strcpy(det1.nombre,nom.c_str());
    det1.defCampos.push_back(def2);

    int tsize = det1.totalTamanio();
    char* tab = new char[tsize];
    det1.aBytes(tab);

    FILE * tFile;
    tFile = fopen ("prueba.sexy","wb");
    if (tFile!=NULL)
    {
        fwrite(tab,1, tsize,tFile);
        fclose(tFile);
    }

    //Now read the file.
    FILE* rFile;
    char* tread = new char[tsize];
    rFile = fopen ("prueba.sexy","rb");
    if(rFile)
    {
        long lsize = 0;
        fseek(rFile,0,SEEK_END);
        lsize = ftell(rFile);
        rewind(rFile);
        fread(tread, 1, tsize, rFile);
        fclose(rFile);
        DefTabla rDef = DefTabla::desdeBytes(tread);
        //cout << (*DefCampo)(rDef.defCampos.begin()).Nombre;
        std::list<DefCampo>::iterator it = rDef.defCampos.begin();
        cout << ((*(++it))).Nombre;
    }
}
