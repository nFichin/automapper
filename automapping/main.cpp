#include "ElementoCamino.h"
#include "MatrizCamino.h"

#include <iostream>

int main(){
	MatrizCamino *matriz = new MatrizCamino(10,10);

	matriz->agregarElementoCaminoEnPosicion(Posicion(1,1));
	matriz->agregarElementoCaminoEnPosicion(Posicion(0,2));
	matriz->agregarElementoCaminoEnPosicion(Posicion(0,1));
	matriz->agregarElementoCaminoEnPosicion(Posicion(0,0));
	matriz->printMatriz();

}
