#include "RuleCheckerFor2.h"

RuleCheckerFor2::RuleCheckerFor2() {
	// TODO Auto-generated constructor stub

}

RuleCheckerFor2::~RuleCheckerFor2() {
	// TODO Auto-generated destructor stub
}

elementoCamino_t RuleCheckerFor2::CheckRule(int sides){
	if( sides == (DERECHA | IZQUIERDA) ){
		return UNITARIO_WE;
	}else if( sides ==  (ARRIBA | ABAJO) ){
		return UNITARIO_NS;
	}else if( sides == (ARRIBA | DERECHA) ){
		return CURVA_NE;
	}else if( sides == (ARRIBA | IZQUIERDA) ){
		return CURVA_NW;
	}else if( sides == (ABAJO | DERECHA) ){
		return CURVA_SE;
	}else if( sides == (ABAJO | IZQUIERDA) ){
		return CURVA_SW;
	}
}
