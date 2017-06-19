#include <iostream>
#include "ConfederacionHidrografica.h"
#include <string>

using namespace std;

int main() {
	ConfederacionHidrografica hidro;
	string rio, pantano;
	float cmax, vol;
	string rio2, pantano2;
	float cmax2, vol2;

	cout << "Introduce rio: ";
	cin >> rio;
	cout << "Introduce pantano, capacidad maxima, volumen: ";
	cin >> pantano >> cmax >> vol;

	hidro.insertar_rio(rio);
	hidro.insertar_pantano(rio, pantano, cmax, vol);

	cout << "Introduce rio: ";
	cin >> rio2;
	cout << "Introduce pantano, capacidad maxima, volumen: ";
	cin >> pantano2 >> cmax2 >> vol2;

	hidro.insertar_rio(rio2);
	hidro.insertar_pantano(rio2, pantano2, cmax2, vol2);

	hidro.transvasar(rio, pantano, rio2, pantano2, 20);

	return 0;
}