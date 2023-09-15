#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/hf_transform.h"

void print_mat4f(const char* msg, HF_Mat4f mat) {
    printf("%s:\n", msg);
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            printf("[%.2f]", mat.values[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_vec3(const char* msg, HF_Vec3f vec) {
    printf("%s:\n", msg);
    printf("{ %.2f, %.2f, %.2f }\n\n", vec.x, vec.y, vec.z);
}

int main(int argc, char** argv) {
    HF_Mat4f pos = hf_transform_translation((HF_Vec3f){ 1.f, 2.f, 3.f });
    print_mat4f("original", pos);

    print_mat4f(
        "rotate around arbitrary",
        hf_mat4f_multiply_mat4f(
            pos,
            hf_transform_rotation((HF_Vec3f){ 0.f, 1.f, 0.f }, 3.1415f / 2.f)
        )
    );

    print_mat4f(
        "rotate around x",
        hf_mat4f_multiply_mat4f(
            pos,
            hf_transform_rotation_x(3.1415f / 2.f)
        )
    );

    print_mat4f(
        "rotate around y",
        hf_mat4f_multiply_mat4f(
            pos,
            hf_transform_rotation_y(3.1415f / 2.f)
        )
    );

    print_mat4f(
        "rotate around z",
        hf_mat4f_multiply_mat4f(
            pos,
            hf_transform_rotation_z(3.1415f / 2.f)
        )
    );

    print_vec3(
        "applied rotation",
        hf_transform_apply((HF_Vec3f) { 10.f, 20.f, 30.f }, hf_transform_rotation_y(3.1415f))
    );

    return 0;
}