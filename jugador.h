#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include <vector>
#include <string>
using namespace std;

class Jugador {
public:
    string nombre;
    vector<Carta> mano;
    vector<Carta> cartasGanadas;
    
    Jugador(string n);
    void mostrarMano() const;
    Carta jugarCarta();
    void ganarCartas(const vector<Carta>& cartas);
};

#endif
