#include <iostream>

using namespace std;

int convertir(int numero) {
	int resultado = numero % 10;
	if (numero >= 10) {
		resultado += 6 * convertir(numero/10);
	}
	return resultado;
}


bool resuelve() {
	int n;
	int numero;
	cin >> n;

	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> numero;
		cout << convertir(numero) << endl;
	}

	return false;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}