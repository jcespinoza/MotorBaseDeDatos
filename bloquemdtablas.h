#ifndef BLOQUEMDTABLAS_H
#define BLOQUEMDTABLAS_H
#define T_BLOQUE 7168
#include <cstdio>
#include <string>
#include <iostream>
#include <list>
#include "deftabla.h"

class BloqueMDTablas
{
public:
    BloqueMDTablas();
    int estaLleno;
    int nTablas;
    int siguienteHermano;
    char data[T_BLOQUE];
    std::list<DefTabla> tablas;

    void modifyEstaLleno(int);
    void modifyNTablas(int);
    void modifySiguienteHermano(int);

    void insertarTablas();
    void agregarTabla(DefTabla);

    static BloqueMDTablas fromBytes(char[]);
};

#endif // BLOQUEMDTABLAS_H
