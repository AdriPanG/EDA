#include <iostream>
#include "Arbin.h"

using namespace std;

/*Podemos utilizar los árboles binarios para representar los caminos en la falda de una
 montaña. La raíz del árbol representa la cima de la que salen una o dos rutas. Las distintas
 rutas según se va ensanchando la falda de la montaña se dividen en dos formando caminos que
 nunca se volverán a conectar. Un escalador está en la cima de la montaña (raíz del árbol) y
 se da cuenta de que en distintas intersecciones (marcadas en el árbol con ’X’) hay amigos que
 necesitan su ayuda para subir. Tiene que bajar a cada una de las ’X’ y ayudarles a subir de
 uno en uno. Implementa una función con la cabecera
 
 int tiempoAyuda(const Arbin<char> &a);
 
 que, dado uno de estos árboles binarios, devuelva el tiempo que tardará el escalador en ayudar
 a todos esos amigos si cada tramo de intersección a intersección lleva una hora en ser recorrido
 (en cada uno de los dos sentidos).*/

int tiempoAyuda(const Arbin<char> &a, int k) {
	if (a.esVacio()) {
		return 0;
	}
	else {
		int tiempo = 0;
		if (a.raiz() == 'X') {
			tiempo += k * 2;
		}
		
		return tiempo + tiempoAyuda(a.hijoIz(), k + 1) + tiempoAyuda(a.hijoDer(), k + 1);
	}
}

Arbin<char> leerArbol(const char &vacio)
{
	char elem;
	cin >> elem;
	if (elem == vacio)
		return Arbin<char>();
	else
	{
		Arbin<char> hi = leerArbol(vacio);
		Arbin<char> hd = leerArbol(vacio);
		return Arbin<char>(hi, elem, hd);
	}
}

bool resuelve() {
	int nCasos;

	cin >> nCasos;

	while (nCasos > 0) {
		int tiempo = 0;
		Arbin<char> arbol = leerArbol('Z');
		cout << tiempoAyuda(arbol, 0) << endl;
	}

	return false;
}

int main() {
	while (resuelve()) {
		;
	}
}
