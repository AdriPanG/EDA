#include <iostream>

using namespace std;

int bocadillosHormiga(unsigned int v[], unsigned int n) {
	int pos = 0;
	int suma = 0;
	int numero = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		suma += v[i];
	}

	if (suma <= 1000000000) {
		suma = 0;
		int i = 0;
		int j = 1;
		while (i < n) {
			if (v[i] > suma && j < n) {
				suma += v[j];
				j++;
			}
			else if ((v[i] == suma) && (numero < suma) && (j == n)) {
				numero = suma;
				pos = i + 1;
			}
			else {
				i++;
				j = i + 1;
				suma = 0;
			}
		}
	}

	return pos;
}

bool resuelve() {
	unsigned int n;
	unsigned int v[100000];
	int resul = 0;

	cin >> n;

	if (n == 0) {
		return false;
	}
	else if (n > 0 && n <= 100000) {
		resul = bocadillosHormiga(v, n);
		if (resul == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "SI " << resul << endl;
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