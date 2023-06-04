#ifndef HF_PATH_H
#define HF_PATH_H

#include <stdbool.h>
#include <stddef.h>

bool hf_path_normalize(char* buffer, size_t buffer_size, const char* path);
bool hf_path_exists(const char* path);

bool hf_path_is_directory(const char* path);

#endif//HF_PATH_H
