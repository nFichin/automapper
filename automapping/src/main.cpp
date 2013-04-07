#include "ElementoCamino.h"
#include "MatrizCamino.h"
#include "AutoMapper.h"
#include <iostream>
#include "SDL.h"
#include "Texture.h"

#define TILE_SIZE    40

#define WWIDTH        400
#define WHEIGHT       400

int main(int argc, char *argv[]){

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	SDL_Window *window = NULL;
	if( (window = SDL_CreateWindow("AUTOMAPPING TEST", 100, 100, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN)) == NULL){
		return false;
	}
	SDL_Renderer *renderer = NULL;
	if( (renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED)) == NULL){
		return false;
	}

	MatrizCamino matriz(10,10,renderer);
	AutoMapper automapper;
	elementoCamino_t nuevoTipo = UNITARIO_NS;
	SDL_Event e;
	bool quit = false;
	while (!quit){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
		  //If user presses any key
			if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym){
					case SDLK_ESCAPE:{
						quit = true;
						break;
					}
					default:{
						break;
					}
				}
			}
			if(e.type == SDL_MOUSEMOTION){
			}
			if(e.type == SDL_MOUSEBUTTONDOWN){
				if(e.button.button == SDL_BUTTON_LEFT){
					automapper.AgregarElementoCaminoEnPosicion(matriz,Posicion(e.button.y/TILE_SIZE,e.button.x/TILE_SIZE));
				}else if(e.button.button == SDL_BUTTON_RIGHT){
					automapper.QuitarElementoCaminoEnPosicion(matriz,Posicion(e.button.y/TILE_SIZE,e.button.x/TILE_SIZE));
				}
			}
		}
		//Rendering
		SDL_RenderClear(renderer);
		//Draw the image
		matriz.OnDraw(renderer);
		//Update the screen
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
