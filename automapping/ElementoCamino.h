#ifndef ELEMENTOCAMINO_H_
#define ELEMENTOCAMINO_H_

#include "PosicionAdyacente.h"

enum elementoCamino_t {
	UNITARIO,FORMA_T,CRUZ,CURVA,NULO
};

class ElementoCamino{
private:
	elementoCamino_t tipoElementoCamino;
public:
						ElementoCamino();
	virtual 			~ElementoCamino();
	elementoCamino_t 	GetTipo();
	void 				SetTipo(elementoCamino_t tipo);

	void 				AdaptateParaConectarEnNuevaDireccion(ladoAdyacencia_t ladoNuevaAdyacencia);

};

#endif /* ELEMENTOCAMINO_H_ */
