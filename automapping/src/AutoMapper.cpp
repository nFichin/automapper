#include "AutoMapper.h"

AutoMapper::AutoMapper() {
	ruleCheckerVector.push_back(new RuleCheckerFor0);
	ruleCheckerVector.push_back(new RuleCheckerFor1);
	ruleCheckerVector.push_back(new RuleCheckerFor2);
	ruleCheckerVector.push_back(new RuleCheckerFor3);
	ruleCheckerVector.push_back(new RuleCheckerFor4);
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

	int lados = ApplyBitwiseOrOperation(posAdyacentes);

	int cantAdyacentes = posAdyacentes.size();
	elementoCamino_t nuevoTipo = NULO;

	std::vector<RuleChecker*>::iterator iterador = ruleCheckerVector.begin();
	for( ; (iterador != ruleCheckerVector.end()) && (nuevoTipo == NULO) ; iterador++){
		nuevoTipo = (*iterador)->CheckRule(lados,cantAdyacentes);
	}

	elementoCamino.SetTipo(nuevoTipo);
}

int AutoMapper::ApplyBitwiseOrOperation(std::vector<PosicionAdyacente>& posAdyacentes){
	int i = 0;
	for( std::vector<PosicionAdyacente>::const_iterator iterador = posAdyacentes.begin() ; iterador != posAdyacentes.end() ; iterador++){
		i |= iterador->ladoAdyacencia;
	}
	return i;
}
