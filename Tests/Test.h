#ifndef _TEST_H
#define _TEST_H

/*
 * A base class to inherit from for all automated tests
 */

enum testStatus {
	Pass,
	Warning,
	Fail
};

class Test {
public:
	// Shows up in the test output before the test status
	const char* Name;
	// Optional message which gives information about test status
	char* Message;
	
	testStatus status;
	
	explicit Test(const char* name) : Name(name), status(Fail) {}
	
	// Override this function to do whatever you need to do
	// Make sure to set the status depending on the outcome
	virtual void Run() = 0;
	
	// If you need it, go ahead
	virtual ~Test();
};

#endif // _TEST_H
