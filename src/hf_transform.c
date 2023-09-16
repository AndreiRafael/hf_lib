#include "../include/hf_transform.h"

#include <math.h>

void hf_transform_translation(HF_Vec3f vec, HF_Mat4f out) {
    hf_mat4f_identity(out);
    out[3][0] = vec.x;
    out[3][1] = vec.y;
    out[3][2] = vec.z;
}

void hf_transform_rotation(HF_Vec3f vec, float rad, HF_Mat4f out) {
    hf_transform_rotation_cached(vec, sinf(rad), cosf(rad), out);
}

void hf_transform_rotation_cached(HF_Vec3f vec, float sin_rad, float cos_rad, HF_Mat4f out) {
    float one_minus_cos = 1.f - cos_rad;

    hf_mat4f_identity(out);
    out[0][0] = cos_rad + vec.x * vec.x * one_minus_cos;
    out[1][0] = vec.x * vec.y * one_minus_cos - vec.z * sin_rad;
    out[2][0] = vec.x * vec.z * one_minus_cos + vec.y * sin_rad;

    out[0][1] = vec.x * vec.y * one_minus_cos + vec.z * sin_rad;
    out[1][1] = cos_rad + vec.y * vec.y * one_minus_cos;
    out[2][1] = vec.y * vec.z * one_minus_cos - vec.x * sin_rad;

    out[0][2] = vec.x * vec.z * one_minus_cos - vec.y * sin_rad;
    out[1][2] = vec.y * vec.z * one_minus_cos + vec.x * sin_rad;
    out[2][2] = cos_rad + vec.z * vec.z * one_minus_cos;
}

void hf_transform_rotation_x(float rad, HF_Mat4f out) {
    hf_transform_rotation_x_cached(sinf(rad), cosf(rad), out);
}

void hf_transform_rotation_x_cached(float sin_rad, float cos_rad, HF_Mat4f out) {
    hf_mat4f_identity(out);

    out[1][1] = cos_rad;
    out[2][1] = -sin_rad;

    out[1][2] = sin_rad;
    out[2][2] = cos_rad;
}

void hf_transform_rotation_y(float rad, HF_Mat4f out) {
    hf_transform_rotation_y_cached(sinf(rad), cosf(rad), out);
}

void hf_transform_rotation_y_cached(float sin_rad, float cos_rad, HF_Mat4f out) {
    hf_mat4f_identity(out);

    out[0][0] = cos_rad;
    out[2][0] = sin_rad;

    out[0][2] = -sin_rad;
    out[2][2] = cos_rad;
}

void hf_transform_rotation_z(float rad, HF_Mat4f out) {
    hf_transform_rotation_z_cached(sinf(rad), cosf(rad), out);
}

void hf_transform_rotation_z_cached(float sin_rad, float cos_rad, HF_Mat4f out) {
    hf_mat4f_identity(out);

    out[0][0] = cos_rad;
    out[1][0] = -sin_rad;

    out[0][1] = sin_rad;
    out[1][1] = cos_rad;
}

void hf_transform_scale(HF_Vec3f vec, HF_Mat4f out) {
    hf_mat4f_identity(out);
    out[0][0] = vec.x;
    out[1][1] = vec.y;
    out[2][2] = vec.z;
}
