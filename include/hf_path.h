//Functions for handling file paths
//Dependencies:
//- stdbool.h
//- stddef.h
//- hf_string.h

#ifndef HF_PATH_H
#define HF_PATH_H

#define HF_PATH_MAX_PATH_LENGTH 260

#include <stdbool.h>
#include <stddef.h>

bool hf_path_equal(const char* left_path, const char* right_path);

bool hf_path_normalize(const char* path, char* buffer, size_t buffer_size);
bool hf_path_parent(const char* path, char* buffer, size_t buffer_size);

#endif//HF_PATH_H
