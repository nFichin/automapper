#ifndef AUTOMAPPER_H_
#define AUTOMAPPER_H_

#include <list>
#include "MatrizCamino.h"
class AutoMapper {
public:
									AutoMapper();
	virtual 						~AutoMapper();

	void 							AgregarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	std::list<PosicionAdyacente>	CalcularPosicionesAdyacentesOcupadas(MatrizCamino& matriz,const Posicion& posicion);
	void							AdaptarElementoANuevoCamino(ElementoCamino& elementoCamino,std::list<PosicionAdyacente>& posAdyacentes);
};

#endif /* AUTOMAPPER_H_ */
