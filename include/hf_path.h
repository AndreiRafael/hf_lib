#ifndef HF_PATH_H
#define HF_PATH_H

#include <stdbool.h>

bool hf_path_normalize(char* path);
bool hf_path_is_directory(const char* path);

#endif//HF_PATH_H
