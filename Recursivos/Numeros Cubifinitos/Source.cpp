#include <iostream>

using namespace std;

int buscar(int v[], int buscado, int cont) {
	int ini = 0, fin = cont-1, pos = -1;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) {
		if (buscado == v[ini]) {
			encontrado = true;
			pos = buscado;
		}
		else {
			ini++;
		}
	}

	return pos;
}

void cubifinitos(int v[], int n, int &cont) {
	int suma = 0;
	int cubo = 0;
	int i = 0;
	bool encontrado = false;

	while (n > 0 && !encontrado) {
		cubo = ((n % 10) * (n % 10) * (n % 10));
		suma += cubo;
		n = n / 10;

		if (n == 0) {
			v[i] = suma;
			if (i > 0 && v[i] == buscar(v, suma, i)) {
				encontrado = true;
			}
			else if (v[i] == 1) {
				encontrado = true;
			}

			i++;
			cont++;
			n = suma;
			suma = 0;
		}
	}
}

bool resuelve() {
	int n, cont = 0;
	int v[100000];

	cin >> n;

	if (n == 0) {
		return false;
	}
	else if (n > 0 && n <= 10000000) {
		cubifinitos(v, n, cont);
		
		if (n != 1) {
			cout << n << " - ";
		}
		for (int i = 0; i < cont; i++) {
			cout << v[i];
			
			if (i == cont-1) {
				cout << " -> ";
			}
			else {
				cout << " - ";
			}
		}
		
		if (v[cont-1] == 1) {
			cout << "cubifinito." << endl;
		}
		else {
			cout << "no cubifinito." << endl;
		}
			
	}

	return true;
}

int main() {
	while (resuelve()) {
		;
	}

	return 0;
}