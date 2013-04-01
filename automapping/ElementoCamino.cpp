#include "ElementoCamino.h"

ElementoCamino::ElementoCamino() {
	tipoElementoCamino = NULO;
}

ElementoCamino::~ElementoCamino() {
}

elementoCamino_t ElementoCamino::GetTipo(){
	return tipoElementoCamino;
};

void ElementoCamino::SetTipo(elementoCamino_t tipo){
	tipoElementoCamino = tipo;
}

void ElementoCamino::SetPos(int fil,int col){
	pos.fila = fil;
	pos.columna = col;
}
void ElementoCamino::AdaptateParaConectarEnNuevaDireccion(ladoAdyacencia_t ladoNuevaAdyacencia){

}

void ElementoCamino::Draw(SDL_Renderer *renderer,SDL_Texture *spriteSheet){
	SDL_Rect srcRect,destRect;
	srcRect.w = srcRect.h = 40;
	destRect.w = destRect.h = 80;
	switch(tipoElementoCamino){
		case UNITARIO_NS:{
			srcRect.x = 40;
			srcRect.y = 0;
			break;
		}
		case UNITARIO_WE:{
			srcRect.x = 0;
			srcRect.y = 0;
			break;
		}
		case T_S:{
			srcRect.x = 80;
			srcRect.y = 0;
			break;
		}
		case T_N:{
			srcRect.x = 40;
			srcRect.y = 120;
			break;
		}
		case T_E:{
			srcRect.x = 80;
			srcRect.y = 80;
			break;
		}
		case T_W:{
			srcRect.x = 80;
			srcRect.y = 40;
			break;
		}
		case CRUZ:{
			srcRect.x = 0;
			srcRect.y = 40;
			break;
		}
		case CURVA_NW:{
			srcRect.x = 40;
			srcRect.y = 40;
			break;
		}
		case CURVA_NE:{
			srcRect.x = 0;
			srcRect.y = 80;
			break;
		}
		case CURVA_SE:{
			srcRect.x = 0;
			srcRect.y = 120;
			break;
		}
		case CURVA_SW:{
			srcRect.x = 40;
			srcRect.y = 80;
			break;
		}
		case NULO:{
			srcRect.x = 80;
			srcRect.y = 120;
			break;
		}
	}
	destRect.x = pos.columna * 40;
	destRect.y = pos.fila * 40;
	SDL_RenderCopy(renderer,spriteSheet,&srcRect,&destRect);
}
