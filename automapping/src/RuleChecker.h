#ifndef RULECHECKER_H_
#define RULECHECKER_H_

#include "ElementoCamino.h"

class RuleChecker {
public:
	RuleChecker();
	virtual ~RuleChecker();

	virtual elementoCamino_t checkRule(int sides) = 0;
};

#endif /* RULECHECKER_H_ */
