#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cuencaNavegables(const Arbin<int>& a, int &navegables, int tramo) {
	if (a.esVacio()) {
		tramo = 0;
	}
	else {
		if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
			tramo = 1;
		}

		int tramoIz = 0, tramoDer = 0;

		tramoIz = cuencaNavegables(a.hijoIz(), navegables, tramo);
		tramoDer = cuencaNavegables(a.hijoDer(), navegables, tramo);

		tramo = tramoIz + tramoDer + a.raiz();

		if (tramo < 0) {
			tramo = 0;
		}

		if (tramo >= 3) {
			navegables++;
		}
	}

	return tramo;
}

// Devuelve el n�mero de tramos navegables en una cuenca.
// Par�metros:
	// cuenca: La cuenca representada como un �rbol binario
// Resultado:
	// N�mero de afluentes navegables en la cuenca
// Precondici�n: En 'cuenca' hay una representaci�n v�lida de
// una cuenca fluvial (esta precondici�n no es
// necesario comprobarla)
int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int navegables = 0, tramo = 0;

	tramo = cuencaNavegables(cuenca, navegables, tramo);

	if (tramo >= 3) {
		navegables--;
	}

	return navegables;
}

Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF) {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}