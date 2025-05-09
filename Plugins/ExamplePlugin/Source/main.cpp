#include <Common.h>
#include <stdbool.h>
#include <string.h>

// Pyrite Includes
#include "core.h"
#include "Logging/public/Log.h"
#include "Kernal/Notification/public/notification.h"

#define PLUGIN_NAME "Example Plugin"
#define PLUGIN_DESC "Pyrite Example Plugin"
#define PLUGIN_AUTH "Tevtongermany"
#define PLUGIN_VER 0x100 // 1.00

DECLARE_LOG_CATEGORY(LogExample);

PUBLIC_ATTRIBUTE const char *g_pluginName = PLUGIN_NAME;
PUBLIC_ATTRIBUTE const char *g_pluginDesc = PLUGIN_DESC;
PUBLIC_ATTRIBUTE const char *g_pluginAuth = PLUGIN_AUTH;
PUBLIC_ATTRIBUTE u32 g_pluginVersion = PLUGIN_VER;


extern "C" {
    
    PUBLIC_ATTRIBUTE s32 plugin_load(s32 argc, const char* argv[])  {
        LOG(LogExample,LogVerbosity::Log,"[GoldHEN] %s Plugin Started.\n", g_pluginName);
        LOG(LogExample,LogVerbosity::Log,"[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
        LOG(LogExample,LogVerbosity::Log,"[GoldHEN] Plugin Author(s): %s\n", g_pluginAuth);


        // Simple Logging Function!
        LOG(LogExample,LogVerbosity::Log,"Hello from Pyrite!");
        LOG(LogExample,LogVerbosity::Fatal,"Fatal Hello from Pyrite!");
        LOG(LogExample,LogVerbosity::Warning,"Warning Hello from Pyrite!");
        LOG(LogExample,LogVerbosity::Error,"Error Hello from Pyrite!");

        // Formatted Logging works aswell!
        // Pretty basic Example but it works
        LOG(LogExample,LogVerbosity::Log,"how much is 1 + 1? its %i", 1+1);

        NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Notifications also work! thanks to OSM <3");

        NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"and Once again Formatting works! : %s","Hello Peter, welcome to fortnite");


        return 0;
    } 


    
    PUBLIC_ATTRIBUTE s32 plugin_unload(s32 argc, const char* argv[]) {
        LOG(LogExample,LogVerbosity::Log,"[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
        LOG(LogExample,LogVerbosity::Log,"[GoldHEN] %s Plugin Ended.\n", g_pluginName);
        return 0;
    }

    
    WEAK_ATTRIBUTE s32 module_start(s64 argc, const void *args) {
        return 0;
    }


    WEAK_ATTRIBUTE s32 module_stop(s64 argc, const void *args) {
        return 0;
    }

} 