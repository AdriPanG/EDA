#include <iostream>
using namespace std;

//Precondicion: {n >= 0 && 0 < long(v) < 100000}
//int acumulaValores (int v[], int n) return aux[];
//Postcondicion: {Para todo i : 0 <= i < n : aux[i] = (sumatorio j: 0 <= j < i: v[j])}

//Complejidad: O(n)

void resuelve() {
	int n = 0;
	int v[100000];
	int numero = 0;
	int contMax = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		int cont = 0;
		for (int j = i; j < n; j++) {
			if (v[i] == v[j]) {
				cont++;
			}
			if (cont > contMax) {
				contMax = cont;
				numero = v[i];
			}
		}
	}
	
	//imprimo
	cout << numero << " " << contMax << endl;
}

int main() {
	
	int casos = 0;
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		resuelve();
	}
	return 0;
}