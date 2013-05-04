#ifndef RULECHECKERFOR4_H_
#define RULECHECKERFOR4_H_

#include "RuleChecker.h"

class RuleCheckerFor4: public RuleChecker {
public:
	RuleCheckerFor4();
	virtual ~RuleCheckerFor4();

	elementoCamino_t CheckRule(int sides,int cantLados);
};

#endif /* RULECHECKERFOR4_H_ */
