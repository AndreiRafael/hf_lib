#include "../include/hf_path.h"

char preferred_separator(void);

bool hf_path_normalize(char* path) {
    char separator = preferred_separator();

    return true;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
    #include "hf_path_win32.c"
#elif defined(UNIX) || defined(_UNIX) || defined(__UNIX) || defined(__UNIX__)
    #include "hf_path_unix.c"
#else
    #error "Unknown System"
#endif
