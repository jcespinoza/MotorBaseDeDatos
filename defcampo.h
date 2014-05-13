#ifndef CAMPO_H
#define CAMPO_H
#include <cstdio>
#include <cstring>
#include <iostream>

class DefCampo
{
public:
    DefCampo();

    int Tipo;
    int Longitud;
    char Nombre[50];

    void aBytes(char* dest){
        memcpy(&dest[0], &Tipo, 4);
        memcpy(&(dest[4]), &Longitud, 4);
        memcpy(&dest[8], &Nombre, 50);
    }

    static DefCampo desdeBytes(char* fuente){
        DefCampo res;
        memcpy(&(res.Tipo),&fuente[0], 4);
        memcpy(&(res.Longitud),&(fuente[4]), 4);
        memcpy(res.Nombre,&(fuente[8]), 50);
        return res;
    }
};

class Campo
{
public:
    Campo();
    Campo(int,int);
    int tipo;
    int longitud;
    char* data;

    void aBytes(char* dest){
        memcpy(&dest[0], &tipo, 4);
        memcpy(&dest[4], &longitud, 4);
        memcpy(&dest[8], data, longitud);
    }

    int total(){
        return 2*sizeof(int)+longitud;
    }
};

#endif // CAMPO_H
