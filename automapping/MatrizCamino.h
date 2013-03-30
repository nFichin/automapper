#ifndef MATRIZCAMINO_H_
#define MATRIZCAMINO_H_

#include "ElementoCamino.h"


class MatrizCamino {
public:
	int 							cantFilas;
	int 							cantColumnas;
	ElementoCamino *				matriz;

									MatrizCamino(int cantFilas,int cantColumnas);
	virtual 						~MatrizCamino();
	void 							PrintMatriz();
};

#endif /* MATRIZCAMINO_H_ */
