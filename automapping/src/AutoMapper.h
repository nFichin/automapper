#ifndef AUTOMAPPER_H_
#define AUTOMAPPER_H_

#include <vector>
#include "MatrizCamino.h"
#include "RuleChecker.h"
#include "RuleCheckerFor0.h"
#include "RuleCheckerFor1.h"
#include "RuleCheckerFor2.h"
#include "RuleCheckerFor3.h"
#include "RuleCheckerFor4.h"

class AutoMapper {
protected:
	std::vector<RuleChecker*> ruleCheckerVector;
public:
									AutoMapper();
	virtual 						~AutoMapper();

	void 							AgregarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	void							QuitarElementoCaminoEnPosicion(MatrizCamino& matriz,Posicion posicion);
	std::vector<PosicionAdyacente>	CalcularPosicionesAdyacentesOcupadas(MatrizCamino& matriz,const Posicion& posicion);
	void							AdaptarElementoANuevoCamino(ElementoCamino& elementoCamino,std::vector<PosicionAdyacente>& posAdyacentes);
	int								ApplyBitwiseOrOperation(std::vector<PosicionAdyacente>& posAdyacentes);
	elementoCamino_t				ElegirTipoSegunAdyacencias(int ladosAdyacentes,int cantLados);
};

#endif /* AUTOMAPPER_H_ */
