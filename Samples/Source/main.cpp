// C Libraries 
#include <stdbool.h>
#include <string.h>

// Pyrite Includes
#include "core.h"
#include "Logging/Public/Log.h"
#include "Kernal/Notification/Public/notification.h"

// Goldhen
#include <Common.h>

#define PLUGIN_NAME "Example Plugin"
#define PLUGIN_DESC "Example plugin"
#define PLUGIN_AUTH "you"
#define PLUGIN_VER 0x100 // 1.00

DECLARE_LOG_CATEGORY(LogFaith);


extern "C" {
    
    PUBLIC_ATTRIBUTE s32 plugin_load(s32 argc, const char* argv[])  {
        LOG(LogFaith,LogVerbosity::Log,"%s Plugin Started.", PLUGIN_NAME);
        LOG(LogFaith,LogVerbosity::Log,"Plugin Author(s): %s", PLUGIN_AUTH);

        NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Hi From Pyrite!");
      
        return 0;
    } 


    
    PUBLIC_ATTRIBUTE s32 plugin_unload(s32 argc, const char* argv[]) {
        LOG(LogFaith,LogVerbosity::Log,"[GoldHEN] %s Plugin Ended.", PLUGIN_NAME);

        return 0;
    }

    
    WEAK_ATTRIBUTE s32 module_start(s64 argc, const void *args) {
        return 0;
    }


    WEAK_ATTRIBUTE s32 module_stop(s64 argc, const void *args) {
        return 0;
    }

} 
