#ifndef RULECHECKERFOR1_H_
#define RULECHECKERFOR1_H_

#include "RuleChecker.h"

class RuleCheckerFor1 : public RuleChecker {
public:
	RuleCheckerFor1();
	virtual ~RuleCheckerFor1();

	virtual elementoCamino_t checkRule(int sides);
};

#endif /* RULECHECKERFOR1_H_ */
