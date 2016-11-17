//Adrian Panadero Gonzalez
//Alberto Marquez Gomez

//Precondicion {n >= 0 y 0 < long(v) < 100000}
//int resuelve (int v[], int n) return int resultado;
//Postcondicion {resultado = (#i : 0 <= i < n : v[i]%2 == 0)} 

#include <iostream>
using namespace std;

bool resuelve() {
	int n = 0;
	int v[100000];
	int resultado = 0;
	//lee entrada
	cin >> n;
	if (n == 0)
		return false;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		//calculoresultado
		for (int j = 0; j < n; j++) {
			if (v[j] % 2 == 0) {
				resultado++;
			}
		}
		//imprimo
		cout << resultado << endl;
	}
	return true;
}

int main() {
	while (resuelve()) {
		;
	}
	return 0;
}