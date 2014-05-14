#ifndef BLOQUEESTANDAR_H
#define BLOQUEESTANDAR_H
#define TAM_BLOQUE 7168

class BloqueEstandar
{
public:
    BloqueEstandar();
    int siguienteBloqueData;
    char data[TAM_BLOQUE];
};

#endif // BLOQUEESTANDAR_H
