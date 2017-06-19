#include "ConfederacionHidrografica.h"
#include <algorithm>
using namespace std;

ConfederacionHidrografica::ConfederacionHidrografica() {}  

void ConfederacionHidrografica::insertar_rio(const string& rio) {
	if (_rios.contiene(rio)) {
		throw new ERioDuplicado();
	}
	else {
		_rios.inserta(rio, Rio());
	}
}

void ConfederacionHidrografica::insertar_pantano(const string& rio, const string& pantano, const float cmax, const float vol) {
	busca_rio(rio).insertar_pantano(pantano, cmax, vol);
}

void ConfederacionHidrografica::embalsar(const string& rio, const string& pantano, const float vol) {
	busca_rio(rio).embalsar(pantano, vol);
}

float ConfederacionHidrografica::embalsado_pantano(const string& rio, const string& pantano) const {
	return busca_rio(rio).embalsado_pantano(pantano);
}

float ConfederacionHidrografica::embalsado_cuenca(const string& rio) const {
	return busca_rio(rio).embalsado_total();
}

void ConfederacionHidrografica::transvasar(const string& rio_origen, const string& pantano_origen,
	const string& rio_destino, const string& pantano_destino, float vol) {
	if (busca_rio(rio_origen).contiene_pantano(pantano_origen) && busca_rio(rio_destino).contiene_pantano(pantano_destino)) {
		if (vol <= busca_rio(rio_origen).embalsado_pantano(pantano_origen) 
			&& (busca_rio(rio_destino).buscar_pantano(pantano_destino).cmax() >= (vol + busca_rio(rio_destino).embalsado_pantano(pantano_destino)))) {
			busca_rio(rio_origen).embalsar(pantano_origen, -vol);
			busca_rio(rio_destino).embalsar(pantano_destino, vol);
		}
	}
}


Rio& ConfederacionHidrografica::busca_rio(const string& rio) {
	Diccionario<string, Rio>::Iterator it = _rios.busca(rio);
	Diccionario<string, Rio>::Iterator fin = _rios.end();
	if (it != fin) {
		return it.valor();
	}
	else {
		throw new ERioNoExiste();
	}
}

const Rio& ConfederacionHidrografica::busca_rio(const string& rio) const {
	Diccionario<string, Rio>::ConstIterator it = _rios.cbusca(rio);
	Diccionario<string, Rio>::ConstIterator fin = _rios.cend();
	if (it != fin) {
		return it.valor();
	}
	else {
		throw new ERioNoExiste();
	}
}