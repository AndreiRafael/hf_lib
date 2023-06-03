#include "../include/hf_path.h"

#define WIN32

#if defined(WIN32)
    #include "hf_path_win32.c"
#elif defined (UNIX)
    #include "hf_path_unix.c"
#else
    #error "Unknown System"
#endif