#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS
#include "pila.h"

bool noVocal(char elem) {
	if (elem != 'a' && elem != 'e' && elem != 'i' && elem != 'o' && elem != 'u' &&
		elem != 'A' && elem != 'E' && elem != 'I' && elem != 'O' && elem != 'U')
		return true;
	else
		return false;
}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	// A IMPLEMENTAR
	Pila<char> pila;
	Lista<char>::Iterator it = mensaje.begin();

	while (it != mensaje.end()) {
		if (noVocal(it.elem())) {
			pila.apila(it.elem());
			it = mensaje.eliminar(it);
		}
		else {
			while (!pila.esVacia()) {
				mensaje.insertar(pila.cima(), it);
				pila.desapila();
			}
			it.next();
		}
	}
	while (!pila.esVacia()) {
		mensaje.insertar(pila.cima(), it);
		pila.desapila();
	}
}


// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	Lista<char>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem();
		it.next();
	}
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();    // Esta operacion debe ser implementada como
						  // un nuevo metodo de Lista
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}