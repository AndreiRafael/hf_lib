#ifndef HF_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct hf_buffer_s {
    void* data;
    size_t length;
    size_t capacity;
} hf_buffer;

void hf_buffer_init(hf_buffer* buffer, void* data, size_t capacity);
bool hf_buffer_push(hf_buffer* buffer, void* data, size_t size);

#endif//HF_BUFFER_H
