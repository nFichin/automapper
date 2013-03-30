#include "AutoMapper.h"

AutoMapper::AutoMapper() {
	// TODO Auto-generated constructor stub

}

AutoMapper::~AutoMapper() {
	// TODO Auto-generated destructor stub
}

void AutoMapper::AgregarElementoCaminoEnPosicion(MatrizCamino *matriz,Posicion pos){

	std::list<PosicionAdyacente> posAdyacentes = CalcularPosicionesAdyacentesOcupadas(matriz,pos);

	elementoCamino_t nuevoTipo;
	switch(posAdyacentes.size()){
		case 0:{
			nuevoTipo = UNITARIO;
			break;
		}
		case 1:{
			nuevoTipo = UNITARIO;
			break;
		}
		case 2:{
			nuevoTipo = CURVA;
			break;
		}
		case 3:{
			nuevoTipo = FORMA_T;
			break;
		}
		case 4:{
			nuevoTipo = CRUZ;
			break;
		}
	}

	for(std::list<PosicionAdyacente>::const_iterator iterador = posAdyacentes.begin();iterador != posAdyacentes.end();iterador++){

		matriz->matriz[iterador->fila * matriz->cantColumnas + iterador->columna].AdaptateParaConectarEnNuevaDireccion(PosicionAdyacente::DireccionOpuesta(iterador->ladoAdyacencia));
	}

	matriz->matriz[pos.fila * matriz->cantColumnas + pos.columna].SetTipo(nuevoTipo);

}

std::list<PosicionAdyacente> AutoMapper::CalcularPosicionesAdyacentesOcupadas(MatrizCamino *matriz,const Posicion posicion){

	std::list<PosicionAdyacente> posicionesAdyacentes;

	if( ( posicion.fila > 0 ) && ( matriz->matriz[(posicion.fila - 1) * matriz->cantColumnas + posicion.columna].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila - 1,posicion.columna,ARRIBA));
	}
	if( ( posicion.fila < ( matriz->cantFilas - 1 ) ) && ( matriz->matriz[(posicion.fila +1) * matriz->cantColumnas + posicion.columna].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila + 1,posicion.columna,ABAJO));
	}
	if( ( posicion.columna > 0 ) && ( matriz->matriz[posicion.fila * matriz->cantColumnas + posicion.columna - 1].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna - 1,IZQUIERDA));
	}
	if( ( posicion.columna < ( matriz->cantColumnas - 1 ) ) && ( matriz->matriz[posicion.fila * matriz->cantColumnas + posicion.columna + 1].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna + 1,DERECHA));
	}
	return posicionesAdyacentes;
}
