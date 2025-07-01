#include "core.h"

#define FM_READONLY 0x0000
#define FM_WRITEONLY 0x0001
#define FM_READWRITE 0x0002

#define FM_CREATE 0x0200

#define GOLDHENDIR "/data/GoldHEN"

class FileManager {
public:
    static bool createFile(string path);
    static bool deleteFile(string path);
    static bool fileExists(string path);

    static string readfile(string path);
    static bool writefile(string path,string content);

    static bool createDir(string path);

    static string makePath(string first,...);
};