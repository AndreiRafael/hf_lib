#include "../include/hf_memory.h"

void hf_memory_arena_init(HF_MemoryArena* arena, void* memory, size_t size) {
    *arena = (HF_MemoryArena) {
        .size = size,
        .available_size = size,
        .memory_start = memory,
    };
}

void hf_memory_arena_deinit(HF_MemoryArena* arena) {
    *arena = (HF_MemoryArena){
        .size = 0,
        .available_size = 0,
        .memory_start = NULL,
    };
}

void* hf_memory_arena_get(HF_MemoryArena* arena, size_t size) {
    if(arena->available_size < size) {
        return NULL;
    }
    void* mem = ((char*)arena->memory_start) + (arena->size - arena->available_size);
    arena->available_size -= size;
    return mem;
}

void hf_memory_arena_reset(HF_MemoryArena* arena) {
    arena->available_size = arena->size;
}
