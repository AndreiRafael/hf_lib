#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/hf_transform.h"

void print_mat4f(HF_Mat4f mat) {
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            printf("[%.2f]", mat.values[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char** argv) {
    print_mat4f(hf_transform_translation((HF_Vec3f){ 1.f, 2.f, 3.f }));
    print_mat4f(
        hf_mat4f_multiply_mat4f(
            hf_mat4f_multiply_mat4f(hf_transform_translation((HF_Vec3f){ 2.f, 0.f, 0.f }), hf_transform_scale((HF_Vec3f){ 2.f, 2.f, 2.f })),
            hf_transform_rotation((HF_Vec3f){ 0.f, 0.f, 1.f }, 3.1415f / 2.f)
        )
    );

    return 0;
}