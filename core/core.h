// Pyrite
// core.h

/*
    This File Contains all the stuff needed to make life easier when using pyrite
    PUBLIC_ATTRIBUTE is used on functions such as plugin load and unload and need to be used there or else
    goldhen cant find those and run those
*/

#include <Common.h>

//  shut up intellisense 
#ifdef __INTELLISENSE__
    #define __attribute__(x)
    typedef char* va_list;

    #define va_start(ap, last) ((void)0)
    #define va_end(ap)         ((void)0)

    #define va_arg(ap, type)   (*(type*)0)
#endif

// Shorthand names
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;
typedef float    f32;
typedef double   f64;
typedef char* string;


#define PUBLIC_ATTRIBUTE __attribute__((visibility("default")))
#define WEAK_ATTRIBUTE   __attribute__((weak, visibility("hidden")))

