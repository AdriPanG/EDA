#ifndef _LIBRO_H
#define _LIBRO_H

#include "hash.h"
#include <string>
using namespace std;

class Libro {
public:
	int hashcode() const;
	// para las tablas hash y los árboles de búsqueda
	bool operator==(const Libro& l) const;
    /**
	  Crea un libro a partir de su nombre
	*/
   	Libro(const string& nombre);
	/**
	  Devuelve el nombre del libro
	*/
    const string& nombre() const; 
	/**
	  DECLARAR LOS MÉTODOS ADICIONALES QUE SE CONSIDEREN NECESARIOS 
	**/
private:
     /** El nombre del libro */
	string _nombre;
};

#endif