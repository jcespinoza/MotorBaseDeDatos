#include "defcampo.h"


using namespace std;

DefCampo::DefCampo()
{

}

Campo::Campo(int t, int lon){
    tipo = t;
    data = new char[lon];
    longitud = lon;
}
