//Alberto Máquez Gómez
//Adrian Panadero Gonzalez

#include <iostream>
#include <string>
#include "diccionario.h"
#include "lista.h"

using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
public:
	string alumno;
	int nota;
	Puntuacion(const string& nombre, int puntuacion) : alumno(nombre), nota(puntuacion) {}
};
// Devuelve una lista con las puntuaciones de aquellos alumnos cuya
// calificación final es distinta de 0. Dicha lista está ordenada
// alfabéticamente por nombre de alumno
// Parámetros:
// bien: Lista de alumnos que han resuelto correctamente un ejercicio (si
// un alumno ha resuelto correctamente varios ejercicios, aparecerá
// varias veces en la lista)
// mal: Lista de alumnos que han resuelto incorrectamente un ejercicio (si
// un alumno ha resuelto correctamente varios ejercicios, aparecerá
// varias veces en la lista)
// listado: Listado de calificaciones, ordenado alfabéticamente por nombre
// de alumno. Solo aparecen aquellos alumnos cuya calificación final
// es distinta de 0.La clase Puntuacion permite representar la
// calificación de un alumno, y está definida en main.cpp.
void califica(const Lista<string> & bien, const Lista<string> & mal, Lista<Puntuacion> & listado) {
	Diccionario<string, int> dic;

	Lista<string>::ConstIterator ini = bien.cbegin();
	Lista<string>::ConstIterator fin = bien.cend();
	
	while (ini != fin) {
		int c = 1;
		if(dic.contiene(ini.elem())) {
			c = dic.valorPara(ini.elem()) + 1;
			dic.borra(ini.elem());
		}
		dic.inserta(ini.elem(), c);
		ini.next();
	}

	Lista<string>::ConstIterator ini2 = mal.cbegin();
	Lista<string>::ConstIterator fin2 = mal.cend();

	while (ini2 != fin2) {
		int c = -1;
		if (dic.contiene(ini2.elem())) {
			c = dic.valorPara(ini2.elem()) - 1;
			dic.borra(ini2.elem());
		}
		dic.inserta(ini2.elem(), c);
		ini2.next();
	}

	Diccionario<string, int>::ConstIterator iniC = dic.cbegin();
	Diccionario<string, int>::ConstIterator finC = dic.cend();

	while (iniC != finC) {
		if (iniC.valor() != 0) {
			Puntuacion p = Puntuacion(iniC.clave(), iniC.valor());
			listado.pon_final(p);
		}
		iniC.next();
	}
}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
	while (i != e) {
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
	string comienzo;
	while (cin >> comienzo) {
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal, listado);
		imprimePuntuaciones(listado);
	}
	return 0;
}