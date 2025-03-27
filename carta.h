#ifndef CARTA_H
#define CARTA_H

#include <iostream>

using namespace std;

enum Color { Amarillo, Azul, Rojo, Negro };

class Carta {
public:
    Color color;
    int valor;
    
    Carta(Color c, int v);
    void mostrar() const;
};

#endif // CARTA_H
