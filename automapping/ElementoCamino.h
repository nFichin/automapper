#ifndef ELEMENTOCAMINO_H_
#define ELEMENTOCAMINO_H_

#include "PosicionAdyacente.h"
#include <SDL2/SDL.h>

enum elementoCamino_t {
	UNITARIO_NS,UNITARIO_WE,T_S,T_N,T_E,T_W,CRUZ,CURVA_NW,CURVA_NE,CURVA_SE,CURVA_SW,NULO
};

class ElementoCamino{
private:
	elementoCamino_t tipoElementoCamino;
public:
	Posicion 			pos;
						ElementoCamino();
						ElementoCamino(Posicion pos);
	virtual 			~ElementoCamino();
	elementoCamino_t 	GetTipo();
	void 				SetTipo(elementoCamino_t tipo);
	void				SetPos(int fil,int col);

	void 				AdaptateParaConectarEnNuevaDireccion(ladoAdyacencia_t ladoNuevaAdyacencia);
	void 				Draw(SDL_Renderer *renderer);

};

#endif /* ELEMENTOCAMINO_H_ */
