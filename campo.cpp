#include "campo.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

Campo::Campo()
{

}

void Campo::convertirABytes(char* buff)
{
    cout << "Ok" << sizeof(buff);
    memcpy(&(buff), &Tipo, sizeof(int));
    //memcpy(&(buff[sizeof(int)]), &Longitud, 4);
    //memcpy(&(buff[2*sizeof(int)]), Nombre, 4);

}

