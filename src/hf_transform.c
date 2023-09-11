#include "../include/hf_transform.h"

#include <math.h>

HF_Mat4f hf_transform_translation(HF_Vec3f vec) {
    HF_Mat4f out = hf_mat4f_identity();
    out.values[3][0] = vec.x;
    out.values[3][1] = vec.y;
    out.values[3][2] = vec.z;
    return out;
}

HF_Mat4f hf_transform_rotation(HF_Vec3f vec, float rad) {
    return hf_transform_rotation_cached(vec, sinf(rad), cosf(rad));
}

HF_Mat4f hf_transform_rotation_cached(HF_Vec3f vec, float sin_rad, float cos_rad) {
    float one_minus_cos = 1.f - cos_rad;

    HF_Mat4f out = hf_mat4f_identity();
    out.values[0][0] = cos_rad + vec.x * vec.x * one_minus_cos;
    out.values[1][0] = vec.x * vec.y * one_minus_cos - vec.z * sin_rad;
    out.values[2][0] = vec.x * vec.z * one_minus_cos + vec.y * sin_rad;

    out.values[0][1] = vec.x * vec.y * one_minus_cos + vec.z * sin_rad;
    out.values[1][1] = cos_rad + vec.y * vec.y * one_minus_cos;
    out.values[2][1] = vec.y * vec.z * one_minus_cos - vec.x * sin_rad;

    out.values[0][2] = vec.x * vec.z * one_minus_cos - vec.y * sin_rad;
    out.values[1][2] = vec.y * vec.z * one_minus_cos + vec.x * sin_rad;
    out.values[2][2] = cos_rad + vec.z * vec.z * one_minus_cos;
    return out;
}

HF_Mat4f hf_transform_scale(HF_Vec3f vec) {
    HF_Mat4f out = hf_mat4f_identity();
    out.values[0][0] = vec.x;
    out.values[1][1] = vec.y;
    out.values[2][2] = vec.z;
    return out;
}
