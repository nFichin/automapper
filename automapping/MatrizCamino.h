#ifndef MATRIZCAMINO_H_
#define MATRIZCAMINO_H_

#include "ElementoCamino.h"
#include <list>

class MatrizCamino {
public:
	int cantFilas,cantColumnas;
	ElementoCamino *matriz;

	MatrizCamino(int cantFilas,int cantColumnas);
	virtual ~MatrizCamino();
	void printMatriz();
	void agregarElementoCaminoEnPosicion(Posicion posicion);
	std::list<PosicionAdyacente> calcularPosicionesAdyacentesOcupadas(const Posicion posicion);

};

#endif /* MATRIZCAMINO_H_ */
