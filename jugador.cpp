#include "jugador.h"
#include <iostream>
#include <limits>
using namespace std;

Jugador::Jugador(string n) : nombre(n) {}

void Jugador::mostrarMano() const {
    
    cout << nombre << " - Cartas en mano:" << endl;
    
    for (size_t i = 0; i < mano.size(); i++) {
        
        cout << i + 1 << ". ";
        
        mano[i].mostrar();
        
        cout << endl;
    }
}

Carta Jugador::jugarCarta() {
    
    int opcion;
    
    cout << "Selecciona el número de la carta que deseas jugar: ";
    
    cin >> opcion;
    
    Carta carta = mano[opcion - 1];
    
    mano.erase(mano.begin() + (opcion - 1));
    
    return carta;
}

void Jugador::ganarCartas(const vector<Carta>& cartas) {
    
    for (const auto &carta : cartas) {
        
        cartasGanadas.push_back(carta);
    }
}
