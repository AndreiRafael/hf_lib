#include "../include/hf_path.h"

char preferred_separator(void);

bool hf_path_normalize(char* buffer, size_t buffer_size, const char* path) {
    char separator = preferred_separator();
    (void)separator;// TODO:
    (void)buffer;

    size_t index = 0;
    while(index < (buffer_size - 1) && *path) {
        switch(*path) {
            case '.': // TODO:

                break;
            default:
                break;
        }
    }

    return !(*path);
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
    #include "hf_path_win32.c"
#elif defined(UNIX) || defined(_UNIX) || defined(__UNIX) || defined(__UNIX__)
    #include "hf_path_unix.c"
#else
    #error "Unknown System"
#endif
