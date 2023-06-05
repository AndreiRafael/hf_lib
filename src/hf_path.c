#include "../include/hf_path.h"
#include "../include/hf_string.h"

char preferred_separator(void);

static bool hf_path_internal_is_separator(const char c) {
    return c == '/' || c == '\\';
}

//read one token of the path, return true if a token was read. if the end is reached, false is returned and **path_itr should be '\0'
//other false returns mean errors
static bool hf_path_internal_read_token(char* buffer, size_t buffer_size, const char** path_itr) {
    size_t index = 0;
    const char* itr = *path_itr;
    while(*itr) {
        if(hf_path_internal_is_separator(*itr)) {
            if(index > 0) {
                break;
            }
        }
        else {
            if(index >= (buffer_size - 1)) {
                return false;
            }
            buffer[index++] = *itr;
        }
        itr++;
    }

    if(index < buffer_size) {
        buffer[index] = '\0';
    }
    else {
        return false;// TODO: this could falsely indicate end of path??
    }

    *path_itr = itr;// TODO: this could falsely indicate end of path??
    return index > 0;
}

bool hf_path_normalized(const char* path, char* buffer, size_t buffer_size) {
    if(buffer_size == 0) {
        return false;
    }
    buffer[0] = '\0';

    char separator_str[2];
    separator_str[0] = preferred_separator();
    separator_str[1] = '\0';

    char token_buffer[261];
    while(hf_path_internal_read_token(token_buffer, 261, &path)) {
        hf_string_concat(token_buffer, buffer, buffer_size);
        if(hf_string_length_bytes(buffer) > 0) {
            hf_string_concat(separator_str, buffer, buffer_size);
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
