//Alberto Márquez Gómez y Adrián Panadero González

#include <iostream>
#include "cola.h"
using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) {
	Cola<int> cola;
	int cont = 1;
	int num;

	for (int i = 1; i <= n; i++) { //Introducimos los datos en la cola
		cola.pon(i);
	}

	num = cola.primero();
	cola.quita();

	while (!cola.esVacia()) {
		if (cont != m) {
			cola.pon(num);
		}

		num = cola.primero();
		cola.quita();

		cont = cont % m;
		cont++;
	}

	return num;
}


int main() {
	int n, m;
	while ((cin >> n)) {
		cin >> m;
		cout << afortunado(n, m) << endl;
	}
	return 0;
}