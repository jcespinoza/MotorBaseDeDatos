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
    static int const TAM_NOMBRES = 50;
    char nombre[TAM_NOMBRES];
    std::list<DefCampo> defCampos;

    int totalTamanio(){
        int nReg = defCampos.size();
        int ret = nReg*TAM_CAMPOS + 3*sizeof(int)+sizeof(nombre);
        return ret;
    }

    void aBytes(char *dest){
        //numeroDe Campos
        int elems = defCampos.size();
        memcpy(&dest[0],&elems,4);
        memcpy(&dest[4], &nRegistros, 4);
        memcpy(&dest[8], &bloqDatos, 4);
        memcpy(&dest[12], nombre,TAM_NOMBRES);
        int a = 62;

        for(std::list<DefCampo>::iterator i = defCampos.begin(); i != defCampos.end(); ++i,a += TAM_CAMPOS){
            char stor[TAM_CAMPOS];
            (*i).aBytes(stor);

            memcpy(&dest[a], stor, TAM_CAMPOS);
        }
    }

    static DefTabla desdeBytes(char* desde){
        DefTabla resT;
        int nCamp = 0;
        memcpy(&(nCamp), &desde[0], 4);
        memcpy(&(resT.nRegistros), &desde[4],4);
        memcpy(&(resT.bloqDatos), &desde[8], 4);
        memcpy(&(resT.nombre[0]), &desde[12], TAM_NOMBRES);
        int a = 62;
        for(int i = 0; i < nCamp; i++){
            char stor[TAM_CAMPOS];

            memcpy(stor, &desde[a], TAM_CAMPOS);
            DefCampo dc = DefCampo::desdeBytes(stor);
            resT.defCampos.push_back(dc);
            a += TAM_CAMPOS;
        }
        return resT;
    }
};

#endif // DEFTABLA_H
