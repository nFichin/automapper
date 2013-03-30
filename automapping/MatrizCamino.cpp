#include "MatrizCamino.h"
#include <iostream>

MatrizCamino::MatrizCamino(int cantFil,int cantCol) {
	cantFilas = cantFil;
	cantColumnas = cantCol;
	matriz = new ElementoCamino[cantFilas * cantColumnas];

	for(int fil = 0; fil < cantFil ; ++fil){
		for(int col = 0; col < cantCol ; ++col){
			matriz[fil * cantCol + col].SetPos(fil,col);

		}
	}
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
