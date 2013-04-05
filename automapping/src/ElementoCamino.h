#ifndef ELEMENTOCAMINO_H_
#define ELEMENTOCAMINO_H_

#include "PosicionAdyacente.h"
#include "SDL.h"

enum elementoCamino_t {
	UNITARIO_WE,UNITARIO_NS,T_S,CRUZ,CURVA_NW,T_W,CURVA_NE,CURVA_SW,T_E,CURVA_SE,T_N,NULO
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
};

#endif /* ELEMENTOCAMINO_H_ */
