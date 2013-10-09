#ifndef _LOG_H
#define _LOG_H

// TODO: Set defaults for Try Catch based on defaults from SmartDashboard

/*
 * Utility functions for logging information while the robot runs.
 * Designed primarily to facilitate logging errors that happen due
 * to network errors or invalid keys with smartdashboard.
 * If a try/catch block is used around a smartdashboard get request,
 * values for the variables MUST be initialized to defaults before
 * setting them in the try block, e.g:
 * 
 * float speed = 1.f; // Set default here
 * try {
 * 		SmartDashboard::GetNumber("Speed"); // IF The dashboard works, get the value there
 * } catch (Error* e) {
 * 		// etc...
 * }
 * 
 * Otherwise they might not be set due to an exception, and FOR ONCE
 * the compiler catches this error possiblity.
 */
#include <stdio.h>
#include "Error.h"

/*
 * The location that the log messages will be written to.
 * If we have webconsole available, marshal writes to the
 * logfmessage *FILE to both there and the log file,
 * or something similar
 */
#define LOGFILE "log.txt"

/*
 * Takes a format string and variadic arguments just like normal Printf
 * and writes to the logfile
 */
void logfMessage(const char* fmt, ...);

/*
 * Writes a string directly to the logfile with a \n at the end
 */
void logMessage(const char* message);

/*
 * Takes a WPILib Error Class and prints a predifined pattern:
 * Time: ErrorCode at File:Line Function - Message
 * To the Logfile
 */
void logError(Error* e);


#endif //_LOG_H
