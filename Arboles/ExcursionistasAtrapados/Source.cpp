#include <iostream>
#include "Arbin.h"

using namespace std;

struct Solucion {
	int numEquipos;
	int maxExRuta;
};

int mayor(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

void ayudaEscaladores(Arbin<int> &a, Solucion &sol) {
	if (a.esVacio()) {
		sol.numEquipos = 0; sol.maxExRuta = 0;
	}
	else {
		Solucion solIz, solDer;
		solIz.maxExRuta = 0, solDer.maxExRuta = 0, solIz.numEquipos = 0, solDer.numEquipos = 0;

		ayudaEscaladores(a.hijoIz(), solIz);
		ayudaEscaladores(a.hijoDer(), solDer);

		if (solIz.numEquipos == 0 && solDer.numEquipos == 0 && a.raiz() != 0) {
			sol.numEquipos++;
			sol.maxExRuta += a.raiz();
		}
		else {
			sol.numEquipos = solIz.numEquipos + solDer.numEquipos;
			sol.maxExRuta = mayor(solIz.maxExRuta, solDer.maxExRuta) + a.raiz();
		}
	}
}

Arbin<int> leerArbol(int const& vacio) {
	int raiz;
	cin >> raiz;
	if (raiz == vacio) return Arbin<int>();
	Arbin<int> a1 = leerArbol(vacio);
	Arbin<int> a2 = leerArbol(vacio);
	return Arbin<int>(a1, raiz, a2);
}

bool resuelve() {
	int nCasos;
	Solucion solucion;

	cin >> nCasos;

	while (nCasos > 0) {
		Arbin<int> a = leerArbol(-1);
		solucion.numEquipos = 0; solucion.maxExRuta = 0;
		ayudaEscaladores(a, solucion);
		cout << solucion.numEquipos << " " << solucion.maxExRuta << endl;
	}

	return false;
}


int main() {
	while (resuelve()) {
		;
	}
	return 0;
}