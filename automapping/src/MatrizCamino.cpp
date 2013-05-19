#include "MatrizCamino.h"
#include <iostream>
#include "Texture.h"
MatrizCamino::MatrizCamino(int cantFil,int cantCol,SDL_Renderer *renderer) {
	cantFilas = cantFil;
	cantColumnas = cantCol;
	matriz = new ElementoCamino[cantFilas * cantColumnas];
	tileset = cTexture::OnLoad(renderer,"../tileset/tileset_topdown.png");

	for(int fil = 0; fil < cantFil ; ++fil){
		for(int col = 0; col < cantCol ; ++col){
			matriz[fil * cantCol + col].SetPos(fil,col);
		}
	}
}
MatrizCamino::~MatrizCamino() {
	SDL_DestroyTexture(tileset);
}
void MatrizCamino::OnDraw(SDL_Renderer* renderer){
	int destX,destY,srcX,srcY;
	for(int i = 0; i < cantFilas ; i++){
		for(int j = 0; j < cantColumnas ; j++){
			if(matriz[i*cantColumnas+j].GetTipo() == NULO){
				continue;
			}

			destY = i * 40;
			destX = j * 40;

			srcX = ( matriz[i*cantColumnas+j].GetTipo() % 3 ) * 40;
			srcY = ( matriz[i*cantColumnas+j].GetTipo() / 3 ) * 40;

			cTexture::OnDraw(renderer,tileset,destX,destY,srcX,srcY,40,40);
		}
	}
}
