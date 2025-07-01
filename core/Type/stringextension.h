#include "core.h"

string FormatString(string first,...){
    if (!first) return nullptr;

    size_t totalLen = 0;
    va_list args;
    // Count length of first arg
    totalLen += strlen(first);
    va_start(args, first);
    const char* arg = nullptr;
    while ((arg = va_arg(args, const char*)) != nullptr) {
        // +1 for the slash separator
        totalLen += 1 + strlen(arg);
    }
    va_end(args);
    char* buffer = (char*)malloc(totalLen + 1);
    if (!buffer) return nullptr;

    // Build the string
    strcpy(buffer, first);

    va_start(args, first);
    while ((arg = va_arg(args, const char*)) != nullptr) {
        // Add slash if not already at end
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] != '/') {
            buffer[len] = '/';
            buffer[len+1] = '\0';
            len++;
        }
        strcat(buffer, arg);
    }
    va_end(args);

    return buffer;  // Caller is responsible for free()
}
