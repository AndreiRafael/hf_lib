#ifndef HF_MEMORY_H
#define HF_MEMORY_H

#include <stddef.h>

typedef struct HF_MemoryArena_s {
    size_t size;
    size_t available_size;
    void* memory_start;
} HF_MemoryArena;

void hf_memory_arena_init(HF_MemoryArena* arena, void* memory, size_t size);
void hf_memory_arena_deinit(HF_MemoryArena* arena);

void* hf_memory_arena_get(HF_MemoryArena* arena, size_t size);
void hf_memory_arena_reset(HF_MemoryArena* arena);

#endif//HF_MEMORY_H
