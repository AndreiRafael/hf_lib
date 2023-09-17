#include "../include/hf_transform.h"

#include <string.h>
#include <math.h>

void hf_transform_translation(HF_Vec3f vec, HF_Mat4f out) {
    hf_mat4f_identity(out);
    out[3][0] = vec[0];
    out[3][1] = vec[1];
    out[3][2] = vec[2];
}

void hf_transform_rotation(HF_Vec3f vec, float rad, HF_Mat4f out) {
    hf_transform_rotation_cached(vec, sinf(rad), cosf(rad), out);
}

void hf_transform_rotation_cached(HF_Vec3f vec, float sin_rad, float cos_rad, HF_Mat4f out) {
    float one_minus_cos = 1.f - cos_rad;

    hf_mat4f_identity(out);
    out[0][0] = cos_rad + vec[0] * vec[0] * one_minus_cos;
    out[1][0] = vec[0] * vec[1] * one_minus_cos - vec[2] * sin_rad;
    out[2][0] = vec[0] * vec[2] * one_minus_cos + vec[1] * sin_rad;

    out[0][1] = vec[0] * vec[1] * one_minus_cos + vec[2] * sin_rad;
    out[1][1] = cos_rad + vec[1] * vec[1] * one_minus_cos;
    out[2][1] = vec[1] * vec[2] * one_minus_cos - vec[0] * sin_rad;

    out[0][2] = vec[0] * vec[2] * one_minus_cos - vec[1] * sin_rad;
    out[1][2] = vec[1] * vec[2] * one_minus_cos + vec[0] * sin_rad;
    out[2][2] = cos_rad + vec[2] * vec[2] * one_minus_cos;
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
    out[0][0] = vec[0];
    out[1][1] = vec[1];
    out[2][2] = vec[2];
}

void hf_transform_apply(HF_Vec3f vec, HF_Mat4f mat, HF_Vec3f out) {
    HF_Mat4f tmp;
    hf_mat4f_identity(tmp);
    memcpy(&tmp[3][0], vec, sizeof(vec[0]) * 3);
    hf_mat4f_multiply_mat4f(tmp, mat, tmp);
    memcpy(out, &tmp[3][0], sizeof(vec[0]) * 3);
}
