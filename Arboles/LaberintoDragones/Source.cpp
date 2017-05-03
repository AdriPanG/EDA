#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void laberintoDragones(const Arbin<string> &a, string &puerta, int &dragones) {
	if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
		puerta = a.raiz();
		dragones = 0;
	}
	else {
		if (a.hijoIz().esVacio()) {
			int dragonesDer = 0;
			string puertaDer;
			laberintoDragones(a.hijoDer(), puertaDer, dragonesDer);
			puerta = puertaDer;
			if (a.raiz() == "Dragon") {
				dragones = dragonesDer + 1;
			}
			else {
				dragones = dragonesDer;
			}
		}
		else if (a.hijoDer().esVacio()) {
			int dragonesIz = 0;
			string puertaIz;
			laberintoDragones(a.hijoIz(), puertaIz, dragonesIz);
			puerta = puertaIz;
			if (a.raiz() == "Dragon") {
				dragones = dragonesIz + 1;
			}
			else {
				dragones = dragonesIz;
			}
		}
		else {
			int dragonesDer = 0, dragonesIz = 0;
			string puertaDer, puertaIz;
			laberintoDragones(a.hijoDer(), puertaDer, dragonesDer);
			laberintoDragones(a.hijoIz(), puertaIz, dragonesIz);
			
			if (dragonesIz <= dragonesDer) {
				puerta = puertaIz;
				dragones = dragonesIz;
			}
			else {
				puerta = puertaDer;
				dragones = dragonesDer;
			}
			
			if (a.raiz() == "Dragon") {
				dragones++;
			}
		}
	}
}

Arbin<string> leerArbol(string nulo) {
	string n;
	cin >> n;
	if (n == nulo)
		return Arbin<string>();	//Devuelve arbol vacio
	Arbin<string> hi = leerArbol(nulo);
	Arbin<string> hd = leerArbol(nulo);
	return Arbin<string>(hi, n, hd);
}

int main() {
	Arbin<string> a;
	int nCasos, dragones;
	cin >> nCasos;
	const string nulo = "...";
	string puerta = "";
	for (int i = 0; i < nCasos; i++) {
		a = leerArbol(nulo);
		laberintoDragones(a, puerta, dragones);
		cout << puerta << " " << dragones;
	}
	
	return 0;
}

