#include <iostream>
#include "dcola.h"

using namespace std;

void eliminarApariciones(int v[]) {
	int n = 0;
	DCola<int> cola;

	cin >> v[n];
	cola.pon_final(v[n]);
	n++;

	while (v[n - 1] != 0) {
		cin >> v[n];
		cola.pon_final(v[n]);
		n++;
	}
	cola.quita_final();

	cola.duplicar(n-1);

	while(!cola.esVacia()){
		cout << cola.primero() << " ";
		cola.quita_ppio();
	}

	cout << endl;
}

bool resuelve() {
	int nCasos;
	int v[1000];

	cin >> nCasos;

	while (nCasos > 0) {
		eliminarApariciones(v);
	}

	return false;
}

int main() {
	while (resuelve()) {
		;
	}

	return 0;
}