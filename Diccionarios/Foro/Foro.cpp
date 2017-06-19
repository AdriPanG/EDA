#include "Foro.h"


/*** METODOS DE Mensaje ***/

Mensaje::Mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo):
   _id(id), _remitente(remitente), _asunto(asunto), _cuerpo(cuerpo) {}	

const MID Mensaje::id() const {
	return _id;
}

const string& Mensaje::remitente() const {
   return _remitente;	
}

const string& Mensaje::asunto() const {
   return _asunto;	
}

const string& Mensaje::cuerpo() const {
   return _cuerpo;	
}


/*** METODOS DE Foro ***/

Foro::Foro() {
	// A IMPLEMENTAR
	mensajes = 0;
}
   
void Foro::envia_mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo) {
  // A IMPLEMENTAR
	if (_foro.contiene(id)) {
		throw EMIDDuplicado();
	}
	else {
		_foro.inserta(id, Mensaje(id, remitente, asunto, cuerpo));
		_lista.pon_ppio(id);
		mensajes++;
	}

}

const Mensaje& Foro::consulta_mensaje(MID id) const {
  // A IMPLEMENTAR
	if (!_foro.contiene(id)) {
		throw ENoHayMensaje();
	}
	else {
		return _foro.valorPara(id);
	}
}

void Foro::elimina_mensaje(MID id) {
  // A IMPLEMENTAR
	_foro.borra(id);

	Lista<MID>::Iterator it = _lista.begin();
	Lista<MID>::Iterator fin = _lista.end();
	bool encontrado = false;

	while (it != fin && !encontrado) {
		if (it.elem() == id) {
			_lista.eliminar(it);
			encontrado = true;
			mensajes--;
		}
		it.next();
	}
}
   
Lista<MID> Foro::recupera_mensajes(unsigned int n) const {
  // A IMPLEMENTAR
	Lista<MID> l;
	Lista<MID>::ConstIterator ini = _lista.cbegin();
	Lista<MID>::ConstIterator fin = _lista.cend();
	
	while (ini != fin && n > 0) {
		l.pon_final(ini.elem());
		ini.next();
		n--;
	}

	return l;
	
}

unsigned int Foro::numero_mensajes() const {
  // A IMPLEMENTAR
	return mensajes;
}