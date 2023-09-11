#ifndef HF_TRANSFORM_H
#define HF_TRANSFORM_H

#include "hf_vec.h"
#include "hf_mat.h"

HF_Mat4f hf_transform_translation(HF_Vec3f vec);
HF_Mat4f hf_transform_rotation(HF_Vec3f vec, float rad);
HF_Mat4f hf_transform_rotation_cached(HF_Vec3f vec, float sin_rad, float cos_rad);
HF_Mat4f hf_transform_scale(HF_Vec3f vec);

//TODO: view and perspective

#endif//HF_TRANSFORM_H
