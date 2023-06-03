#include "../include/hf_string.h"

bool hf_string_equal(const char* left, const char* right) {
    while(*left && *right) {
        if(*left != *right) {
            return false;
        }
        left++;
        right++;
    }
    return *left == *right;
}

size_t hf_string_length_bytes(const char* string) {
    size_t len = 0;
    while(*string) {
        string++;
        len++;
    }
    return len;
}

bool hf_string_copy(char* buffer, size_t buffer_len, const char* string) {
    if(buffer_len == 0) {
        return false;
    }

    size_t index = 0;
    while(index < (buffer_len - 1) && *string) {
        buffer[index++] = *string;
        string++;
    }
    while((*string & 192) == 128) {//push index back to start of codepoint if applicable
        string--;
        index--;
    }
    buffer[index] = '\0';
    return index < (buffer_len - 1);
}

bool hf_string_concat(char* buffer, size_t buffer_len, const char* string) {
    size_t new_len = buffer_len;
    while(*buffer && new_len > 0) {
        buffer++;
        new_len--;
    }
    return hf_string_copy(buffer, new_len, string);
}
