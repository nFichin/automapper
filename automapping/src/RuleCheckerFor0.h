#ifndef RULECHECKERFOR0_H_
#define RULECHECKERFOR0_H_

#include "RuleChecker.h"

class RuleCheckerFor0: public RuleChecker {
public:
	RuleCheckerFor0();
	virtual ~RuleCheckerFor0();

	elementoCamino_t checkRule(int sides);
};

#endif /* RULECHECKERFOR0_H_ */
