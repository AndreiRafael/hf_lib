#ifndef HF_PATH_H
#define HF_PATH_H

#include <stdbool.h>
#include <stddef.h>

bool hf_path_normalized(const char* path, char* buffer, size_t buffer_size);
bool hf_path_exists(const char* path);

bool hf_path_is_directory(const char* path);

#endif//HF_PATH_H
