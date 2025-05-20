#include <time.h>
#include "core.h"




class PyriteTime {
    public:

    /* Returns a UnixTimeStamp */
    u32 GetUnixTimeStamp();

    /* Returns the current Date time as a Struct */
    tm* GetDateTime();

};