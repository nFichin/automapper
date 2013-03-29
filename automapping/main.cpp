#include "ElementoCamino.h"
#include "MatrizCamino.h"

#include <iostream>

int main(){
	MatrizCamino *matriz = new MatrizCamino(10,10);

	matriz->AgregarElementoCaminoEnPosicion(Posicion(1,1));
	matriz->AgregarElementoCaminoEnPosicion(Posicion(0,2));
	matriz->AgregarElementoCaminoEnPosicion(Posicion(0,1));
	matriz->AgregarElementoCaminoEnPosicion(Posicion(0,0));
	matriz->PrintMatriz();

}
