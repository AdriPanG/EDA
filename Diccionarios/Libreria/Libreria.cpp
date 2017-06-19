#include "Libreria.h"

Libreria::Libreria() {
	// A IMPLEMENTAR
}

void Libreria::an_libro(const Libro& libro, unsigned int n) {
	// A IMPLEMENTAR
	if (!_libro.contiene(libro)) {
		_libro.inserta(libro, n);
	}
	else {
		int cantidad = n + _libro.valorPara(libro);
		_libro.inserta(libro, cantidad);
	}
}

void Libreria::comprar(const Libro& libro) {
	// A IMPLEMENTAR
	if (!_libro.contiene(libro)) {
		throw ELibroNoExiste();
	}
	else {
		if (_libro.valorPara(libro) == 0) {
			throw ENoHayEjemplares();
		}
		else {
			int cantidad = _libro.valorPara(libro) - 1;
			_libro.inserta(libro, cantidad);
		}
	}
}
bool Libreria::esta_libro(const Libro& libro) const {
	// A IMPLEMENTAR
	if (_libro.contiene(libro)) {
		return true;
	}
	else
		return false;
}

void Libreria::elim_libro(const Libro& libro) {
	// A IMPLEMENTAR
	if (_libro.contiene(libro)) {
		_libro.borra(libro);
	}
}
	
int Libreria::num_ejemplares(const Libro& libro) const {
	// A IMPLEMENTAR
	if (!_libro.contiene(libro)) {
		throw ELibroNoExiste();
	}
	else {
		return _libro.valorPara(libro);
	}
}

int Libreria::num_libros() const {
	// A IMPLEMENTAR
	Diccionario<Libro, int>::ConstIterator it = _libro.cbegin();
	Diccionario<Libro, int>::ConstIterator fin = _libro.cend();

	int libros = 0;

	while (it != fin) {
		libros++;
		it.next();
	}

	return libros;

}
