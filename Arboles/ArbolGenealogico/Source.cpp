#include <iostream>
#include "Arbin.h"

using namespace std;

int genealogico(Arbin<int> &a, int &generaciones, bool &encontrado) {
	if (!a.esVacio()) {
		if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
			return a.raiz();
		}
		else {
			int genIz = 1, genDer = 1, numIz = 0, numDer = 0, restaHijos, restaPadre;

			numIz = genealogico(a.hijoIz(), genIz, encontrado);
			numDer = genealogico(a.hijoDer(), genDer, encontrado);

			if (numDer >= 0) {
				restaHijos = numIz - numDer;
			} else{
				restaHijos = numIz;
			}

			restaPadre = a.raiz() - numIz;

			if (restaPadre >= 18 && restaHijos >= 2) {
				if (genIz >= genDer) {
					generaciones = genIz;
				}
				else {
					generaciones = genDer;
				}
				generaciones++;
			}
			else {
				encontrado = false;
			}

			return a.raiz();
		}
	}
}

Arbin<int> leerArbol(const int &vacio)
{
	int elem;
	cin >> elem;
	if (elem == vacio)
		return Arbin<int>();
	else
	{
		Arbin<int> hi = leerArbol(vacio);
		Arbin<int> hd = leerArbol(vacio);
		return Arbin<int>(hi, elem, hd);
	}
}

bool resuelve() {
	int nCasos;

	cin >> nCasos;

	while (nCasos > 0) {
		int generaciones = 1;
		bool encontrado = true;
		Arbin<int> gen = leerArbol(-1);
		genealogico(gen, generaciones, encontrado);

		if (encontrado == true) {
			cout << "YES " << generaciones << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return false;
}

int main() {
	while (resuelve()) {
		;
	}
}