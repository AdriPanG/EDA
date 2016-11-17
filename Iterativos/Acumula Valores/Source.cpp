#include <iostream>
using namespace std;

//Precondicion: {n >= 0 && 0 < long(v) < 100000}
//int acumulaValores (int v[], int n) return aux[];
//Postcondicion: {Para todo i : 0 <= i < n : aux[i] = (sumatorio j: 0 <= j < i: v[j])}

//Complejidad: O(n)

bool resuelve() {
	int i = 0;
	int v[100000];
	int aux[100000];
	int suma = 0;
	cin >> v[0];

	if (v[0] == 0) {
		return false;
	}
	else {
		do {
			i++;
			cin >> v[i];
		} while (v[i] != 0);

		for (int j = 0; j < i; j++) {
			suma += v[j];
			aux[j] = suma;
		}

		//imprimo
		for (int j = 0; j < i; j++) {
			cout << aux[j] << " ";
		}
		cout << endl;
	}
	return true;
}

int main() {
	while (resuelve()) {
		;
	}
	return 0;
}