#ifndef HF_TRANSFORM_H
#define HF_TRANSFORM_H

#include "hf_vec.h"
#include "hf_mat.h"

HF_Mat4f hf_transform_translation(HF_Vec3f vec);//create a translation matrix

HF_Mat4f hf_transform_rotation(HF_Vec3f vec, float rad);//create a rotation matrix on an arbitrary axis
HF_Mat4f hf_transform_rotation_cached(HF_Vec3f vec, float sin_rad, float cos_rad);//create a rotation matrix on an arbitrary axis using pre-calculated sine and cosine
HF_Mat4f hf_transform_rotation_x(float rad);//create a rotation matrix on the x axis
HF_Mat4f hf_transform_rotation_x_cached(float sin_rad, float cos_rad);//create a rotation matrix on the x axis using pre-calculated sine and cosine
HF_Mat4f hf_transform_rotation_y(float rad);//create a rotation matrix on the y axis
HF_Mat4f hf_transform_rotation_y_cached(float sin_rad, float cos_rad);//create a rotation matrix on the y axis using pre-calculated sine and cosine
HF_Mat4f hf_transform_rotation_z(float rad);//create a rotation matrix on the z axis
HF_Mat4f hf_transform_rotation_z_cached(float sin_rad, float cos_rad);//create a rotation matrix on the z axis using pre-calculated sine and cosine

HF_Mat4f hf_transform_scale(HF_Vec3f vec);//create a scale matrix

//TODO: view and perspective

HF_Vec3f hf_transform_apply(HF_Vec3f vec, HF_Mat4f mat);//returns vec transformed by the matrix mat

#endif//HF_TRANSFORM_H
