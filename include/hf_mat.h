#ifndef HF_MAT_H
#define HF_MAT_H

typedef struct HF_Mat2f_s {
	float values[2][2];
} HF_Mat2f;

typedef struct HF_Mat2x3f_s {
	float values[2][3];
} HF_Mat2x3f;

typedef struct HF_Mat2x4f_s {
	float values[2][4];
} HF_Mat2x4f;

typedef struct HF_Mat3x2f_s {
	float values[3][2];
} HF_Mat3x2f;

typedef struct HF_Mat3f_s {
	float values[3][3];
} HF_Mat3f;

typedef struct HF_Mat3x4f_s {
	float values[3][4];
} HF_Mat3x4f;

typedef struct HF_Mat4x2f_s {
	float values[4][2];
} HF_Mat4x2f;

typedef struct HF_Mat4x3f_s {
	float values[4][3];
} HF_Mat4x3f;

typedef struct HF_Mat4f_s {
	float values[4][4];
} HF_Mat4f;

HF_Mat2f hf_mat2f_identity(void);
HF_Mat2f hf_mat2f_multiply(HF_Mat2f a, float scalar);
HF_Mat2f hf_mat2f_multiply_mat2f(HF_Mat2f a, HF_Mat2f b);
HF_Mat2x3f hf_mat2f_multiply_mat2x3f(HF_Mat2f a, HF_Mat2x3f b);
HF_Mat2x4f hf_mat2f_multiply_mat2x4f(HF_Mat2f a, HF_Mat2x4f b);

HF_Mat2x3f hf_mat2x3f_multiply(HF_Mat2x3f a, float scalar);
HF_Mat2f hf_mat2x3f_multiply_mat3x2f(HF_Mat2x3f a, HF_Mat3x2f b);
HF_Mat2x3f hf_mat2x3f_multiply_mat3f(HF_Mat2x3f a, HF_Mat3f b);
HF_Mat2x4f hf_mat2x3f_multiply_mat3x4f(HF_Mat2x3f a, HF_Mat3x4f b);

HF_Mat2x4f hf_mat2x4f_multiply(HF_Mat2x4f a, float scalar);
HF_Mat2f hf_mat2x4f_multiply_mat4x2f(HF_Mat2x4f a, HF_Mat4x2f b);
HF_Mat2x3f hf_mat2x4f_multiply_mat4x3f(HF_Mat2x4f a, HF_Mat4x3f b);
HF_Mat2x4f hf_mat2x4f_multiply_mat4f(HF_Mat2x4f a, HF_Mat4f b);

HF_Mat3x2f hf_mat3x2f_multiply(HF_Mat3x2f a, float scalar);
HF_Mat3x2f hf_mat3x2f_multiply_mat2f(HF_Mat3x2f a, HF_Mat2f b);
HF_Mat3f hf_mat3x2f_multiply_mat2x3f(HF_Mat3x2f a, HF_Mat2x3f b);
HF_Mat3x4f hf_mat3x2f_multiply_mat2x4f(HF_Mat3x2f a, HF_Mat2x4f b);

HF_Mat3f hf_mat3f_identity(void);
HF_Mat3f hf_mat3f_multiply(HF_Mat3f a, float scalar);
HF_Mat3x2f hf_mat3f_multiply_mat3x2f(HF_Mat3f a, HF_Mat3x2f b);
HF_Mat3f hf_mat3f_multiply_mat3f(HF_Mat3f a, HF_Mat3f b);
HF_Mat3x4f hf_mat3f_multiply_mat3x4f(HF_Mat3f a, HF_Mat3x4f b);

HF_Mat3x4f hf_mat3x4f_multiply(HF_Mat3x4f a, float scalar);
HF_Mat3x2f hf_mat3x4f_multiply_mat4x2f(HF_Mat3x4f a, HF_Mat4x2f b);
HF_Mat3f hf_mat3x4f_multiply_mat4x3f(HF_Mat3x4f a, HF_Mat4x3f b);
HF_Mat3x4f hf_mat3x4f_multiply_mat4f(HF_Mat3x4f a, HF_Mat4f b);

HF_Mat4x2f hf_mat4x2f_multiply(HF_Mat4x2f a, float scalar);
HF_Mat4x2f hf_mat4x2f_multiply_mat2f(HF_Mat4x2f a, HF_Mat2f b);
HF_Mat4x3f hf_mat4x2f_multiply_mat2x3f(HF_Mat4x2f a, HF_Mat2x3f b);
HF_Mat4f hf_mat4x2f_multiply_mat2x4f(HF_Mat4x2f a, HF_Mat2x4f b);

HF_Mat4x3f hf_mat4x3f_multiply(HF_Mat4x3f a, float scalar);
HF_Mat4x2f hf_mat4x3f_multiply_mat3x2f(HF_Mat4x3f a, HF_Mat3x2f b);
HF_Mat4x3f hf_mat4x3f_multiply_mat3f(HF_Mat4x3f a, HF_Mat3f b);
HF_Mat4f hf_mat4x3f_multiply_mat3x4f(HF_Mat4x3f a, HF_Mat3x4f b);

HF_Mat4f hf_mat4f_identity(void);
HF_Mat4f hf_mat4f_multiply(HF_Mat4f a, float scalar);
HF_Mat4x2f hf_mat4f_multiply_mat4x2f(HF_Mat4f a, HF_Mat4x2f b);
HF_Mat4x3f hf_mat4f_multiply_mat4x3f(HF_Mat4f a, HF_Mat4x3f b);
HF_Mat4f hf_mat4f_multiply_mat4f(HF_Mat4f a, HF_Mat4f b);

#endif//HF_MAT_H
