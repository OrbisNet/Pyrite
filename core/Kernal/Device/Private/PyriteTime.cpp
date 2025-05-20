#include "core.h"
#include "Kernal/Device/Public/PyriteTime.h"

u32 GetUnixTimeStamp() {
    time_t rawtime;

    rawtime = time(NULL);
    return (u32)rawtime;
}

tm* GetDateTime() {
    time_t rawtime;
    struct tm* timeinfo;

    rawtime = time(NULL);
    timeinfo = gmtime(&rawtime);

    return timeinfo;
}