#include "PosicionAdyacente.h"

PosicionAdyacente::PosicionAdyacente(int fil,int col,ladoAdyacencia_t ladoAdya):Posicion(fil,col) {
	ladoAdyacencia = ladoAdya;
}

PosicionAdyacente::~PosicionAdyacente() {
	// TODO Auto-generated destructor stub
}

ladoAdyacencia_t PosicionAdyacente::DireccionOpuesta(ladoAdyacencia_t lado){
	switch(lado){
		case DERECHA:{
			return IZQUIERDA;
			break;
		}
		case IZQUIERDA:{
			return DERECHA;
			break;
		}
		case ARRIBA:{
			return ABAJO;
			break;
		}
		case ABAJO:{
			return ARRIBA;
			break;
		}
	}
}

