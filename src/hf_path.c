#include "../include/hf_path.h"
#include "../include/hf_string.h"

#define HF_PATH_MAX_PATH_LENGHT_PLUS_ONE (HF_PATH_MAX_PATH_LENGTH + 1)

char preferred_separator(void);

static bool hf_path_internal_is_separator(const char c) {
    return c == '/' || c == '\\';
}

// TODO: return error code instead of true/false !!!
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

//provided path must be normalized!!
static bool hf_path_internal_delete_token(char* path) {
    char* itr = path;
    while(*itr) {//get to end of string
        itr++;
    }

    //go back until a separator or start of path
    while(itr != path && !hf_path_internal_is_separator(*itr)) {
        itr--;
    }

    *itr = '\0';
    return itr != path;
}

bool hf_path_equal(const char* left_path, const char* right_path) {
    char buffer_left[HF_PATH_MAX_PATH_LENGHT_PLUS_ONE];
    char buffer_right[HF_PATH_MAX_PATH_LENGHT_PLUS_ONE];

    return
        hf_path_normalize(left_path, buffer_left, HF_PATH_MAX_PATH_LENGHT_PLUS_ONE) &&
        hf_path_normalize(right_path, buffer_right, HF_PATH_MAX_PATH_LENGHT_PLUS_ONE) &&
        hf_string_equal(buffer_left, buffer_right);
    ;
}

typedef enum ETokenType_e {
    ETOKENTYPE_THIS,
    ETOKENTYPE_PARENT,
    ETOKENTYPE_ROOT,
    ETOKENTYPE_OTHER,
} ETokenType;

static ETokenType hf_path_internal_token_type(const char* token) {
    if(hf_string_equal(token, "..")) {
        return ETOKENTYPE_PARENT;
    }
    if(hf_string_equal(token, ".")) {
        return ETOKENTYPE_THIS;
    }
    return ETOKENTYPE_OTHER;
}

bool hf_path_normalize(const char* path, char* buffer, size_t buffer_size) {
    if(buffer_size == 0) {
        return false;
    }
    buffer[0] = '\0';

    char separator_str[2];
    separator_str[0] = preferred_separator();
    separator_str[1] = '\0';

    int depth = 0;

    char token_buffer[HF_PATH_MAX_PATH_LENGHT_PLUS_ONE];
    while(hf_path_internal_read_token(token_buffer, HF_PATH_MAX_PATH_LENGHT_PLUS_ONE, &path)) {
        ETokenType type = hf_path_internal_token_type(token_buffer);

        if(type == ETOKENTYPE_PARENT && depth > 0) {
            hf_path_internal_delete_token(buffer);
            depth--;
        }
        else if(type != ETOKENTYPE_THIS || buffer[0] == '\0') {
            if(type == ETOKENTYPE_PARENT && hf_path_internal_token_type(buffer) == ETOKENTYPE_THIS) {// . become irrelevant
                buffer[0] = '\0';
            }

            if(buffer[0] != '\0') {//put separator before new token
                hf_string_concat(separator_str, buffer, buffer_size);
            }
            hf_string_concat(token_buffer, buffer, buffer_size);

            if(type == ETOKENTYPE_PARENT) {
                depth--;
            }
            else if(type != ETOKENTYPE_THIS) {
                depth++;
            }
        }
    }

    return !(*path);
}

bool hf_path_parent(const char* path, char* buffer, size_t buffer_size) {
    char normalized_buffer[HF_PATH_MAX_PATH_LENGHT_PLUS_ONE];
    if(
        hf_path_normalize(path, normalized_buffer, HF_PATH_MAX_PATH_LENGHT_PLUS_ONE) &&
        hf_path_internal_delete_token(normalized_buffer)
    ) {
        return hf_string_copy(normalized_buffer, buffer, buffer_size);
    }

    return false;
}

//platform specific implementations handled in respective separate files
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
    #include "hf_path_win32.c"
#elif defined(UNIX) || defined(_UNIX) || defined(__UNIX) || defined(__UNIX__)
    #include "hf_path_unix.c"
#else
    #error "Unknown System"
#endif
