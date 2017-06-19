#include <iostream>
#include "lista.h"

using namespace std;

int main() {
	int casos, valor;
	Lista<int> miLista;

	while (cin >> casos) {
		while (casos > 0) {
			cin >> valor;
			miLista.pon_ppio(valor);
			casos--;
		}

		Lista<int>::Iterator it = miLista.begin();
		Lista<int>::Iterator itEnd = miLista.end();

		//Mostramos Lista
		int contador = 1, total = miLista.longitud();
		while (it != itEnd) {
			if (contador < total)
				cout << it.elem() << " ";
			else
				cout << it.elem();
			it.next();					
			contador++;
		}
		cout << endl;

		//Invertimos y mostramos lista
		miLista.invertir();
		it = miLista.begin();
		contador = 1;
		while (it != itEnd) {
			if (contador < total)
				cout << it.elem() << " ";
			else
				cout << it.elem();
			it.next();
			contador++;
		}
		cout << endl;

		//Borramos lista
		while (!miLista.esVacia())
			miLista.quita_final();
	}
	return 0;
}