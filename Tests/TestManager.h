#ifndef _TESTMANAGER_H
#define _TESTMANAGER_H

/*
 * Class for running automated tests
 */

#include "Test.h"
#include "../Log/Log.h"
#include <vector>

class TestManager {
protected:
	std::vector<Test*> testList;
public:
	void AddTest(Test* const test);
	void RunTests();
};

#endif // _TESTMANAGER_H
