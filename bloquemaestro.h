#ifndef BLOQUEMAESTRO_H
#define BLOQUEMAESTRO_H
//#define TAM_BLOQUE 7168
#include <cstdio>
#include <string>
#include <iostream>
#include <QDebug>

class BloqueMaestro
{
public:
    BloqueMaestro();
    static int const TAM_BLOQUE = 7168;
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
    static BloqueMaestro fromBytes(char [TAM_BLOQUE]);
    void modifyCantidadBloques(int);
    void modifyBloqueActivo(int);
    void modifyPrimerBloqueDefTabla(int);
    void modifyPrimerBloqueData(int);
    void modifyPrimerBloqueDefCampo(int);
    void modifySiguienteBloqueDataLibre(int);
    void modifySiguienteBloqueDefCampoLibre(int);
    void modifySiguienteBloqueDefTablaLibre(int);
};

#endif // BLOQUEMAESTRO_H
