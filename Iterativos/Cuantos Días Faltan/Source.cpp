#include <iostream>

using namespace std;

int nochevieja(int n, int dia, int mes) {
	int restantes = 0; //dias que quedan para nochevieja

	if (mes >= 1 && mes <= 12 && dia >= 1) {

		while (mes <= 12) {
			if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
				if (dia <= 31) {
					restantes += (32 - dia);
				}
			}
			else if (mes == 2) {
				if (dia <= 28) {
					restantes += (29 - dia);
				}
			}
			else {
				if (dia <= 30) {
					restantes += (31 - dia);
				}
			}
			dia = 1;
			mes++;
		}
	}

	return restantes-1;
}

bool resuelve() {
	int n;
	int dia = 0, mes = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dia >> mes;
		cout << nochevieja(n, dia, mes) << endl;
	}


	return false;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}