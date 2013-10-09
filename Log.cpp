
#include "Log.h"

void logfMessage(const char* fmt, ...) {
	va_list args;

	FILE* errfile;
	errfile = fopen(LOGFILE, "w");

	va_start(args, fmt);
	vfprintf(errfile, fmt, args);
	printf(fmt, args);
	va_end(args);

	fputs("\n", errfile);
	fclose(errfile);
	
	errfile = NULL;
	
}

void logMessage(const char* message) {
	FILE* errfile;
	errfile = fopen(LOGFILE, "w");

	fputs(message, errfile);
	fputs("\n", errfile);
	
	printf("%s\n", message);

	fclose(errfile);
	
	errfile = NULL;
}

void logError(Error* e) {
	logfMessage("%d: Code %d at %s:%d %s - %s", e->GetTime(), e->GetCode(),
			e->GetFilename(), e->GetLineNumber(), e->GetFunction(),
			e->GetMessage());
}
