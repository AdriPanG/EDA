#include <iostream>

using namespace std;

int tortitas(int v[], int n) {
	int vueltas;
	int numTortas[100000];

	cin >> vueltas;

	if (v[0] == -1) {
		return -1;
	}

	for (int i = 0; i < vueltas; i++) {
		cin >> numTortas[i];
	}

	for (int i = 0; i < vueltas; i++) {
		int ini = n - numTortas[i];
		int fin = n-1;
		int aux;
		
		while (ini < fin) {
			aux = v[ini];
			v[ini] = v[fin];
			v[fin] = aux;
			ini++;
			fin--;
		}
	}

	return v[n - 1];
}

bool resuelve() {
	int v[100000];
	int n = 0;
	int num = 0;

	do {
		cin >> v[n];
		n++;
	} while (v[n - 1] != -1);

	num = tortitas(v, n-1);

	if (num != -1) {
		cout << num << endl;
	}
	else {
		return false;
	}

	return true;
}

int main() {
	while (resuelve()) {
		;
	}

	return 0;
}