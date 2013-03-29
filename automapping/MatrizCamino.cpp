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

void MatrizCamino::PrintMatriz(){
	for(int i = 0; i < cantFilas ; i++){
		for(int j = 0; j < cantColumnas ; j++){
			switch(matriz[i*cantColumnas+j].GetTipo()){
				case UNITARIO:{
					std::cout << "-";
					break;
				}
				case FORMA_T:{
					std::cout << "T";
					break;
				}
				case CRUZ:{
					std::cout << "+";
					break;
				}
				case CURVA:{
					std::cout << "\\";
					break;
				}
				case NULO:{
					std::cout << "0";
					break;
				}
			}
			std::cout << " ";
		}
		std::cout << "\n";
	}
}
void MatrizCamino::AgregarElementoCaminoEnPosicion(Posicion pos){

	std::list<PosicionAdyacente> posAdyacentes = CalcularPosicionesAdyacentesOcupadas(pos);

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

		matriz[iterador->fila * cantColumnas + iterador->columna].AdaptateParaConectarEnNuevaDireccion(PosicionAdyacente::DireccionOpuesta(iterador->ladoAdyacencia));
	}

	matriz[pos.fila * cantColumnas + pos.columna].SetTipo(nuevoTipo);

}

std::list<PosicionAdyacente> MatrizCamino::CalcularPosicionesAdyacentesOcupadas(const Posicion posicion){

	std::list<PosicionAdyacente> posicionesAdyacentes;

	if( ( posicion.fila > 0 ) && ( matriz[(posicion.fila - 1) * cantColumnas + posicion.columna].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila - 1,posicion.columna,ARRIBA));
	}
	if( ( posicion.fila < ( cantFilas - 1 ) ) && ( matriz[(posicion.fila +1) * cantColumnas + posicion.columna].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila + 1,posicion.columna,ABAJO));
	}
	if( ( posicion.columna > 0 ) && ( matriz[posicion.fila * cantColumnas + posicion.columna - 1].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna - 1,IZQUIERDA));
	}
	if( ( posicion.columna < ( cantColumnas - 1 ) ) && ( matriz[posicion.fila * cantColumnas + posicion.columna + 1].GetTipo() != NULO ) ){
		posicionesAdyacentes.push_back(PosicionAdyacente(posicion.fila ,posicion.columna + 1,DERECHA));
	}
	return posicionesAdyacentes;
}
