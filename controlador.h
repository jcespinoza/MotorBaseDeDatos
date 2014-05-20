#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <list>
#include "deftabla.h"
#include <string>
#include "bloquemaestro.h"
#include "bloqueestandar.h"
#include "bloquemdcampos.h"
#include "bloquemdtablas.h"
#include <cstdio>

using namespace std;

class Controlador
{
public:
    Controlador();
    std::string nomArchivo;
    int obtenerIndice(string);
    int agregarTabla(DefTabla);
    void inicializarMaster();
    BloqueMaestro master;
};

#endif // CONTROLADOR_H
