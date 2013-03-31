#ifndef MATRIZCAMINO_H_
#define MATRIZCAMINO_H_

#include "ElementoCamino.h"
#include <SDL2/SDL.h>

class MatrizCamino {
public:
	int 							cantFilas;
	int 							cantColumnas;
	ElementoCamino *				matriz;
	SDL_Texture						*tileset;

									MatrizCamino(int cantFilas,int cantColumnas);
	virtual 						~MatrizCamino();
	void 							Draw(SDL_Renderer* renderer);
};

#endif /* MATRIZCAMINO_H_ */
