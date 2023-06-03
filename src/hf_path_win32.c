#include "../include/hf_path.h"
#include <windows.h>

static const char preferred_separator = '\\';

bool hf_path_exists(const char* path) {
    DWORD file_type = GetFileAttributesA(path);
    if(file_type & INVALID_FILE_ATTRIBUTES ){
        return !(GetLastError() & (
            ERROR_PATH_NOT_FOUND |
            ERROR_FILE_NOT_FOUND |
            ERROR_INVALID_NAME |
            ERROR_BAD_NETPATH
        ));
    }
    return true;
}

bool hf_path_is_directory(const char* path) {
    DWORD file_type = GetFileAttributesA(path);
    if (file_type == INVALID_FILE_ATTRIBUTES) {
        return false;
    }

    return (file_type & FILE_ATTRIBUTE_DIRECTORY);
}
