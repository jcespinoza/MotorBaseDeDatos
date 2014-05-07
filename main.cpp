#include "mwindow.h"
#include <iostream>
#include "campo.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);

MWindow w;
    w.show();

    return a.exec();*/
    cout << "TEst0\n";
    Campo campo;
    cout << "TEst1\n";
    campo.Tipo = 0;
    cout << "TEst2\n";
    campo.Longitud = 4;
    //campo.Nombre = "hello";
    cout << "TEst\n";
    char h[6] = "hello";
    cout << "passes\n";
    memcpy(campo.Nombre,h,5);
    cout << campo.Nombre << "\n";
    char* algo = new char[50];
    campo.convertirABytes(algo);
    cout << algo;
    return 0;

}
