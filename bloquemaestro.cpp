#include "bloquemaestro.h"
using namespace std;

BloqueMaestro::BloqueMaestro()
{
}


BloqueMaestro BloqueMaestro::fromBytes(char desde[TAM_BLOQUE])
{
    BloqueMaestro res;
    qDebug() << sizeof(desde);
    memcpy(res.data,desde,TAM_BLOQUE);
    memcpy(&(res.cantidadBloques), &desde[0], sizeof(int));
    memcpy(&(res.bloqueActivo), &desde[sizeof(int)], sizeof(int));
    memcpy(&(res.primerBloqueDefTabla),&desde[2*sizeof(int)],sizeof(int));
    memcpy(&(res.siguienteBloqueDefTablaLibre),&desde[3*sizeof(int)],sizeof(int));
    memcpy(&(res.primerBloqueData),&desde[4*sizeof(int)],sizeof(int));
    memcpy(&(res.siguienteBloqueDataLibre),&desde[5*sizeof(int)],sizeof(int));
    memcpy(&(res.primerBloqueDefCampo),&desde[6*sizeof(int)],sizeof(int));
    memcpy(&(res.siguienteBloqueDefCampoLibre),&desde[7*sizeof(int)],sizeof(int));
    qDebug() << "Done retrieving";
    return res;
}

void BloqueMaestro::sendToData()
{
    qDebug() << sizeof(data);
    /*
    int cantidadBloques;
    int bloqueActivo;
    int primerBloqueDefTabla;
    int siguienteBloqueDefTablaLibre;
    int primerBloqueData;
    int siguienteBloqueDataLibre;
    int primerBloqueDefCampo;
    int siguienteBloqueDefCampoLibre;
    */
    memcpy(&data[0],&cantidadBloques,sizeof(int));
    memcpy(&data[sizeof(int)],&bloqueActivo,sizeof(int));
    memcpy(&data[2*sizeof(int)],&primerBloqueDefTabla,sizeof(int));
    memcpy(&data[3*sizeof(int)],&siguienteBloqueDefTablaLibre,sizeof(int));
    memcpy(&data[4*sizeof(int)],&primerBloqueData,sizeof(int));
    memcpy(&data[5*sizeof(int)],&siguienteBloqueDataLibre,sizeof(int));
    memcpy(&data[6*sizeof(int)],&primerBloqueDefCampo,sizeof(int));
    memcpy(&data[7*sizeof(int)],&siguienteBloqueDefCampoLibre,sizeof(int));
    qDebug() << "Done Copying";
}


void BloqueMaestro::modifyCantidadBloques(int param)
{
    cantidadBloques = param;
    memcpy(&data[0],&cantidadBloques,sizeof(int));
}

void BloqueMaestro::modifyBloqueActivo(int param)
{
    bloqueActivo = param;
    memcpy(&data[sizeof(int)],&bloqueActivo,sizeof(int));
}

void BloqueMaestro::modifyPrimerBloqueDefTabla(int param)
{
    primerBloqueDefTabla = param;
    memcpy(&data[2*sizeof(int)],&primerBloqueDefTabla,sizeof(int));
}


void BloqueMaestro::modifySiguienteBloqueDefTablaLibre(int param)
{
    siguienteBloqueDefTablaLibre = param;
    memcpy(&data[3*sizeof(int)],&siguienteBloqueDefTablaLibre,sizeof(int));
}

void BloqueMaestro::modifyPrimerBloqueData(int param)
{
    primerBloqueData = param;
    memcpy(&data[4*sizeof(int)],&primerBloqueData,sizeof(int));
}

void BloqueMaestro::modifySiguienteBloqueDataLibre(int param)
{
    siguienteBloqueDataLibre = param;
    memcpy(&data[5*sizeof(int)],&siguienteBloqueDataLibre,sizeof(int));
}

void BloqueMaestro::modifyPrimerBloqueDefCampo(int param)
{
    primerBloqueDefCampo = param;
    memcpy(&data[6*sizeof(int)],&primerBloqueDefCampo,sizeof(int));
}

void BloqueMaestro::modifySiguienteBloqueDefCampoLibre(int param)
{
    siguienteBloqueDefCampoLibre = param;
    memcpy(&data[7*sizeof(int)],&siguienteBloqueDefCampoLibre,sizeof(int));
}

