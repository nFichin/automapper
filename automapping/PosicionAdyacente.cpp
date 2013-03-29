#include "PosicionAdyacente.h"

PosicionAdyacente::PosicionAdyacente(int fil,int col,t_ladoAdyacencia ladoAdya):Posicion(fil,col) {
	ladoAdyacencia = ladoAdya;
}

PosicionAdyacente::~PosicionAdyacente() {
	// TODO Auto-generated destructor stub
}

t_ladoAdyacencia PosicionAdyacente::direccionOpuesta(t_ladoAdyacencia lado){
	switch(lado){
		case derecha:{
			return izquierda;
			break;
		}
		case izquierda:{
			return derecha;
			break;
		}
		case arriba:{
			return abajo;
			break;
		}
		case abajo:{
			return arriba;
			break;
		}
	}
}

