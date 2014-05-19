#include "controlador.h"
#include <QDebug>
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
    FILE* dbFile = fopen("database.accdb", "r+");
    if (dbFile){
        qDebug() << "Ya existe";
    }else{
        qDebug() << "No existe";
        //no existe, escribir en el primer bloque
        //fseek(dbFile,0,SEEK_SET);
        master.sendToData();
        master.bloqueActivo=0;
        master.primerBloqueData=-1;
        master.primerBloqueDefCampo=-1;
        master.primerBloqueDefTabla=-1;
        master.siguienteBloqueDataLibre=-1;
        master.siguienteBloqueDefCampoLibre=-1;
        master.siguienteBloqueDefTablaLibre=-1;
        master.cantidadBloques=0;
        int res = fwrite(master.data,1,7168,dbFile);
        qDebug() << res;
        fclose(dbFile);
    }

}
