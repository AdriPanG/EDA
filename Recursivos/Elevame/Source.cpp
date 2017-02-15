#include <iostream>

using namespace std;

const int k = 31543;

int elevame(int x, int n) {
	
	long long int num = 0;

	if (n == 0) { //Caso base del exponente = 0
		return 1;
	}
	else if (n == 1) { // Caso base del exponente = 1
		return x % k;
	}
	else {
		num = (elevame(x, n/2) % k);// Recursion que devuelve el numero
		num *= num % k;
	}

	if (n % 2 == 1) {
		num *= x % k;
	}

	return num % k;
}

bool resuelve() {
	int x, n;

	cin >> x >> n;

	if (x == 0 && n == 0) {
		return false;
	}
	else if (x >= 0 && n >= 0) {
		cout << elevame(x, n) << endl;
	}


	return true;
}


int main() {

	while (resuelve()) {
		;
	}

	return 0;
}
