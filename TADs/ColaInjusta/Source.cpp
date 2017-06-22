#include <iostream>
#include "dcola.h"

using namespace std;

void injusta(int v[]) {
	int n = 0, elem;;
	DCola<int> original;

	cin >> v[n];
	
	while (v[n] != -1) {
		original.pon_final(v[n]);
		n++;
		cin >> v[n];
	}

	cin >> elem;

	cout << "{";
	if (v[0] != -1) {
		for (int i = 0; i < n - 1; i++) {
			cout << v[i] << ",";
		}
		cout << v[n - 1] << "}" << endl;
	}
	else {
		cout << "}" << endl;
	}

	if (elem > n - 1) {
		original.invertirElementos(n);
	}
	else {
		original.invertirElementos(elem);
	}

	cout << "{";
	if (v[0] != -1) {
		for (int i = 0; i < n - 1; i++) {
			cout << original.primero() << ",";
			original.quita_ppio();
		}
		cout << v[n - 1] << "}" << endl;
	} 
	else {
		cout << "}" << endl;
	}
}

bool resuelve() {
	int nCasos;
	int v[1000];

	cin >> nCasos;

	while (nCasos > 0) {
		injusta(v);
	}
	
	return false;
}

int main() {
	while (resuelve()) {
		;
	}

	return 0;
}
