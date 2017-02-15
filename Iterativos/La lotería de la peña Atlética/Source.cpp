#include <iostream>

using namespace std;

int loteriaAtleti(unsigned int v[]) {
	int numero = 0;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		if ((v[i] >= 0 && v[i] <= 99999) && v[i] % 2 == 0) {
			numero++;
		}
	}

	return numero;
}

bool resuelve() {
	int nCasos;
	unsigned int v[10000];

	cin >> nCasos;

	for (int i = 0; i < nCasos; i++) {
		cout << loteriaAtleti(v) << endl;
	}

	return false;
}

int main() {
	
	while (resuelve()) {
		;
	}

	return 0;
}