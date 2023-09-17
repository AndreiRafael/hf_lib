#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/hf_transform.h"

void print_mat2f(const char* msg, HF_Mat2f mat) {
    printf("%s:\n", msg);
    for(int y = 0; y < 2; y++) {
        for(int x = 0; x < 2; x++) {
            printf("[%.2f]", mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_mat3f(const char* msg, HF_Mat3f mat) {
    printf("%s:\n", msg);
    for(int y = 0; y < 3; y++) {
        for(int x = 0; x < 3; x++) {
            printf("[%.2f]", mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_mat4f(const char* msg, HF_Mat4f mat) {
    printf("%s:\n", msg);
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            printf("[%.2f]", mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_vec3(const char* msg, HF_Vec3f vec) {
    printf("%s:\n", msg);
    printf("{ %.2f %.2f %.2f }\n", vec[0], vec[1], vec[2]);
}

int main(int argc, char** argv) {
    {
        HF_Mat4f pos;
        hf_transform_translation((HF_Vec3f){ 1.f, 2.f, 3.f }, pos);
        print_mat4f("original", pos);

        HF_Mat4f res, op;

        hf_transform_rotation((HF_Vec3f){ 0.f, 1.f, 0.f }, 3.1415f / 2.f, op);
        hf_mat4f_multiply_mat4f(pos, op, res);

        print_mat4f("rotate around arbitrary", res);

        hf_transform_rotation_x(3.1415f / 2.f, op);
        hf_mat4f_multiply_mat4f(pos, op, res);
        print_mat4f("rotate around x", res);

        hf_transform_rotation_y(3.1415f / 2.f, op);
        hf_mat4f_multiply_mat4f(pos, op, res);
        print_mat4f("rotate around y", res);

        hf_transform_rotation_z(3.1415f / 2.f, op);
        hf_mat4f_multiply_mat4f(pos, op, res);
        print_mat4f("rotate around z", res);
    }

    {//determinant test
        HF_Mat4f mat4 = {
            0, 5, 1, 3,
            2, 5, 2, 2,
            3, 7, 3, 1,
            4, -1, 4, 8,
        };
        printf("determinant(-48): %.2f\n\n", hf_mat4f_determinant(mat4));

        hf_mat4f_identity(mat4);
        printf("determinant(1): %.2f\n\n", hf_mat4f_determinant(mat4));

        HF_Mat3f mat3 = {
            0, 2, 1,
            0, -1, 1,
            1, 3, 4,
        };
        printf("determinant(3): %.2f\n\n", hf_mat3f_determinant(mat3));

        hf_mat3f_identity(mat3);
        printf("determinant(1): %.2f\n\n", hf_mat3f_determinant(mat3));
    }

    {//inverse test
        HF_Mat2f mat2 = { 1, 3, 2, 4 };

        HF_Mat2f res2;
        hf_mat2f_inverse(mat2, res2);
        print_mat2f("mat2 inverse(-2 1 1.5 0.5): ", res2);

        hf_mat2f_multiply_mat2f(mat2, res2, res2);
        print_mat2f("mat2 x inv: ", res2);

        HF_Mat3f mat3 = { 1, 4, 7, 2, 5, 8, 3, 6, -1 };

        HF_Mat3f res3;
        hf_mat3f_inverse(mat3, res3);
        print_mat3f("mat3 inverse(-1.76 0.86 -0.1 1.53 -0.73 0.2 -0.1 0.2 -0.1): ", res3);

        hf_mat3f_multiply_mat3f(mat3, res3, res3);
        print_mat3f("mat3 x inv: ", res3);

        HF_Mat4f mat4 = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            10, 20, 30, 1,
        };

        HF_Mat4f res4;
        hf_mat4f_inverse(mat4, res4);
        print_mat4f("mat4 inverse(-10 -20 -30): ", res4);

        hf_mat4f_multiply_mat4f(mat4, res4, res4);
        print_mat4f("mat4 x inv: ", res4);
    }

    {//test transform vector
        HF_Vec3f vec = { 10.f, 20.f, 30.f };
        HF_Vec3f res;
        HF_Mat4f mat;

        print_vec3("original vector", vec);

        hf_transform_rotation_x(3.1415f / 2.f, mat);
        hf_transform_apply(vec, mat, res);
        print_vec3("90 x", res);

        hf_transform_rotation_y(3.1415f / 2.f, mat);
        hf_transform_apply(vec, mat, res);
        print_vec3("90 y", res);

        hf_transform_rotation_z(3.1415f / 2.f, mat);
        hf_transform_apply(vec, mat, res);
        print_vec3("90 z", res);
    }

    return 0;
}