#include "AutoMapper.h"

AutoMapper::AutoMapper() {
}

AutoMapper::~AutoMapper() {
}
void	AutoMapper::QuitarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion pos){
	matriz.matriz[pos.fila * matriz.cantColumnas + pos.columna].SetTipo(NULO);

	std::vector<PosicionAdyacente> posAdyacentes = CalcularPosicionesAdyacentesOcupadas(matriz,pos);
	for(std::vector<PosicionAdyacente>::const_iterator iterador = posAdyacentes.begin();iterador != posAdyacentes.end();iterador++){
		std::vector<PosicionAdyacente> nuevosPosAdyacentes = CalcularPosicionesAdyacentesOcupadas(matriz,*iterador);
		AdaptarElementoANuevoCamino(matriz.matriz[iterador->fila * matriz.cantColumnas + iterador->columna],nuevosPosAdyacentes);
	}
}

void	AutoMapper::AgregarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion pos){
	std::vector<PosicionAdyacente> posAdyacentes = CalcularPosicionesAdyacentesOcupadas(matriz,pos);

	AdaptarElementoANuevoCamino(matriz.matriz[pos.fila * matriz.cantColumnas + pos.columna],posAdyacentes);

	for(std::vector<PosicionAdyacente>::const_iterator iterador = posAdyacentes.begin();iterador != posAdyacentes.end();iterador++){
		std::vector<PosicionAdyacente> nuevosPosAdyacentes = CalcularPosicionesAdyacentesOcupadas(matriz,*iterador);
		AdaptarElementoANuevoCamino(matriz.matriz[iterador->fila * matriz.cantColumnas + iterador->columna],nuevosPosAdyacentes);
	}
}

std::vector<PosicionAdyacente> AutoMapper::CalcularPosicionesAdyacentesOcupadas(MatrizCamino& matriz,const Posicion& posicion){

	std::vector<PosicionAdyacente> posicionesAdyacentes;

	if( ( posicion.fila > 0 ) && ( matriz.matriz[(posicion.fila - 1) * matriz.cantColumnas + posicion.columna].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila - 1,posicion.columna,ARRIBA));
	}
	if( ( posicion.fila < ( matriz.cantFilas - 1 ) ) && ( matriz.matriz[(posicion.fila +1) * matriz.cantColumnas + posicion.columna].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila + 1,posicion.columna,ABAJO));
	}
	if( ( posicion.columna > 0 ) && ( matriz.matriz[posicion.fila * matriz.cantColumnas + posicion.columna - 1].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna - 1,IZQUIERDA));
	}
	if( ( posicion.columna < ( matriz.cantColumnas - 1 ) ) && ( matriz.matriz[posicion.fila * matriz.cantColumnas + posicion.columna + 1].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna + 1,DERECHA));
	}
	return posicionesAdyacentes;
}

void AutoMapper::AdaptarElementoANuevoCamino(ElementoCamino& elementoCamino,std::vector<PosicionAdyacente>& posAdyacentes){
	//Aca se aplican las reglas del automapper
	//TODO abstraer las reglas a algo generico, para darle flexibilidad a la herramienta

	int lados = PonerValorLadosEnUnaVariable(posAdyacentes);

	int cantAdyacentes = posAdyacentes.size();
	elementoCamino_t nuevoTipo;
	switch(cantAdyacentes){
		case 0:{
			nuevoTipo = UNITARIO_WE;
			break;
		}
		case 4:{
			nuevoTipo = CRUZ;
			break;
		}
		default:{
			nuevoTipo = ElegirTipoSegunAdyacencias(lados,cantAdyacentes);
			break;
		}
	}
	elementoCamino.SetTipo(nuevoTipo);
}

int AutoMapper::PonerValorLadosEnUnaVariable(std::vector<PosicionAdyacente>& posAdyacentes){
	int i = 0;
	for( std::vector<PosicionAdyacente>::const_iterator iterador = posAdyacentes.begin() ; iterador != posAdyacentes.end() ; iterador++){
		i |= iterador->ladoAdyacencia;
	}
	return i;
}

elementoCamino_t AutoMapper::ElegirTipoSegunAdyacencias(int ladosAdyacentes,int cantLados){
	switch(cantLados){
		case 1:{
			if( (ladosAdyacentes == IZQUIERDA) || (ladosAdyacentes == DERECHA) ){
				return UNITARIO_WE;
			}else{
				return UNITARIO_NS;
			}
			break;
		}
		case 2:{
			if( ladosAdyacentes == (DERECHA | IZQUIERDA) ){
				return UNITARIO_WE;
			}else if( ladosAdyacentes ==  (ARRIBA | ABAJO) ){
				return UNITARIO_NS;
			}else if( ladosAdyacentes == (ARRIBA | DERECHA) ){
				return CURVA_NE;
			}else if( ladosAdyacentes == (ARRIBA | IZQUIERDA) ){
				return CURVA_NW;
			}else if( ladosAdyacentes == (ABAJO | DERECHA) ){
				return CURVA_SE;
			}else if( ladosAdyacentes == (ABAJO | IZQUIERDA) ){
				return CURVA_SW;
			}
			break;
		}
		case 3:{
			if( (ladosAdyacentes ^ (DERECHA | IZQUIERDA) ) == ARRIBA){
				return T_N;
			}else if( (ladosAdyacentes ^ (DERECHA | IZQUIERDA) ) == ABAJO ){
				return T_S;
			}else if( (ladosAdyacentes ^ (ARRIBA | ABAJO) ) == DERECHA ){
				return T_E;
			}else if( (ladosAdyacentes ^ (ARRIBA | ABAJO) ) ==  IZQUIERDA ){
				return T_W;
			}
			break;
		}
	}
}
