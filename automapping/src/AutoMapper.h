#ifndef AUTOMAPPER_H_
#define AUTOMAPPER_H_

#include <vector>
#include "MatrizCamino.h"
#include "RuleChecker.h"
class AutoMapper {
protected:
	std::vector<RuleChecker> ruleCheckerVector;
public:
									AutoMapper();
	virtual 						~AutoMapper();

	void 							AgregarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	void							QuitarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	std::vector<PosicionAdyacente>	CalcularPosicionesAdyacentesOcupadas(MatrizCamino& matriz,const Posicion& posicion);
	void							AdaptarElementoANuevoCamino(ElementoCamino& elementoCamino,std::vector<PosicionAdyacente>& posAdyacentes);
	int								PonerValorLadosEnUnaVariable(std::vector<PosicionAdyacente>& posAdyacentes);
	elementoCamino_t				ElegirTipoSegunAdyacencias(int ladosAdyacentes,int cantLados);
};

#endif /* AUTOMAPPER_H_ */
