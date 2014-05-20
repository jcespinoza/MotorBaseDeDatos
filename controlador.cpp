#include "controlador.h"
#include <QDebug>
using namespace std;

Controlador::Controlador()
{
    nomArchivo = "database.accdb";
}

int Controlador::obtenerIndice(string nam)
{
/*
    int indice = 0;
    for(list<DefTabla>::iterator it = tablas.begin(); it != tablas.end(); ++it, indice++){
        string tab( (*it).nombre );
        if( tab.compare(nam) == 0)
            return indice;
    }
    */
    return -1;
}

int Controlador::agregarTabla(DefTabla par)
{
    int encontrado = obtenerIndice(par.nombre);
    if( encontrado != -1)
        return 1; // tabla ya existia
    //agregar la tabla
    int indexNextBloqueTablas = master.siguienteBloqueDefTablaLibre;
    if(indexNextBloqueTablas > 0){
        FILE* dbFile = fopen(nomArchivo.c_str(), "r+b");
        char read[TAM_BLOQUES];
        fread(read,1, TAMA_BLOQUES,dbFile);
        BloqueMDTablas temp_BT = BloqueMDTablas::fromBytes(read);
        temp_BT.agregarTabla(par);
        temp_BT.insertarTablas();
        rewind(dbFile);
        fseek(dbFile,indexNextBloqueTablas*T_BLOQUE+temp_BT.nTablas*DefTabla::TAM_TABLAS,SEEK_SET);
        fwrite(temp_BT.data,1,T_BLOQUE,dbFile);
        fclose(dbFile);
    }
    if(indexNextBloqueTablas == -1){
        indexNextBloqueTablas = 1;
        BloqueMDTablas bt_Block;
        bt_Block.agregarTabla(par);
        bt_Block.insertarTablas();
        FILE* dbFile = fopen(nomArchivo.c_str(), "r+b");

        fseek(dbFile,indexNextBloqueTablas*T_BLOQUE+bt_Block.nTablas*DefTabla::TAM_TABLAS, SEEK_SET);
        fwrite(bt_Block.data,1, T_BLOQUE, dbFile);
        fclose(dbFile);
    }
}

void Controlador::inicializarMaster()
{
    //verificar si el archivo ya existia y si no estaba vacio
    //escribir uno nuevo o leer desde el de acuerdo a cada caso
    FILE* dbFile = fopen(nomArchivo.c_str(), "rb");
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
        dbFile = fopen(nomArchivo.c_str(),"wb");
        //no existe, escribir en el primer bloque
        //fseek(dbFile,0,SEEK_SET);
        master.bloqueActivo=0;
        master.primerBloqueData=-1;
        master.primerBloqueDefCampo=-1;
        master.primerBloqueDefTabla=-1;
        master.siguienteBloqueDataLibre=-1;
        master.siguienteBloqueDefCampoLibre=-1;
        master.siguienteBloqueDefTablaLibre=-1;
        master.cantidadBloques=1;
        master.sendToData();
        qDebug() << "Long:" << master.data;
        int res = fwrite(master.data,1,7168,dbFile);
        //qDebug() << res;
        fclose(dbFile);
    }
}
