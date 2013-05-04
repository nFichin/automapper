#ifndef RULECHECKERFOR1_H_
#define RULECHECKERFOR1_H_

#include "RuleChecker.h"

class RuleCheckerFor1 : public RuleChecker {
public:
	RuleCheckerFor1();
	virtual ~RuleCheckerFor1();

	elementoCamino_t CheckRule(int sides,int cantLados);
};

#endif /* RULECHECKERFOR1_H_ */
