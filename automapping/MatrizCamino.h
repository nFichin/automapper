#ifndef MATRIZCAMINO_H_
#define MATRIZCAMINO_H_

#include "ElementoCamino.h"
#include <list>

class MatrizCamino {
public:
	int 							cantFilas;
	int 							cantColumnas;
	ElementoCamino *				matriz;

									MatrizCamino(int cantFilas,int cantColumnas);
	virtual 						~MatrizCamino();
	void 							PrintMatriz();
	void 							AgregarElementoCaminoEnPosicion(Posicion posicion);
	std::list<PosicionAdyacente>	CalcularPosicionesAdyacentesOcupadas(const Posicion posicion);

};

#endif /* MATRIZCAMINO_H_ */
