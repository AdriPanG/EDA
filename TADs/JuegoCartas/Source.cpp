#include <iostream>
#include "pila.h"

using namespace std;

struct Carta{
	int num;
	char palo;
};

bool solitario(int numCartas, int numPalos, int sacar, int &veces) {
	int totalCartas = numCartas*numPalos;
	Carta carta;
	Pila<Carta> mazo;
	Pila<Carta> monton;
	Carta palos[4] = {};
	bool ok = false;

	while (totalCartas > 0) {
		cin >> carta.num >> carta.palo;
		if (carta.num <= 12 && (carta.palo == 'A' || carta.palo == 'B' || carta.palo == 'C' || carta.palo == 'D')) {
			monton.apila(carta);
		}
		totalCartas--;
	}

	while (!monton.esVacia() || !mazo.esVacia()) {
		if (!monton.esVacia()) {
			mazo.apila(monton.cima());
			monton.desapila();
			if (sacar > 1 && !monton.esVacia()) {
				mazo.apila(monton.cima());
				monton.desapila();
				if (sacar == 3 && !monton.esVacia()) {
					mazo.apila(monton.cima());
					monton.desapila();
				}
			}
		}
		if (mazo.cima().num == 1 || mazo.cima().num - palos[mazo.cima().palo].num == 1) { //Si la carta es un 1 o la diferencia del mismo palo es 1
			palos[mazo.cima().palo] = mazo.cima(); //Introducimos carta
			ok = true;
			mazo.desapila();
		}

		if (monton.esVacia() && !mazo.esVacia() && (mazo.cima().num - palos[mazo.cima().palo].num != 1)) {
			if (ok == false) {
				return false;
			}
			veces++;
			while (!mazo.esVacia()) {
				monton.apila(mazo.cima());
				mazo.desapila();
			}
		}
	}

	return true;
}

bool resuelve() {

	int nCasos;

	cin >> nCasos;

	while (nCasos > 0) {
		int veces = 0, numCartas, numPalos, sacar;
		cin >> numCartas >> numPalos >> sacar;
		if (numCartas <= 100 && numPalos <= 4 && sacar <= 3) {
			if (solitario(numCartas, numPalos, sacar, veces)) {
				cout << "SI " << veces << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}

	return false;

}

int main() {
	while (!resuelve()) {
		;
	}

	return 0;
}