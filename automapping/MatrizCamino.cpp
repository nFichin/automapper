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
void MatrizCamino::Draw(SDL_Renderer* renderer){
	for(int i = 0; i < cantFilas ; i++){
		for(int j = 0; j < cantColumnas ; j++){
			matriz[i*cantColumnas+j].Draw(renderer);
		}
	}
}
