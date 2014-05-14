#include "controlador.h"
using namespace std;

Controlador::Controlador()
{
}

int Controlador::obtenerIndice(string nam)
{
    int indice = 0;
    for(list<DefTabla>::iterator it = tablas.begin(); it != tablas.end(); ++it, indice++){
        string tab( (*it).nombre );
        if( tab.compare(nam) == 0)
            return indice;
    }
    return -1;
}

int Controlador::agregarTabla(string nam)
{
    int encontrado = obtenerIndice(nam);
    if( encontrado != -1)
        return 1; // tabla ya existia
}

void Controlador::inicializarMaster()
{
    //verificar si el archivo ya existia y si no estaba vacio
    //escribir uno nuevo o leer desde el de acuerdo a cada caso
    FILE* dbFile = fopen("database.accdb", "rb");
    if (dbFile){

    }else{
        //no existe, escribir en el primer bloque
    }

}
