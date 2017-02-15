#include <iostream>

using namespace std;

bool poliDivisible(long long int n, int digitos) {
	bool divisible = true;

	if (divisible) {
		if (n > 0  && n < 10) {
			divisible = true;
		} else { 
			if (n % digitos != 0) {
				divisible = false;
			}
			else {
				digitos--;
				divisible = poliDivisible(n / 10, digitos);
			}
		}
	}

	return divisible;
}


bool resuelve () {
	long long int n;
	int digitos = 1;

	cin >> n;

	if (!cin) {
		return false;
	} else {
		long long int aux = n;
		while (aux >= 10) {
			aux = aux / 10;
			digitos++;
		}

		if(poliDivisible(n, digitos))
			cout << "POLIDIVISIBLE" << endl;
		else 
			cout << "NO POLIDIVISIBLE" << endl;
	}

	return true;
}


int main() {

	while (resuelve()) {
		;
	}

	return 0;
}