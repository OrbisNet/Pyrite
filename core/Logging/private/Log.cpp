#include "../Public/Log.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

void Log(const char* Category, LogVerbosity Verbosity, const char* Format, ...)
{
    const char* VerbosityStr = nullptr;
    switch (Verbosity) {
        case LogVerbosity::Log:    VerbosityStr = "Log";    break;
        case LogVerbosity::Warning:VerbosityStr = "Warning";break;
        case LogVerbosity::Error:  VerbosityStr = "Error";  break;
        case LogVerbosity::Fatal:  VerbosityStr = "Fatal";  break;
    }
    // Print category and verbosity
    printf("%s: %s: ", Category, VerbosityStr);
    // Print the actual message
    va_list args;
    va_start(args, Format);
    vprintf(Format, args);
    va_end(args);
	printf("\n");
    
}


