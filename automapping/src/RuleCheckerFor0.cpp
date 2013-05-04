#include "RuleCheckerFor0.h"

RuleCheckerFor0::RuleCheckerFor0() {
	// TODO Auto-generated constructor stub

}

RuleCheckerFor0::~RuleCheckerFor0() {
	// TODO Auto-generated destructor stub
}

elementoCamino_t RuleCheckerFor0::CheckRule(int sides,int cantLados){
	if(cantLados == 0){
		return UNITARIO_NS;
	}else {
		return NULO;
	}
}
