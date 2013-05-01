#include "RuleCheckerFor3.h"

RuleCheckerFor3::RuleCheckerFor3() {
	// TODO Auto-generated constructor stub

}

RuleCheckerFor3::~RuleCheckerFor3() {
	// TODO Auto-generated destructor stub
}

elementoCamino_t RuleCheckerFor3::checkRule(int sides){
	if( (sides ^ (DERECHA | IZQUIERDA) ) == ARRIBA){
		return T_N;
	}else if( (sides ^ (DERECHA | IZQUIERDA) ) == ABAJO ){
		return T_S;
	}else if( (sides ^ (ARRIBA | ABAJO) ) == DERECHA ){
		return T_E;
	}else if( (sides ^ (ARRIBA | ABAJO) ) ==  IZQUIERDA ){
		return T_W;
	}
}
