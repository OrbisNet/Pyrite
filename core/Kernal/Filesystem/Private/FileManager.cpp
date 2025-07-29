#include "Kernal/Filesystem/Public/FileManager.h"
#include "Logging/Public/Log.h"
#include "core.h"
#include "orbis/libkernel.h"

#define DEBUG 1

bool FileManager::createFile(string path) {
    s32 file = sceKernelOpen(path, FM_CREATE | FM_READWRITE ,770);

    if (file < 0) {

        LOG(LogFilesystem,LogVerbosity::Log,"Couldnt Create File!: %s", path);

        sceKernelClose(file);
        return false;
    }
    sceKernelClose(file);
    return true;
}

bool FileManager::deleteFile(string path) {
    s32 file = sceKernelUnlink(path);

    if (file < 0) {

        LOG(LogFilesystem,LogVerbosity::Log,"Couldn't remove file!: %s", path);

        sceKernelClose(file);
        return false;
    }
    sceKernelClose(file);
    return true;
}

bool FileManager::fileExists(string path) {
    OrbisKernelStat stat;

    LOG(LogFilesystem,LogVerbosity::Log,"Checking if File exists");

    s32 file = sceKernelStat(path, &stat);

    if (file < 0) {

        LOG(LogFilesystem,LogVerbosity::Log,"Couldn't determ File Existance: %s", path);

        sceKernelClose(file);
        return false;
    }
    sceKernelClose(file);
    return true;
}

string FileManager::readfile(string path) {

    if (FileManager::fileExists(path)) {

        s32 file = sceKernelOpen(path, FM_READONLY ,770);
        u64 filesize;
        string filedata ;

        filesize = sceKernelLseek(file,0,SEEK_END);

        if (filesize < 0) {

            LOG(LogFilesystem,LogVerbosity::Log,"File is Empty!: %s", path);

            sceKernelClose(file);
            return nullptr;
        }

        filedata = (string)malloc(filesize); // this bout to mem leak I already know that

        s32 results;
        results = sceKernelRead(file,filedata ,filesize);

        if (results < 0 ) {


            LOG(LogFilesystem,LogVerbosity::Log,"Failed to read file: %s", path);

            sceKernelClose(file);
            return nullptr;
        }
        sceKernelClose(file);

        return filedata;

    };
    LOG(LogFilesystem,LogVerbosity::Log,"invalid File");
    return nullptr;
}

bool FileManager::writefile(string path,string content) {
    if (FileManager::fileExists(path)) {
        s32 file = sceKernelOpen(path, FM_WRITEONLY ,770);


        s32 result;

        result = sceKernelWrite(file,content,sizeof(content));

        if (result < 0) {

            LOG(LogFilesystem,LogVerbosity::Log,"Couldn't Write to file!");
            sceKernelClose(file);
            return false;
        }
        sceKernelClose(file);
        return true;

    }
    return false;
}



bool FileManager::createDir(string path) {
    s32 dir;
    OrbisKernelStat stat;

    dir = sceKernelStat(path, &stat) ;

    if (dir != 0) {
        s32 dir = sceKernelMkdir(path,770);

        if (dir < 0) {
            return false;
        }
    }

    return true;
}

string FileManager::makePath(string first, ...) {
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

