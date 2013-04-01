#include "MatrizCamino.h"
#include <iostream>
#include "Texture.h"
MatrizCamino::MatrizCamino(int cantFil,int cantCol,SDL_Renderer *renderer) {
	cantFilas = cantFil;
	cantColumnas = cantCol;
	matriz = new ElementoCamino[cantFilas * cantColumnas];
	tileset = Textura::OnLoad(renderer,"./tileset/tileset_topdown.png");


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
			matriz[i*cantColumnas+j].Draw(renderer,tileset);
		}
	}
}
