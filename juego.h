#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include <vector>
#include <string>
using namespace std;

class Juego {
public:
    vector<Jugador> jugadores;
    vector<Carta> mazo;
    
    Juego(vector<string>& nombresJugadores);
    
    void repartirCartas();
    
    void jugarRonda(int indiceJugadorInicial);
    
    bool juegoTerminado();
    
    void jugar();
};

#endif 
