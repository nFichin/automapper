#include "PosicionAdyacente.h"

PosicionAdyacente::PosicionAdyacente(int fil,int col,t_ladoAdyacencia ladoAdya):Posicion(fil,col) {
	ladoAdyacencia = ladoAdya;
}

PosicionAdyacente::~PosicionAdyacente() {
	// TODO Auto-generated destructor stub
}

