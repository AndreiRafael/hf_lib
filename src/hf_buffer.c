#include "../include/hf_buffer.h"
#include "../include/hf_string.h"

void hf_buffer_init(hf_buffer* buffer, void* data, size_t capacity) {
    buffer->data = data;
    buffer->length = 0;
    buffer->capacity = capacity;
}

bool hf_buffer_push(hf_buffer* buffer, void* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (buffer->length >= buffer->capacity) {
            return false;
        }

        ((char*)buffer->data)[buffer->length++] = ((char*)data)[i];
    }
    return true;
}
