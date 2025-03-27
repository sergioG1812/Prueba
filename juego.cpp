#include "juego.h"
#include "carta.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

Juego::Juego( vector<string>& nombresJugadores) {

	for ( auto &nombre : nombresJugadores) {

		jugadores.push_back(Jugador(nombre));
	}
	for (int i = 0; i < 4; i++) {

		Color color = static_cast<Color>(i);

		for (int valor = 1; valor <= 9; valor++) {

			mazo.push_back(Carta(color, valor));
		}
	}

	srand(static_cast<unsigned>(time(0)));

	random_shuffle(mazo.begin(), mazo.end());

	repartirCartas();
}

void Juego::repartirCartas() {

	int indice = 0;

	while (indice < static_cast<int>(mazo.size())) {

		for (auto &jugador : jugadores) {

			if (indice < static_cast<int>(mazo.size())) {

				jugador.mano.push_back(mazo[indice]);

				indice++;
			}
		}
	}
}

void Juego::jugarRonda(int indiceJugadorInicial) {

	vector<Carta> cartasJugadas;

	cout << jugadores[indiceJugadorInicial].nombre << " inicia la ronda." << endl;

	jugadores[indiceJugadorInicial].mostrarMano();

	Carta cartaRef = jugadores[indiceJugadorInicial].jugarCarta();

	cartasJugadas.push_back(cartaRef);

	cout << jugadores[indiceJugadorInicial].nombre << " juega: ";

	cartaRef.mostrar();

	cout << endl;

	for (size_t i = 1; i < jugadores.size(); i++) {
	    
		int indice = (indiceJugadorInicial + i) % jugadores.size();
		
		if (jugadores[indice].mano.size() == 0) continue;
		
		cout << jugadores[indice].nombre << ", es tu turno." << endl;
		
		jugadores[indice].mostrarMano();
		
		Carta carta = jugadores[indice].jugarCarta();
		
		cartasJugadas.push_back(carta);
		
		cout << jugadores[indice].nombre << " juega: ";
		
		carta.mostrar();
		
		cout << endl;
	}

	int maxValor = cartaRef.valor;
	
	int indiceGanador = indiceJugadorInicial;
	
	for (size_t i = 0; i < cartasJugadas.size(); i++) {
	    
		if (cartasJugadas[i].color == cartaRef.color && cartasJugadas[i].valor > maxValor) {
		    
			maxValor = cartasJugadas[i].valor;
			
			indiceGanador = (indiceJugadorInicial + i) % jugadores.size();
		}
	}

	jugadores[indiceGanador].ganarCartas(cartasJugadas);
	
	cout << "\nRonda ganada por " << jugadores[indiceGanador].nombre << "\n" << endl;
}

bool Juego::juegoTerminado() {

	for ( auto &jugador : jugadores) {

		if (!jugador.mano.empty())

			return false;
	}
	return true;
}

void Juego::jugar() {

	int turno = 0;

	while (!juegoTerminado()) {

		jugarRonda(turno % jugadores.size());

		turno++;
	}

	cout << "\nResultados finales:" << endl;

	for ( auto &jugador : jugadores) {

		cout << jugador.nombre << " ganC3 " << jugador.cartasGanadas.size() << " cartas." << endl;
	}
}
