#include "MatrizCamino.h"
#include <iostream>

MatrizCamino::MatrizCamino(int cantFil,int cantCol) {
	cantFilas = cantFil;
	cantColumnas = cantCol;
	matriz = new ElementoCamino[cantFilas * cantColumnas];
}

MatrizCamino::~MatrizCamino() {
	delete matriz;
}

void MatrizCamino::printMatriz(){
	for(int i = 0; i < cantFilas ; i++){
		for(int j = 0; j < cantColumnas ; j++){
			switch(matriz[i*cantColumnas+j].getTipo()){
				case unitario:{
					std::cout << "-";
					break;
				}
				case formaT:{
					std::cout << "T";
					break;
				}
				case cruz:{
					std::cout << "+";
					break;
				}
				case curva:{
					std::cout << "\\";
					break;
				}
				case nulo:{
					std::cout << "0";
					break;
				}
			}
			std::cout << " ";
		}
		std::cout << "\n";
	}
}
void MatrizCamino::agregarElementoCaminoEnPosicion(Posicion pos){

	std::list<PosicionAdyacente> posAdyacentes = calcularPosicionesAdyacentesOcupadas(pos);

	t_elementoCamino nuevoTipo;
	switch(posAdyacentes.size()){
		case 0:{
			nuevoTipo = unitario;
			break;
		}
		case 1:{
			nuevoTipo = unitario;
			break;
		}
		case 2:{
			nuevoTipo = curva;
			break;
		}
		case 3:{
			nuevoTipo = formaT;
			break;
		}
		case 4:{
			nuevoTipo = cruz;
			break;
		}
	}

	for(std::list<PosicionAdyacente>::const_iterator iterador = posAdyacentes.begin();iterador != posAdyacentes.end();iterador++){

		matriz[iterador->fila * cantColumnas + iterador->columna].adaptateParaConectarEnNuevaDireccion(PosicionAdyacente::direccionOpuesta(iterador->ladoAdyacencia));
	}

	matriz[pos.fila * cantColumnas + pos.columna].setTipo(nuevoTipo);

}

std::list<PosicionAdyacente> MatrizCamino::calcularPosicionesAdyacentesOcupadas(const Posicion posicion){

	std::list<PosicionAdyacente> posicionesAdyacentes;

	if( (posicion.fila > 0) && (matriz[(posicion.fila - 1) * cantColumnas + posicion.columna].getTipo() != nulo) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila - 1,posicion.columna,arriba));
	}
	if( (posicion.fila < (cantFilas-1) ) && (matriz[(posicion.fila +1) * cantColumnas + posicion.columna].getTipo() != nulo) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila + 1,posicion.columna,abajo));
	}
	if( (posicion.columna > 0) && (matriz[posicion.fila * cantColumnas + posicion.columna - 1].getTipo() != nulo) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna - 1,izquierda));
	}
	if( (posicion.columna < (cantColumnas-1) ) && (matriz[posicion.fila * cantColumnas + posicion.columna + 1].getTipo() != nulo) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna + 1,derecha));
	}
	return posicionesAdyacentes;
}
