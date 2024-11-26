#ifndef HF_QUAT_H
#define HF_QUAT_H

#include "hf_vec.h"

typedef float hf_quatf[4];

float hf_quatf_square_magnitude(hf_quatf quat);
float hf_quatf_magnitude(hf_quatf quat);
void hf_quatf_normalize(hf_quatf quat, hf_quatf out);
void hf_quatf_conjugate(hf_quatf quat, hf_quatf out);
void hf_quatf_inverse(hf_quatf quat, hf_quatf out);
void hf_quatf_add(hf_quatf a, hf_quatf b, hf_quatf out);
void hf_quatf_subtract(hf_quatf a, hf_quatf b, hf_quatf out);
void hf_quatf_multiply(hf_quatf quat, float scalar, hf_quatf out);
void hf_quatf_multiply_quatf(hf_quatf a, hf_quatf b, hf_quatf out);
void hf_quatf_lerp(hf_quatf a, hf_quatf b, float t, hf_quatf out);
void hf_quatf_slerp(hf_quatf a, hf_quatf b, float t, hf_quatf out);

void hf_quatf_from_axis_angle(hf_vec3f axis, float angle, hf_quatf out);
void hf_quatf_from_direction(hf_vec3f dir, hf_vec3f up, hf_quatf out);

#endif//HF_QUAT_H
