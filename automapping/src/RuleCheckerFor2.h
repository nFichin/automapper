#ifndef RULECHECKERFOR2_H_
#define RULECHECKERFOR2_H_

#include "RuleChecker.h"

class RuleCheckerFor2 : public RuleChecker {
public:
	RuleCheckerFor2();
	virtual ~RuleCheckerFor2();

	elementoCamino_t CheckRule(int sides,int cantLados);
};

#endif /* RULECHECKERFOR2_H_ */
