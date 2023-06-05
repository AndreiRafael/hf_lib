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

size_t hf_string_length_codepoints(const char* string) {
    size_t len = 0;
    while(*string) {
        if((*(string++) & 192) == 192) {//
            do {
                string++;
            } while((*string & 192) == 128);
        }

        len++;
    }
    return len;
}

bool hf_string_copy(const char* string, char* buffer, size_t buffer_size) {
    if(buffer_size == 0) {
        return false;
    }

    size_t index = 0;
    while(index < (buffer_size - 1) && *string) {
        buffer[index++] = *string;
        string++;
    }
    bool retval = !(*string);
    while((*string & 192) == 128) {//push index back to start of codepoint if applicable
        string--;
        index--;
    }
    buffer[index] = '\0';
    return retval;
}

bool hf_string_concat(const char* string, char* buffer, size_t buffer_size) {
    size_t new_len = buffer_size;
    while(*buffer && new_len > 0) {
        buffer++;
        new_len--;
    }
    return hf_string_copy(string, buffer, new_len);
}
