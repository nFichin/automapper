#include "ElementoCamino.h"
#include "MatrizCamino.h"
#include "AutoMapper.h"
#include <iostream>

int main(){

	MatrizCamino matriz(10,10);
	AutoMapper automapper;

	std::string input;
	int fila, columna;
	while(1){

		matriz.PrintMatriz();

		std::cin >> input;
		if(input == "print"){
			matriz.PrintMatriz();
		}else if(input == "new"){
			std::cin >> fila;
			std::cin >> columna;

			automapper.AgregarElementoCaminoEnPosicion(matriz,Posicion(fila,columna));
		}else if(input == "delete"){
			std::cin >> fila;
			std::cin >> columna;

			automapper.QuitarElementoCaminoEnPosicion(matriz,Posicion(fila,columna));
		}else if(input == "quit" || input == "exit"){
			break;
		}
	}

}
