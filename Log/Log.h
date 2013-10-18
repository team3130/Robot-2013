#ifndef _LOG_H
#define _LOG_H

/*
 * Utility functions for logging information while the robot runs.
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
