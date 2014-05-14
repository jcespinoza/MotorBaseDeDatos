#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <list>
#include "deftabla.h"
#include <string>
#include "bloquemaestro.h"
using namespace std;

class Controlador
{
public:
    Controlador();
    list<DefTabla> tablas;
    int obtenerIndice(string);
    int agregarTabla(string);
    void inicializarMaster();
    BloqueMaestro master;
};

#endif // CONTROLADOR_H
