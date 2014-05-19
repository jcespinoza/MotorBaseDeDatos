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
    FILE* dbFile = fopen("database.accdb", "rb");
    if (dbFile){
        qDebug() << "Ya existe";
        //Leer del archivo y convertir a bloque maestro
        char buffer[7168];
        fread(buffer,1,7168,dbFile);
        master = BloqueMaestro::fromBytes(buffer);
        qDebug() << master.bloqueActivo;
        qDebug() << master.primerBloqueData;
        qDebug() << master.primerBloqueDefCampo;
        qDebug() << master.primerBloqueDefTabla;
        qDebug() << master.siguienteBloqueDataLibre;
        qDebug() << master.siguienteBloqueDefCampoLibre;
        qDebug() << master.siguienteBloqueDefTablaLibre;
        qDebug() << master.cantidadBloques;
        fclose(dbFile);
    }else{
        qDebug() << "No existe";
        dbFile = fopen("database.accdb","wb");
        //no existe, escribir en el primer bloque
        //fseek(dbFile,0,SEEK_SET);
        master.bloqueActivo=0;
        master.primerBloqueData=-1;
        master.primerBloqueDefCampo=-1;
        master.primerBloqueDefTabla=-1;
        master.siguienteBloqueDataLibre=-1;
        master.siguienteBloqueDefCampoLibre=-1;
        master.siguienteBloqueDefTablaLibre=-1;
        master.cantidadBloques=0;
        master.sendToData();
        qDebug() << "Long:" << master.data;
        int res = fwrite(master.data,1,7168,dbFile);
        //qDebug() << res;
        fclose(dbFile);
    }
}
