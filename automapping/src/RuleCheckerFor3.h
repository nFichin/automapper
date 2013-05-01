#ifndef RULECHECKERFOR3_H_
#define RULECHECKERFOR3_H_

#include "RuleChecker.h"

class RuleCheckerFor3: public RuleChecker {
public:
	RuleCheckerFor3();
	virtual ~RuleCheckerFor3();

	elementoCamino_t checkRule(int sides);
};

#endif /* RULECHECKERFOR3_H_ */
