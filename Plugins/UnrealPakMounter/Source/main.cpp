#include <Common.h>
#include <stdbool.h>
#include <string.h>
#include <orbis/libkernel.h>
#include <time.h>

// Pyrite Includes
#include "core.h"
#include "Logging/Public/Log.h"
#include "Kernal/Notification/Public/notification.h"
#include "Kernal/Filesystem/Public/FileManager.h"
#include "ThirdParty/Json.hpp"

#define PLUGIN_NAME "Unreal Pak Mounter"
#define PLUGIN_DESC "Mounts Paks from a specific Directory"
#define PLUGIN_AUTH "Tevtongermany"
#define PLUGIN_VER 0x100 // 1.00

string UEPakMounterDir;



DECLARE_LOG_CATEGORY(LogUnrealPakMounter);

using json = nlohmann::json;

extern "C" {
    
    PUBLIC_ATTRIBUTE s32 plugin_load(s32 argc, const char* argv[])  
    {
        LOG(PYRITE,LogVerbosity::Log," %s Plugin Started.", PLUGIN_NAME);
        LOG(PYRITE,LogVerbosity::Log,"<%s\\Ver.0x%08x> %s", PLUGIN_NAME, PLUGIN_VER, __func__);
        LOG(PYRITE,LogVerbosity::Log,"Plugin Author(s): %s", PLUGIN_AUTH);
        // Create the UEPAKMNTR directory
        if (!FileManager::createDir(FileManager::makePath(GOLDHENDIR,"/UEPAKMNTR"))){
            NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Could not create UEPAKMNTR Dir");
            return 0;
        }

        LOG(LogUnrealPakMounter,LogVerbosity::Log,"Created dir UEPAKMNTR!");


        proc_info procInfo{};
        if (sys_sdk_proc_info(&procInfo) != 0)
        {
            NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Couldnt Get Title Id!, Terminating");
            return 0;
        }   
        // Create the directory that houses the pak and the config json
        UEPakMounterDir = FileManager::makePath(GOLDHENDIR,"/UEPAKMNTR/",procInfo.titleid);

        if (FileManager::createDir(UEPakMounterDir)) {
            LOG(LogUnrealPakMounter,LogVerbosity::Log,"Created dir %s", UEPakMounterDir);
        }
             
        string configfile = FileManager::makePath(UEPakMounterDir,"/",procInfo.titleid,".json");
        string configfileContent;
        

        // Check if config file exists
        if (!FileManager::fileExists(configfile)) {
            NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Couldn't find Config File! Make Sure you actually have one");
            return 0;
        }

        configfileContent = FileManager::readfile(configfile);

        if (!configfileContent) {
            NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Could Not read config file!");
            return 0;
        }
        json configJson;

        // Try parsing Json file
        configJson = json::parse(configfileContent);
        if (!configJson) {
            NOTIFY(PS_NOTIFICATION_TEX_ICON_SYSTEM,"Could Not parse Config file!");
            return 0;
        }

        return 0;
    };

    PUBLIC_ATTRIBUTE s32 plugin_unload(s32 argc, const char* argv[]) {
        LOG(PYRITE,LogVerbosity::Log,"<%s\\Ver.0x%08x> %s\n", PLUGIN_NAME, PLUGIN_VER, __func__);
        LOG(PYRITE,LogVerbosity::Log,"%s Plugin Ended.\n", PLUGIN_NAME);
        return 0;
    }


    WEAK_ATTRIBUTE s32 module_start(s64 argc, const void *args) {
        return 0;
    }


    WEAK_ATTRIBUTE s32 module_stop(s64 argc, const void *args) {
        return 0;
    }

}

