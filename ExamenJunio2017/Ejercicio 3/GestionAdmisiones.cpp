/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "GestionAdmisiones.h"

/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas):
    _nombre(nombre),  _sintomas(sintomas), _edad(edad) {}	

unsigned int Paciente::edad() const {
   return _edad;	
}
const string& Paciente::nombre() const {
   return _nombre;	
}
const string& Paciente::sintomas() const {
   return _sintomas;	
}

/**
Implementa aquí los métodos de las clases adicionales
*/
InfoPaciente::InfoPaciente(const Paciente& paciente, const Grave& grave, const Normal& normal, const Leve& leve) :
	_paciente(paciente), _grave(grave), _normal(normal), _leve(leve) {}

const Paciente& InfoPaciente::paciente() const {
	return _paciente;
}
Grave& InfoPaciente::grave() {
	return _grave;
}
Normal& InfoPaciente::normal() {
	return _normal;
}
Leve& InfoPaciente::leve() {
	return _leve;
}
 
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/ 


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Constante solo se da valor a num_pacientes
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
	num_pacientes = 0;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 Constante porque añade el contiene y el insertar es constanta en los diccionarios hash
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENTAR
	if (_paciente.contiene(codigo)) {
		throw EPacienteDuplicado();
	}
	else {
		if (gravedad == GRAVE) {
			_grave.pon_ppio(codigo);
		}
		else if (gravedad == NORMAL) {
			_normal.pon_ppio(codigo);
		}
		else if (gravedad == LEVE){
			_leve.pon_ppio(codigo);
		}
		num_pacientes++;

		Grave grave = _grave.begin();
		Normal normal = _normal.begin();
		Leve leve = _leve.begin();

		_paciente.inserta(codigo, InfoPaciente(Paciente(nombre, edad, sintomas), grave, normal, leve));

	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 Constante porque la funcion cbusca da el valor directamente sin tener que hacer una busqueda lineal
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	Diccionario<CodigoPaciente, InfoPaciente>::ConstIterator it = _paciente.cbusca(codigo);
	Diccionario<CodigoPaciente, InfoPaciente>::ConstIterator fin = _paciente.cend();

	if (it != fin) {
		nombre = it.valor().paciente().nombre();
		edad = it.valor().paciente().edad();
		sintomas = it.valor().paciente().sintomas();
	}
	else {
		throw EPacienteNoExiste();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENTAR
	if (!_grave.esVacia()) {
		codigo = _grave.ultimo();
		gravedad = GRAVE;
	} else if (!_normal.esVacia()) {
		codigo = _normal.ultimo();
		gravedad = NORMAL;
	} else if (!_leve.esVacia()) {
		codigo = _leve.ultimo();
		gravedad = LEVE;
	} else {
		throw ENoHayPacientes();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 Constante ya que solo se comprueba si la variable es distinto de 0
*/
bool GestionAdmisiones::hay_pacientes() const {  
	// A IMPLEMENTAR
	if (num_pacientes > 0) {
		return true;
	}
	return false;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 Constante ya que la funcion busca obtiene la clave y el valor directamente y el eliminar de las listas
 tambien es constante.
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	Diccionario<CodigoPaciente, InfoPaciente>::Iterator it = _paciente.busca(codigo);
	Diccionario<CodigoPaciente, InfoPaciente>::Iterator fin = _paciente.end();
		
	if (it != fin) {
		if (!_grave.esVacia() && it.valor().grave().elem() == codigo) {
			_grave.eliminar(it.valor().grave());
		}
		else if (!_normal.esVacia() && it.valor()
			.normal().elem() == codigo) {
			_normal.eliminar(it.valor().normal());
		}
		else if (!_leve.esVacia() && it.valor().leve().elem() == codigo){
			_leve.eliminar(it.valor().leve());
		}

		_paciente.borra(codigo);
		num_pacientes--;
	}
}
   
