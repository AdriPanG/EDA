/*Alberto Márquez Gómez
Adrián Panadero González*/

#include "BigVector.h"

BigVector::BigVector() { // A IMPLEMENTAR 

}

double BigVector::valorDe(const unsigned long i) const {
	  // A IMPLEMENTAR
	if (dic.contiene(i)) {
		return dic.valorPara(i);
	}
	else {
		return 0;
	}
}  

void BigVector::ponValor(unsigned long i, double v) {
	// A IMPLEMENTAR
	dic.inserta(i, v);
}  

double BigVector::productoEscalar(const BigVector& v) const {
	// A IMPLEMENTAR
	Diccionario<long, double>::ConstIterator ini = dic.cbegin();
	Diccionario<long, double>::ConstIterator fin = dic.cend();
	double v2 = 0;
	double v1 = 0;
	double producto = 0;

	while (ini != fin) {
		v1 = dic.valorPara(ini.clave());
		v2 = v.valorDe(ini.clave());
		producto += v1 * v2;
		ini.next();
	}

	return producto;
}
   
