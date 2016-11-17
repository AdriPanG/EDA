#include <iostream>
using namespace std;

//Precondicion: {n >= 0 && 0 <= n < long(v)}
//fun interParImpar(int v[], int n, out int pares, out int impares)
/*Postcondicion: pares = {#i: 1 <= i < n-1 : (v[i-1] % 2 == 0 && v[i+1] % 2 == 0)) &&
				impares = {#i: 1 <= i < n-1 : (v[i-1] % 2 != 0 && v[i+1] % 2 != 0))
*/

//Calcula los interPares e interImpares
void inter(int v[], int n, int &pares, int &impares) {
	for (int i = 1; i < n - 1; i++) {
		if ((v[i - 1] % 2 == 0) && (v[i + 1] % 2 == 0)) {
			pares++;
		}
		else if ((v[i - 1] % 2 != 0) && (v[i + 1] % 2 != 0)) {
			impares++;
		}
	}
}

bool resuelve() {
	int v[10000];
	int n = 0;
	int pares = 0, impares = 0;
	cin >> n;

	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		//funcion aux
		inter(v, n, pares, impares);

		//imprime
		cout << pares << " " << impares << endl;
	}

	return true; 
}


int main() {
	while (resuelve()) {
		;
	}

	return 0;
}