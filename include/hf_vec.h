#ifndef HF_VEC_H
#define HF_VEC_H

typedef float HF_Vec2f[2];
typedef int HF_Vec2i[2];
typedef float HF_Vec3f[3];
typedef int HF_Vec3i[3];

void hf_vec2f_copy(HF_Vec2f vec, HF_Vec2f out);
void hf_vec2f_add(HF_Vec2f a, HF_Vec2f b, HF_Vec2f out);
void hf_vec2f_subtract(HF_Vec2f a, HF_Vec2f b, HF_Vec2f out);
void hf_vec2f_multiply(HF_Vec2f vec, float scalar, HF_Vec2f out);
void hf_vec2f_divide(HF_Vec2f vec, float scalar, HF_Vec2f out);
void hf_vec2f_normalize(HF_Vec2f vec, HF_Vec2f out);
void hf_vec2f_lerp(HF_Vec2f a, HF_Vec2f b, float t, HF_Vec2f out);
float hf_vec2f_square_magnitude(HF_Vec2f vec);
float hf_vec2f_magnitude(HF_Vec2f vec);
float hf_vec2f_dot(HF_Vec2f a, HF_Vec2f b);

void hf_vec2i_copy(HF_Vec2i vec, HF_Vec2i out);
void hf_vec2i_add(HF_Vec2i a, HF_Vec2i b, HF_Vec2i out);
void hf_vec2i_subtract(HF_Vec2i a, HF_Vec2i b, HF_Vec2i out);
void hf_vec2i_multiply(HF_Vec2i vec, int scalar, HF_Vec2i out);
void hf_vec2i_divide(HF_Vec2i vec, int scalar, HF_Vec2i out);
int hf_vec2i_square_magnitude(HF_Vec2i vec);
float hf_vec2i_magnitude(HF_Vec2i vec);
int hf_vec2i_dot(HF_Vec2i a, HF_Vec2i b);

void hf_vec3f_copy(HF_Vec3f vec, HF_Vec3f out);
void hf_vec3f_add(HF_Vec3f a, HF_Vec3f b, HF_Vec3f out);
void hf_vec3f_subtract(HF_Vec3f a, HF_Vec3f b, HF_Vec3f out);
void hf_vec3f_multiply(HF_Vec3f vec, float scalar, HF_Vec3f out);
void hf_vec3f_divide(HF_Vec3f vec, float scalar, HF_Vec3f out);
void hf_vec3f_normalize(HF_Vec3f vec, HF_Vec3f out);
void hf_vec3f_lerp(HF_Vec3f a, HF_Vec3f b, float t, HF_Vec3f out);
float hf_vec3f_square_magnitude(HF_Vec3f vec);
float hf_vec3f_magnitude(HF_Vec3f vec);
float hf_vec3f_dot(HF_Vec3f a, HF_Vec3f b);
void hf_vec3f_cross(HF_Vec3f a, HF_Vec3f b, HF_Vec3f out);

void hf_vec3i_copy(HF_Vec3i vec, HF_Vec3i out);
void hf_vec3i_add(HF_Vec3i a, HF_Vec3i b, HF_Vec3i out);
void hf_vec3i_subtract(HF_Vec3i a, HF_Vec3i b, HF_Vec3i out);
void hf_vec3i_multiply(HF_Vec3i vec, int scalar, HF_Vec3i out);
void hf_vec3i_divide(HF_Vec3i vec, int scalar, HF_Vec3i out);
int hf_vec3i_square_magnitude(HF_Vec3i vec);
float hf_vec3i_magnitude(HF_Vec3i vec);
int hf_vec3i_dot(HF_Vec3i a, HF_Vec3i b);
void hf_vec3i_cross(HF_Vec3i a, HF_Vec3i b, HF_Vec3i out);

#endif//HF_VEC_H
