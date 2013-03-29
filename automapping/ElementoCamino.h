#ifndef ELEMENTOCAMINO_H_
#define ELEMENTOCAMINO_H_

#include "PosicionAdyacente.h"

typedef enum{
	unitario,formaT,cruz,curva,nulo
} t_elementoCamino;

class ElementoCamino{
private:
	t_elementoCamino tipoElementoCamino;
public:
	ElementoCamino();
	virtual ~ElementoCamino();
	t_elementoCamino getTipo();
	void setTipo(t_elementoCamino tipo);

	void adaptateParaConectarEnNuevaDireccion(t_ladoAdyacencia ladoNuevaAdyacencia);

};

#endif /* ELEMENTOCAMINO_H_ */
