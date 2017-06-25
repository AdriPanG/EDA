#include <iostream>
#include "lista.h"

using namespace std;

void eliminarApariciones(int v[]) {
	int n = 0, elem;
	Lista<int> lista;
	
	cin >> v[n];
	lista.pon_final(v[n]);
	n++;

	while (v[n-1] != -1) {
		cin >> v[n];
		lista.pon_final(v[n]);
		n++;
	}
	lista.quita_final();

	cin >> elem;

	for (int i = 0; i < n-2; i++) {
		cout << v[i] << " ";
	}
	cout << v[n - 2] << endl;

	lista.eliminarElem(elem, n-1);

	while(!lista.esVacia()) {
		cout << lista.primero() << " ";
		lista.quita_ppio();
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