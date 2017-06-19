#include "Libro.h"
#include "hash.h"

Libro::Libro(const string& nombre) {
	_nombre = nombre;
}

const string& Libro::nombre() const{ 
     return _nombre; 
}

/*** 
IMPLEMENTAR LOS METODOS ADICIONALES
QUE SE CONSIDEREN NECESARIOS 
****/
int Libro::hashcode() const { return ::h(_nombre); }
bool Libro::operator==(const Libro& l) const { return _nombre == l._nombre; }