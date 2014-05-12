#ifndef CAMPO_H
#define CAMPO_H
#include <cstdio>
#include <cstring>

class DefCampo
{
public:
    DefCampo();

    int Tipo;
    int Longitud;
    char Nombre[50];

    void aByteArray(char* dest){
        memcpy(&dest[0], &Tipo, 4);
        memcpy(&(dest[4]), &Longitud, 4);
        memcpy(&dest[8], &Nombre, 50);
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
