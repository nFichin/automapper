#include "RuleCheckerFor1.h"

RuleCheckerFor1::RuleCheckerFor1() {
	// TODO Auto-generated constructor stub

}

RuleCheckerFor1::~RuleCheckerFor1() {
	// TODO Auto-generated destructor stub
}

elementoCamino_t RuleCheckerFor1::CheckRule(int sides,int cantLados){
	if(cantLados == 1){
		if( (sides == IZQUIERDA) || (sides == DERECHA) ){
			return UNITARIO_WE;
		}else{
			return UNITARIO_NS;
		}
	}else{
		return NULO;
	}
}
