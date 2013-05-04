#ifndef RULECHECKER_H_
#define RULECHECKER_H_

#include "ElementoCamino.h"

class RuleChecker {
public:
	virtual elementoCamino_t CheckRule(int sides, int cantLados) = 0;
};

#endif /* RULECHECKER_H_ */
