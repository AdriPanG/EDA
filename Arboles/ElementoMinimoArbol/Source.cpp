#include <iostream>
#include "Arbin.h"
#include <string>

using namespace std;

template <class T>
T minimo(Arbin<T> a) {
	if (a.hijoDer().esVacio() && a.hijoIz().esVacio()) {
		return a.raiz();
	}
	else {
		T minIz, minDer, min;

		minIz = minimo(a.hijoIz());
		minDer = minimo(a.hijoDer());

		min = a.raiz();

		if (min > minIz) {
			min = minIz;
		}
		else if (min > minDer) {
			min = minDer;
		}

		return min;
	}
}

template <class T>
Arbin<T> leerArbol(const T &repVacio)
{
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else
	{
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi, elem, hd);
	}
}

//template <class T>
bool resuelveCaso() {
	char letra;
	cin >> letra;
	if (letra == 'N') {
		Arbin<int> caminos = leerArbol(-1); // -1 es la repr. de arbol vacio
		cout << minimo(caminos) << endl;
		return true;
	}
	else if (letra == 'P') {
		Arbin<string> caminos;
		string vacio = "#";
		caminos = leerArbol(vacio);
		cout << minimo(caminos) << endl;
		return true;
	}
	else
		return false;
}

int main() {
	while (resuelveCaso()) {
		;
	}

	return 0;
}