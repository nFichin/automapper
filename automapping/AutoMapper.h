#ifndef AUTOMAPPER_H_
#define AUTOMAPPER_H_

#include <vector>
#include "MatrizCamino.h"
class AutoMapper {
public:
									AutoMapper();
	virtual 						~AutoMapper();

	void 							AgregarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	void							QuitarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	std::vector<PosicionAdyacente>	CalcularPosicionesAdyacentesOcupadas(MatrizCamino& matriz,const Posicion& posicion);
	void							AdaptarElementoANuevoCamino(ElementoCamino& elementoCamino,std::vector<PosicionAdyacente>& posAdyacentes);
	bool							ElementosAdyacentesEstanEnIgualDireccion(std::vector<PosicionAdyacente>& posAdyacentes);

};

#endif /* AUTOMAPPER_H_ */
