#include "bloquemaestro.h"
using namespace std;

BloqueMaestro::BloqueMaestro()
{
}

void BloqueMaestro::sendToData()
{
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
    memcpy(data,&cantidadBloques,sizeof(int));
    memcpy(&data[sizeof(int)],&bloqueActivo,sizeof(int));
    memcpy(&data[2*sizeof(int)],&primerBloqueDefTabla,sizeof(int));
    memcpy(&data[3*sizeof(int)],&siguienteBloqueDefTablaLibre,sizeof(int));
    memcpy(&data[4*sizeof(int)],&primerBloqueData,sizeof(int));
    memcpy(&data[5*sizeof(int)],&siguienteBloqueDataLibre,sizeof(int));
    memcpy(&data[6*sizeof(int)],&primerBloqueDefCampo,sizeof(int));
    memcpy(&data[7*sizeof(int)],&siguienteBloqueDefCampoLibre,sizeof(int));
    cout << "Done Copying";
}

void BloqueMaestro::fromBytes(char desde[TAM_BLOQUE])
{

}
