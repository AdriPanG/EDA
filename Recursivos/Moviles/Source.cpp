#include <iostream>
using namespace std;

void  moviles(int pi, int di, int pd, int dd, int &peso, bool &ok) {
	int rIz = pi;
	int rDr = pd;
	int adi, add, api, apd;

	if (pi == 0) {
		cin >> api >> adi >> apd >> add;
		moviles(api, adi, apd, add, rIz, ok);
	}
	if (pd == 0) {
		cin >> api >> adi >> apd >> add;
		moviles(api, adi, apd, add, rDr, ok);
	}
	peso = rIz + rDr;
	ok = ok && (rIz * di == rDr * dd);
}

bool resuelve() {
	bool ok = true;
	int peso = 0;
	int di, dd, pi, pd;
	
	//lee los numeros
	cin >> pi >> di >> pd >> dd;
	//salimos
	if ((pd == 0) && (dd == 0) && (pi == 0) && (di == 0))
		return false;

	moviles(pi, di, pd, dd, peso, ok);

	if (ok) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return true;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}