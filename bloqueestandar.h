#ifndef BLOQUEESTANDAR_H
#define BLOQUEESTANDAR_H
#define TAM_BLOQUES 7168

class BloqueEstandar
{
public:
    BloqueEstandar();
    int siguienteBloqueData;
    int siguienteBloqueHermano;
    int espacioLibre;
    char data[TAM_BLOQUES];
};

#endif // BLOQUEESTANDAR_H
