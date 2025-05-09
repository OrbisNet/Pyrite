
// Macro Definitions
#define DECLARE_LOG_CATEGORY(Name) \
    constexpr const char* Name = #Name

#define LOG(Category, Verbosity, Format, ...) Log(Category, Verbosity, Format, ##__VA_ARGS__)


enum class LogVerbosity {
    Log,
    Warning,
    Error,
    Fatal
};

void Log(const char* Category, LogVerbosity Verbosity, const char* Format, ...);