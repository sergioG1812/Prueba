#include "carta.h"
#include <string>
Carta::Carta(Color c, int v) : color(c), valor(v) {}

void Carta::mostrar() const {
    string colorString;
    if (color == Amarillo)
        colorString = "Amarillo";
    else if (color == Azul)
        colorString = "Azul";
    else if (color == Rojo)
        colorString = "Rojo";
    else if (color == Negro)
        colorString = "Negro";

    cout << "[" << colorString << " " << valor << "]";
}
