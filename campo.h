#ifndef CAMPO_H
#define CAMPO_H

class Campo
{
public:
    Campo();

    int Tipo;
    int Longitud;
    char Nombre[50];

    void convertirABytes(char*);
    //static Campo desdeBytes(char*);
};

#endif // CAMPO_H
