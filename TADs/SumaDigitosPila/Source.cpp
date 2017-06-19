#include <iostream>
#include "pila.h"

using namespace std;

void digitos(int n, Pila<int> &p) {
	int digito = 0;
	

	while (n >= 10) {
		digito = n % 10;
		n = n / 10;
		p.apila(digito);
	}

	digito = n % 10;
	p.apila(digito);
}

bool resuelve() {
	int v[10], n;
	Pila<int> p;
	cin >> n;

	if (n < 0 || n >= 1000000000) {
		return false;
	}
	else {
		digitos(n, p);
		int i = 0, suma = 0;
		while (!p.esVacia()) {
			v[i] = p.cima();
			suma += p.cima();
			p.desapila();
			i++;
		}

		int j = 0;
		while (j < i-1) {
			cout << v[j] << " + ";
			j++;
		}

		cout << v[j] << " = " << suma << endl;
	}

	return true;
}

int main() {
	while (resuelve()) {
		;
	}

	return 0;
}