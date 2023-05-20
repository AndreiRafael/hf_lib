#include "../include/hf_algorithm.h"

#include <string.h>

#define HF_UNIQUENAME_C(name, line) unique##_##line##_##name
#define HF_UNIQUENAME_B(name, line) HF_UNIQUENAME_C(name, line)
#define HF_UNIQUENAME(name) HF_UNIQUENAME_B(name, __LINE__)

#define HF_BITSWAP(a, b, size)\
do {\
    size_t HF_UNIQUENAME(i) = 0;\
    char* HF_UNIQUENAME(ca) = a;\
    char* HF_UNIQUENAME(cb) = b;\
    while (HF_UNIQUENAME(i) < size) {\
        char tmp = *HF_UNIQUENAME(ca);\
        *HF_UNIQUENAME(ca) = *HF_UNIQUENAME(cb);\
        *HF_UNIQUENAME(cb) = tmp;\
        HF_UNIQUENAME(ca)++;\
        HF_UNIQUENAME(cb)++;\
        HF_UNIQUENAME(i)++;\
    }\
} while(0)\

void hf_sort_bubble(void* items, size_t item_count, size_t item_size, int(*compare)(const void*, const void*)) {
    for(size_t i = 0; i < item_count - 1; i++) {
        for(size_t j = 0; j < item_count - i - 1; j++) {
            void* a = (((char*)items) + item_size * j);
            void* b = (((char*)items) + item_size * (j + 1));
            if(compare(a, b) > 0) {
                HF_BITSWAP(a, b, item_size);
            }
        }
    }
}

void hf_sort_with_context_bubble(void* items, size_t item_count, size_t item_size, int(*compare)(const void* a, const void* b, const void* context), void* context) {
    for(size_t i = 0; i < item_count - 1; i++) {
        for(size_t j = 0; j < item_count - i - 1; j++) {
            void* a = (((char*)items) + item_size * j);
            void* b = (((char*)items) + item_size * (j + 1));
            if(compare(a, b, context) > 0) {
                HF_BITSWAP(a, b, item_size);
            }
        }
    }
}

void hf_query_select(void* src, void* dest, size_t src_item_size, size_t dest_item_size, size_t item_count, void(*expression)(void* src, void* dest)) {
    for(size_t i = 0; i < item_count; i++) {
        void* src_item = ((char*)src) + (src_item_size * i);
        void* dest_item = ((char*)dest) + (dest_item_size * i);
        expression(src_item, dest_item);
    }
}

void hf_query_where(void* src, void* dest, size_t item_size, size_t item_count, size_t* new_item_count, bool(*predicate)(void* value)) {
    size_t dest_index = 0;
    for(size_t i = 0; i < item_count; i ++) {
        void* src_item = ((char*)src) + (item_size * i);
        if(predicate(src_item)) {
            void* dest_item = ((char*)dest) + (item_size * dest_index);
            memcpy(dest_item, src_item, item_size);
            dest_index++;
        }
    }
    if(new_item_count) {
        *new_item_count = dest_index;
    }
}
