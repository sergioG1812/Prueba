#include "juego.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> nombres = {"Jugador 1", "Jugador 2", "Jugador 3", "Jugador 4"};
    Juego juego(nombres);
    juego.jugar();
    return 0;
}
