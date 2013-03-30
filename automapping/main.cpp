#include "ElementoCamino.h"
#include "MatrizCamino.h"
#include "AutoMapper.h"
#include <iostream>

int main(){

	MatrizCamino *matriz = new MatrizCamino(10,10);
	AutoMapper *automapper = new AutoMapper();



	automapper->AgregarElementoCaminoEnPosicion(matriz,Posicion(1,1));
	automapper->AgregarElementoCaminoEnPosicion(matriz,Posicion(0,2));
	automapper->AgregarElementoCaminoEnPosicion(matriz,Posicion(0,1));
	automapper->AgregarElementoCaminoEnPosicion(matriz,Posicion(0,0));
	matriz->PrintMatriz();

}
