#ifndef HF_STRING_H
#define HF_STRING_H

//Functions for handling null terminated utf-8 strings using bounds checking by default

#include <stdbool.h>
#include <stddef.h>

//Returns true if contents of left are exactly the same as the contents of right.
bool hf_string_equal(const char* left, const char* right);

//Returns the lenght in bytes of a utf-8 null terminated string.
size_t hf_string_length_bytes(const char* string);

//Returns the lenght in unicode codepoints of a utf-8 null terminated string.
size_t hf_string_length_codepoints(const char* string);

//Copies contents of null terminated string into buffer and null terminates the buffer.
//Returns false if string couldn't fit into the buffer, in which case the value in the buffer will be truncated and null terminated.
bool hf_string_copy(char* buffer, size_t buffer_len, const char* string);

//Appends null terminated string to the end of null terminated buffer and null terminates the buffer.
//Returns false if string couldn't fit into the buffer, in which case the value in the buffer will be truncated and null terminated.
bool hf_string_concat(char* buffer, size_t buffer_len, const char* string);

#endif//HF_STRING_H
