

#ifndef _PYRITE_LOG_H_
#define _PYRITE_LOG_H_
// Macro Definitions
#define DECLARE_LOG_CATEGORY(Name) \
    constexpr const char* Name = #Name

#define LOG(Category, Verbosity, Format, ...) Log(Category, Verbosity, Format, ##__VA_ARGS__)


// Default Log Declarations
DECLARE_LOG_CATEGORY(LogKernalNotification);
DECLARE_LOG_CATEGORY(LogKernal);
DECLARE_LOG_CATEGORY(LogFilesystem);

DECLARE_LOG_CATEGORY(PYRITE);

enum class LogVerbosity {
    Log,
    Warning,
    Error,
    Fatal
};

void Log(const char* Category, LogVerbosity Verbosity, const char* Format, ...);
#endif