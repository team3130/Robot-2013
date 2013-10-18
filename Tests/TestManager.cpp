#include "TestManager.h"

void TestManager::AddTest(Test* const test) {
	testList.push_back(test);
}

void TestManager::RunTests() {
	logMessage("Starting Tests...");
	for (unsigned int i = 0; i < testList.size(); i++) {
		testList[i]->Run();
		char* status;
		switch (testList[i]->status) {
		case Pass:
			status = "PASS";
			break;
			
		case Fail:
			status = "FAIL";
			break;
			
		case Warning:
			status = "WARN";
			break;
		}
		logfMessage("%s %s: %s", testList[i]->Name, status, testList[i]->Message);
	}
}
