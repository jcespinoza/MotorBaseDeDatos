#include "bloquemdtablas.h"

BloqueMDTablas::BloqueMDTablas()
{
    estaLleno = 0;
    nTablas = 0;
    siguienteHermano = -1;
}

void BloqueMDTablas::modifyEstaLleno(int par)
{
    estaLleno = par;
    memcpy(data,&estaLleno, sizeof(int));
}

void BloqueMDTablas::modifyNTablas(int par){
    nTablas = par;
    memcpy(&data[sizeof(int)], &nTablas, sizeof(int));
}

void BloqueMDTablas::modifySiguienteHermano(int par)
{
    siguienteHermano = par;
    memcpy(&data[2*sizeof(int)], &siguienteHermano, sizeof(int));
}

void BloqueMDTablas::insertarTablas()
{
    int max_numberOfTables = (T_BLOQUE-3*sizeof(int))/70;
    int i = 3*sizeof(int);
    for(std::list<DefTabla>::iterator it = tablas.begin(); it != tablas.end(); ++it){
        if(nTablas <= max_numberOfTables){
            DefTabla def = *it;
            char *buf = new char[def.tamanio()];
            def.metaToBytes(buf);
            memcpy(&data[i],buf,def.tamanio());
            nTablas++;
            i += def.tamanio();
        }
    }
}

void BloqueMDTablas::agregarTabla(DefTabla def)
{
    tablas.push_back(def);
    modifyNTablas(++nTablas);
}

BloqueMDTablas BloqueMDTablas::fromBytes(char desde[T_BLOQUE])
{
    BloqueMDTablas res;
    memcpy(&(res.estaLleno), desde,sizeof(int));
    memcpy(&(res.nTablas), &desde[sizeof(int)],sizeof(int));
    memcpy(&(res.siguienteHermano), &desde[2*sizeof(int)], sizeof(int));
    memcpy(res.data, desde, T_BLOQUE);
    return res;
}
