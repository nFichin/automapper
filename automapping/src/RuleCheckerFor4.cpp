#include "RuleCheckerFor4.h"

RuleCheckerFor4::RuleCheckerFor4() {
	// TODO Auto-generated constructor stub

}

RuleCheckerFor4::~RuleCheckerFor4() {
	// TODO Auto-generated destructor stub
}

elementoCamino_t RuleCheckerFor4::CheckRule(int sides,int cantLados){
	if(cantLados == 4){
		return CRUZ;
	}else{
		return NULO;
	}
}
