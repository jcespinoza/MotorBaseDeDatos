#include "mwindow.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <QApplication>
using namespace std;

void testFunction();
void testControlador();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MWindow w;
    w.show();

    return a.exec();

    //testFunction();
}

void testControlador(){
    Controlador contr;
    DefTabla det1;
    string nom = "Holis";
    strcpy(det1.nombre,nom.c_str());

    contr.tablas.push_back(det1);
    cout << "Result: " << contr.obtenerIndice("Holis");
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

    int tablaSize = det1.totalTamanio();
    char* bufferW = new char[tablaSize];
    det1.aBytes(bufferW);

    FILE * wFile;
    wFile = fopen ("prueba.accdb","wb");
    if (wFile!=NULL)
    {
        fwrite(bufferW,1, tablaSize,wFile);
        fclose(wFile);
    }

    //Now read the file.
    FILE* rFile;
    char* bufferR = new char[tablaSize];
    rFile = fopen ("prueba.accdb","rb");
    if(rFile)
    {
        long fSize = 0;
        fseek(rFile,0,SEEK_END);
        fSize = ftell(rFile);
        rewind(rFile);
        fread(bufferR, 1, tablaSize, rFile);
        fclose(rFile);
        DefTabla rDef = DefTabla::desdeBytes(bufferR);
        //cout << (*DefCampo)(rDef.defCampos.begin()).Nombre;
        std::list<DefCampo>::iterator it = rDef.defCampos.begin();
        cout << ((*(++it))).Nombre;
        for(int i = 0; i < tablaSize; i++){
            cout << "Written[" << i << "]: " << bufferW[i] << "\n";
        }

        for(int i = 0; i < fSize; i++){
            cout << "Read[" << i << "]: " << bufferR[i] << "\n";
        }
    }
}
