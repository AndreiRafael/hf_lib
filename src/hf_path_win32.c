#include <windows.h>

static const char preferred_separator = '\\';

bool hf_path_is_directory(const char* path) {
    DWORD file_type = GetFileAttributesA(path);
    if (file_type == INVALID_FILE_ATTRIBUTES)
        return false;  //something is wrong with your path!

    if (file_type & FILE_ATTRIBUTE_DIRECTORY)
        return true;   // this is a directory!

    return false;    // this is not a directory!
}
