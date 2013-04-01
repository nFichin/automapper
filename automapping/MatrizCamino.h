#ifndef MATRIZCAMINO_H_
#define MATRIZCAMINO_H_

#include "ElementoCamino.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class MatrizCamino {
public:
	int 							cantFilas;
	int 							cantColumnas;
	ElementoCamino *				matriz;
	SDL_Texture						*tileset;

									MatrizCamino(int cantFilas,int cantColumnas,SDL_Renderer *renderer);
	virtual 						~MatrizCamino();
	void 							OnDraw(SDL_Renderer* renderer);
};

#endif /* MATRIZCAMINO_H_ */
