#include <iostream>
#include "Arbin.h"

using namespace std;

int tesoro(const Arbin<int> &a, int k, int &dragones)  {
	if (a.esVacio()) {
		return 0;
	}
	else {
		if (a.raiz() > 2) {
			return a.raiz();
		}
		
		int dragonesIz = 0, dragonesDer = 0, hojaIz, hojaDer;

		hojaIz = tesoro(a.hijoIz(), k + 1, dragonesIz);
		hojaDer = tesoro(a.hijoDer(), k + 1, dragonesDer);
		
		if (a.raiz() == 1) {
			dragones++;
		}

		dragones += dragonesIz + dragonesDer;

		if (hojaIz > 2 && hojaDer > 2) {
			if (dragonesIz <= dragonesDer) {
				return hojaIz;
			}
			else {
				return hojaDer;
			}
		}
		else if (hojaIz < 2 && hojaDer > 2) {
			return hojaDer;
		}
		else if (hojaDer < 2 && hojaIz > 2) {
			return hojaIz;
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
		int k = 0; //Etapa
		int dragones = 0; //Nivel donde se encuentra la hoja
		Arbin<int> arbol = leerArbol(-1);
		cout << tesoro(arbol, k, dragones) << endl;
	}

	return false;
}

int main() {
	while (resuelve()) {
		;
	}
}