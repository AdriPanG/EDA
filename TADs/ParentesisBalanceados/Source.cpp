#include <iostream>
#include "pila.h"
#include <string>

using namespace std;

bool caracterEspecial(char c) {
	if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {
		return true;
	}	
	return false;
}

bool balanceado(string c) {
	Pila<char> pila;
	int contP = 0, contC = 0, contL = 0;
	char cAux;
	string inicio;

	for (int i = 0; i < c.size(); i++) {
		if (caracterEspecial(c[i])) {
			pila.apila(c[i]);
		}
	}

	//Guardamos una variable para saber con cual se inicia la cadena
	if (!pila.esVacia()) {
		if (pila.cima() == '(' || pila.cima() == ')') {
			inicio = "parentesis";
		}
		else if (pila.cima() == '[' || pila.cima() == ']') {
			inicio = "corchete";
		}
		else if (pila.cima() == '{' || pila.cima() == '}') {
			inicio = "llave";
		}
	}

	while (!pila.esVacia()) {
		cAux = pila.cima();
		pila.desapila();
		if (cAux == ')') {
			contP++;
		}
		else if (cAux == '}') {
			contL++;
		}
		else if (cAux == ']') {
			contC++;
		}
		else if (cAux == '(') {
			contP--;
		}
		else if (cAux == '{') {
			contL--;
		}
		else if (cAux == '[') {
			contC--;
		}

		//Si el inicio se cierra antes que el resto, se devuelve false
		if (inicio == "parentesis" && contP == 0 && (contP < contL || contP < contC)) {
			return false;
		} else if (inicio == "corchete" && contC == 0 && (contC < contP || contC < contL)) {
			return false;
		} else if (inicio == "llave" && contL == 0 && (contL < contP || contL < contC)) {
			return false;
		}
	}

	if (contP == 0 && contC == 0 && contL == 0) {
		return true;
	}

	return false;
}

bool resuelve() {
	string cadena;
	getline(cin, cadena);

	while (cadena[0] != '.') {
		if (cadena.size() < 1000) {
			if (balanceado(cadena)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}

		getline(cin, cadena);
	}

	return false;
}

int main() {
	while (resuelve()) {
		;
	}
}