//Functions for handling file paths
//Dependencies:
//- stdbool.h
//- stddef.h
//- hf_string.h

#ifndef HF_PATH_H
#define HF_PATH_H

#define HF_PATH_MAX_PATH_LENGTH 512

#include <stdbool.h>
#include <stddef.h>

//returns true if the paths resolve to the same when normalized
//returns false otherwise or if any of the paths could not be normalized
bool hf_path_equal(const char* left_path, const char* right_path);

//normalizes a path, removing redundancies or extra separators, saving the results into the provided buffer
//returns false if normalized value could not fit buffer
bool hf_path_normalize(const char* path, char* buffer, size_t buffer_size);
//gets the parent of the provided path, saving it into the provided buffer
//returns false if value could not fit buffer
bool hf_path_parent(const char* path, char* buffer, size_t buffer_size);
bool hf_path_extension(const char* path, char* buffer, size_t buffer_size);

#endif//HF_PATH_H
