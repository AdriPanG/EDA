#include <iostream>

using namespace std;

int sumaDigitos(int v[], int n, int &cont) {
	int suma = 0;

	while (n >= 10) {
		suma += n % 10;
		v[cont] = n % 10;
		n = n / 10;
		cont++;
	}

	suma += n % 10;
	v[cont] = n % 10;
	cont++;

	return suma;
}

bool resuelve() {
	int n;
	int v[10];
	int suma = 0;
	int cont = 0;

	cin >> n;

	if (n < 0) {
		return false;
	}
	else if (n >= 0 && n <= 1000000000) {
		suma = sumaDigitos(v, n, cont);

		for (int i = cont-1; i >= 0; i--) {
			cout << v[i];
			if (i != 0) {
				cout << " + ";
			}
		}

		cout << " = " << suma << endl;
	}

	return true;
}

int main() {
	while (resuelve()) {
		;
	}

	return 0;
}