#ifndef BLOQUEMAESTRO_H
#define BLOQUEMAESTRO_H
#define TAM_BLOQUE 7168
#include <cstdio>
#include <string>
#include <iostream>

class BloqueMaestro
{
public:
    BloqueMaestro();
    char data[TAM_BLOQUE];
    int cantidadBloques;
    int primerBloqueDefTabla;
    int primerBloqueData;
    int primerBloqueDefCampo;
    int bloqueActivo;
    int siguienteBloqueDataLibre;
    int siguienteBloqueDefCampoLibre;
    int siguienteBloqueDefTablaLibre;

    void sendToData();
    void fromBytes(char [TAM_BLOQUE]);
};

#endif // BLOQUEMAESTRO_H
