#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int riosNavegables(const Arbin<int>& a, int &navegables, int tramos) {
	if (a.esVacio()) {
		tramos = 0;
	}
	else {
		if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
			tramos = 1;
		}

		int tramosIz = 0, tramosDer = 0;

		tramosIz = riosNavegables(a.hijoIz(), navegables, tramosIz);
		tramosDer = riosNavegables(a.hijoDer(), navegables, tramosDer);

		tramos += tramosIz + tramosDer + a.raiz();

		if (tramos < 0) {
			tramos = 0;
		}

		if (tramos >= 3) {
			navegables++;
		}
	}

	return tramos;
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int tramos = 0, navegables = 0;
	
	tramos = riosNavegables(cuenca, navegables, tramos);
	
	if (tramos >= 3) {
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