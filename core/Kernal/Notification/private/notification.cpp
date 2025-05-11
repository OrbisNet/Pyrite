#include <Common.h>
#include <string.h>
#include "Kernal/Notification/public/notification.h"

// Thanks to OSM he the goat
// https://github.com/OSM-Made/PS4-Notify/blob/main/Notify.cpp

void SendNotification(char* IconUri,char* MSG, ...) {
    OrbisNotificationRequest Buffer;

    va_list args;
    va_start(args, MSG);
    vsprintf(Buffer.message, MSG, args);
    va_end(args);

    Buffer.type = OrbisNotificationRequestType::NotificationRequest;
    Buffer.unk3 = 0; 
    Buffer.useIconImageUri = 1; 
    Buffer.targetId = -1;
    strcpy(Buffer.iconUri, IconUri); 

    sceKernelSendNotificationRequest(0, &Buffer, 3120, 0);
}

