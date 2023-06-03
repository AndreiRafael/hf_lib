#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
    #include "hf_path_win32.c"
#elif defined (UNIX)
    #include "hf_path_unix.c"
#else
    #error "Unknown System"
#endif
