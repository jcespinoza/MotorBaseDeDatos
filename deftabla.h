#ifndef DEFTABLA_H
#define DEFTABLA_H
#include <list>
#include <iostream>
#include "defcampo.h"

class DefTabla
{
public:
    DefTabla();
    //int nCampos; GUARDAR EN ARCHIVO
    int nRegistros;
    int bloqDatos;
    static int const TAM_CAMPOS = 58;
    char nombre[50];
    std::list<DefCampo> defCampos;

    int totalTamanio(){
        int nReg = defCampos.size();
        return nReg*TAM_CAMPOS + 3*sizeof(int)+sizeof(nombre);
    }

    void aBytes(char *dest){
        //numeroDe Campos
        int elems = defCampos.size();
        memcpy(&dest[0],&elems,4);
        memcpy(&dest[4], &nRegistros, 4);
        memcpy(&dest[8], &bloqDatos, 4);
        memcpy(&dest[12], nombre,sizeof(nombre));
        int a = 70;

        for(std::list<DefCampo>::iterator i = defCampos.begin(); i != defCampos.end(); ++i,a += TAM_CAMPOS){
            char stor[58];
            (*i).aBytes(stor);
            memcpy(&dest[a], stor, TAM_CAMPOS);
        }
    }
};

#endif // DEFTABLA_H
