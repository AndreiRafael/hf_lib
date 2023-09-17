#ifndef HF_MAT_H
#define HF_MAT_H

typedef float HF_Mat1x2f[1][2];
typedef float HF_Mat1x3f[1][3];
typedef float HF_Mat1x4f[1][4];
typedef float HF_Mat2x1f[2][1];
typedef float HF_Mat2f[2][2];
typedef float HF_Mat2x3f[2][3];
typedef float HF_Mat2x4f[2][4];
typedef float HF_Mat3x1f[3][1];
typedef float HF_Mat3x2f[3][2];
typedef float HF_Mat3f[3][3];
typedef float HF_Mat3x4f[3][4];
typedef float HF_Mat4x1f[4][1];
typedef float HF_Mat4x2f[4][2];
typedef float HF_Mat4x3f[4][3];
typedef float HF_Mat4f[4][4];

void hf_mat1x2f_copy(HF_Mat1x2f mat, HF_Mat1x2f out);
void hf_mat1x2f_transpose(HF_Mat1x2f mat, HF_Mat2x1f out);
void hf_mat1x2f_add(HF_Mat1x2f a, HF_Mat1x2f b, HF_Mat1x2f out);
void hf_mat1x2f_multiply(HF_Mat1x2f mat, float scalar, HF_Mat1x2f out);
void hf_mat1x2f_multiply_mat2f(HF_Mat1x2f a, HF_Mat2f b, HF_Mat1x2f out);
void hf_mat1x2f_multiply_mat2x3f(HF_Mat1x2f a, HF_Mat2x3f b, HF_Mat1x3f out);
void hf_mat1x2f_multiply_mat2x4f(HF_Mat1x2f a, HF_Mat2x4f b, HF_Mat1x4f out);

void hf_mat1x3f_copy(HF_Mat1x3f mat, HF_Mat1x3f out);
void hf_mat1x3f_transpose(HF_Mat1x3f mat, HF_Mat3x1f out);
void hf_mat1x3f_add(HF_Mat1x3f a, HF_Mat1x3f b, HF_Mat1x3f out);
void hf_mat1x3f_multiply(HF_Mat1x3f mat, float scalar, HF_Mat1x3f out);
void hf_mat1x3f_multiply_mat3x2f(HF_Mat1x3f a, HF_Mat3x2f b, HF_Mat1x2f out);
void hf_mat1x3f_multiply_mat3f(HF_Mat1x3f a, HF_Mat3f b, HF_Mat1x3f out);
void hf_mat1x3f_multiply_mat3x4f(HF_Mat1x3f a, HF_Mat3x4f b, HF_Mat1x4f out);

void hf_mat1x4f_copy(HF_Mat1x4f mat, HF_Mat1x4f out);
void hf_mat1x4f_transpose(HF_Mat1x4f mat, HF_Mat4x1f out);
void hf_mat1x4f_add(HF_Mat1x4f a, HF_Mat1x4f b, HF_Mat1x4f out);
void hf_mat1x4f_multiply(HF_Mat1x4f mat, float scalar, HF_Mat1x4f out);
void hf_mat1x4f_multiply_mat4x2f(HF_Mat1x4f a, HF_Mat4x2f b, HF_Mat1x2f out);
void hf_mat1x4f_multiply_mat4x3f(HF_Mat1x4f a, HF_Mat4x3f b, HF_Mat1x3f out);
void hf_mat1x4f_multiply_mat4f(HF_Mat1x4f a, HF_Mat4f b, HF_Mat1x4f out);

void hf_mat2x1f_copy(HF_Mat2x1f mat, HF_Mat2x1f out);
void hf_mat2x1f_transpose(HF_Mat2x1f mat, HF_Mat1x2f out);
void hf_mat2x1f_add(HF_Mat2x1f a, HF_Mat2x1f b, HF_Mat2x1f out);
void hf_mat2x1f_multiply(HF_Mat2x1f mat, float scalar, HF_Mat2x1f out);
void hf_mat2x1f_multiply_mat1x2f(HF_Mat2x1f a, HF_Mat1x2f b, HF_Mat2f out);
void hf_mat2x1f_multiply_mat1x3f(HF_Mat2x1f a, HF_Mat1x3f b, HF_Mat2x3f out);
void hf_mat2x1f_multiply_mat1x4f(HF_Mat2x1f a, HF_Mat1x4f b, HF_Mat2x4f out);

void hf_mat2f_copy(HF_Mat2f mat, HF_Mat2f out);
void hf_mat2f_identity(HF_Mat2f out);
void hf_mat2f_transpose(HF_Mat2f mat, HF_Mat2f out);
float hf_mat2f_determinant(HF_Mat2f mat);
float hf_mat2f_minor(HF_Mat2f mat, int i, int j);
void hf_mat2f_inverse(HF_Mat2f mat, HF_Mat2f out);
void hf_mat2f_add(HF_Mat2f a, HF_Mat2f b, HF_Mat2f out);
void hf_mat2f_multiply(HF_Mat2f mat, float scalar, HF_Mat2f out);
void hf_mat2f_multiply_mat2x1f(HF_Mat2f a, HF_Mat2x1f b, HF_Mat2x1f out);
void hf_mat2f_multiply_mat2f(HF_Mat2f a, HF_Mat2f b, HF_Mat2f out);
void hf_mat2f_multiply_mat2x3f(HF_Mat2f a, HF_Mat2x3f b, HF_Mat2x3f out);
void hf_mat2f_multiply_mat2x4f(HF_Mat2f a, HF_Mat2x4f b, HF_Mat2x4f out);

void hf_mat2x3f_copy(HF_Mat2x3f mat, HF_Mat2x3f out);
void hf_mat2x3f_transpose(HF_Mat2x3f mat, HF_Mat3x2f out);
void hf_mat2x3f_add(HF_Mat2x3f a, HF_Mat2x3f b, HF_Mat2x3f out);
void hf_mat2x3f_multiply(HF_Mat2x3f mat, float scalar, HF_Mat2x3f out);
void hf_mat2x3f_multiply_mat3x1f(HF_Mat2x3f a, HF_Mat3x1f b, HF_Mat2x1f out);
void hf_mat2x3f_multiply_mat3x2f(HF_Mat2x3f a, HF_Mat3x2f b, HF_Mat2f out);
void hf_mat2x3f_multiply_mat3f(HF_Mat2x3f a, HF_Mat3f b, HF_Mat2x3f out);
void hf_mat2x3f_multiply_mat3x4f(HF_Mat2x3f a, HF_Mat3x4f b, HF_Mat2x4f out);

void hf_mat2x4f_copy(HF_Mat2x4f mat, HF_Mat2x4f out);
void hf_mat2x4f_transpose(HF_Mat2x4f mat, HF_Mat4x2f out);
void hf_mat2x4f_add(HF_Mat2x4f a, HF_Mat2x4f b, HF_Mat2x4f out);
void hf_mat2x4f_multiply(HF_Mat2x4f mat, float scalar, HF_Mat2x4f out);
void hf_mat2x4f_multiply_mat4x1f(HF_Mat2x4f a, HF_Mat4x1f b, HF_Mat2x1f out);
void hf_mat2x4f_multiply_mat4x2f(HF_Mat2x4f a, HF_Mat4x2f b, HF_Mat2f out);
void hf_mat2x4f_multiply_mat4x3f(HF_Mat2x4f a, HF_Mat4x3f b, HF_Mat2x3f out);
void hf_mat2x4f_multiply_mat4f(HF_Mat2x4f a, HF_Mat4f b, HF_Mat2x4f out);

void hf_mat3x1f_copy(HF_Mat3x1f mat, HF_Mat3x1f out);
void hf_mat3x1f_transpose(HF_Mat3x1f mat, HF_Mat1x3f out);
void hf_mat3x1f_add(HF_Mat3x1f a, HF_Mat3x1f b, HF_Mat3x1f out);
void hf_mat3x1f_multiply(HF_Mat3x1f mat, float scalar, HF_Mat3x1f out);
void hf_mat3x1f_multiply_mat1x2f(HF_Mat3x1f a, HF_Mat1x2f b, HF_Mat3x2f out);
void hf_mat3x1f_multiply_mat1x3f(HF_Mat3x1f a, HF_Mat1x3f b, HF_Mat3f out);
void hf_mat3x1f_multiply_mat1x4f(HF_Mat3x1f a, HF_Mat1x4f b, HF_Mat3x4f out);

void hf_mat3x2f_copy(HF_Mat3x2f mat, HF_Mat3x2f out);
void hf_mat3x2f_transpose(HF_Mat3x2f mat, HF_Mat2x3f out);
void hf_mat3x2f_add(HF_Mat3x2f a, HF_Mat3x2f b, HF_Mat3x2f out);
void hf_mat3x2f_multiply(HF_Mat3x2f mat, float scalar, HF_Mat3x2f out);
void hf_mat3x2f_multiply_mat2x1f(HF_Mat3x2f a, HF_Mat2x1f b, HF_Mat3x1f out);
void hf_mat3x2f_multiply_mat2f(HF_Mat3x2f a, HF_Mat2f b, HF_Mat3x2f out);
void hf_mat3x2f_multiply_mat2x3f(HF_Mat3x2f a, HF_Mat2x3f b, HF_Mat3f out);
void hf_mat3x2f_multiply_mat2x4f(HF_Mat3x2f a, HF_Mat2x4f b, HF_Mat3x4f out);

void hf_mat3f_copy(HF_Mat3f mat, HF_Mat3f out);
void hf_mat3f_identity(HF_Mat3f out);
void hf_mat3f_transpose(HF_Mat3f mat, HF_Mat3f out);
float hf_mat3f_determinant(HF_Mat3f mat);
float hf_mat3f_minor(HF_Mat3f mat, int i, int j);
void hf_mat3f_inverse(HF_Mat3f mat, HF_Mat3f out);
void hf_mat3f_add(HF_Mat3f a, HF_Mat3f b, HF_Mat3f out);
void hf_mat3f_multiply(HF_Mat3f mat, float scalar, HF_Mat3f out);
void hf_mat3f_multiply_mat3x1f(HF_Mat3f a, HF_Mat3x1f b, HF_Mat3x1f out);
void hf_mat3f_multiply_mat3x2f(HF_Mat3f a, HF_Mat3x2f b, HF_Mat3x2f out);
void hf_mat3f_multiply_mat3f(HF_Mat3f a, HF_Mat3f b, HF_Mat3f out);
void hf_mat3f_multiply_mat3x4f(HF_Mat3f a, HF_Mat3x4f b, HF_Mat3x4f out);

void hf_mat3x4f_copy(HF_Mat3x4f mat, HF_Mat3x4f out);
void hf_mat3x4f_transpose(HF_Mat3x4f mat, HF_Mat4x3f out);
void hf_mat3x4f_add(HF_Mat3x4f a, HF_Mat3x4f b, HF_Mat3x4f out);
void hf_mat3x4f_multiply(HF_Mat3x4f mat, float scalar, HF_Mat3x4f out);
void hf_mat3x4f_multiply_mat4x1f(HF_Mat3x4f a, HF_Mat4x1f b, HF_Mat3x1f out);
void hf_mat3x4f_multiply_mat4x2f(HF_Mat3x4f a, HF_Mat4x2f b, HF_Mat3x2f out);
void hf_mat3x4f_multiply_mat4x3f(HF_Mat3x4f a, HF_Mat4x3f b, HF_Mat3f out);
void hf_mat3x4f_multiply_mat4f(HF_Mat3x4f a, HF_Mat4f b, HF_Mat3x4f out);

void hf_mat4x1f_copy(HF_Mat4x1f mat, HF_Mat4x1f out);
void hf_mat4x1f_transpose(HF_Mat4x1f mat, HF_Mat1x4f out);
void hf_mat4x1f_add(HF_Mat4x1f a, HF_Mat4x1f b, HF_Mat4x1f out);
void hf_mat4x1f_multiply(HF_Mat4x1f mat, float scalar, HF_Mat4x1f out);
void hf_mat4x1f_multiply_mat1x2f(HF_Mat4x1f a, HF_Mat1x2f b, HF_Mat4x2f out);
void hf_mat4x1f_multiply_mat1x3f(HF_Mat4x1f a, HF_Mat1x3f b, HF_Mat4x3f out);
void hf_mat4x1f_multiply_mat1x4f(HF_Mat4x1f a, HF_Mat1x4f b, HF_Mat4f out);

void hf_mat4x2f_copy(HF_Mat4x2f mat, HF_Mat4x2f out);
void hf_mat4x2f_transpose(HF_Mat4x2f mat, HF_Mat2x4f out);
void hf_mat4x2f_add(HF_Mat4x2f a, HF_Mat4x2f b, HF_Mat4x2f out);
void hf_mat4x2f_multiply(HF_Mat4x2f mat, float scalar, HF_Mat4x2f out);
void hf_mat4x2f_multiply_mat2x1f(HF_Mat4x2f a, HF_Mat2x1f b, HF_Mat4x1f out);
void hf_mat4x2f_multiply_mat2f(HF_Mat4x2f a, HF_Mat2f b, HF_Mat4x2f out);
void hf_mat4x2f_multiply_mat2x3f(HF_Mat4x2f a, HF_Mat2x3f b, HF_Mat4x3f out);
void hf_mat4x2f_multiply_mat2x4f(HF_Mat4x2f a, HF_Mat2x4f b, HF_Mat4f out);

void hf_mat4x3f_copy(HF_Mat4x3f mat, HF_Mat4x3f out);
void hf_mat4x3f_transpose(HF_Mat4x3f mat, HF_Mat3x4f out);
void hf_mat4x3f_add(HF_Mat4x3f a, HF_Mat4x3f b, HF_Mat4x3f out);
void hf_mat4x3f_multiply(HF_Mat4x3f mat, float scalar, HF_Mat4x3f out);
void hf_mat4x3f_multiply_mat3x1f(HF_Mat4x3f a, HF_Mat3x1f b, HF_Mat4x1f out);
void hf_mat4x3f_multiply_mat3x2f(HF_Mat4x3f a, HF_Mat3x2f b, HF_Mat4x2f out);
void hf_mat4x3f_multiply_mat3f(HF_Mat4x3f a, HF_Mat3f b, HF_Mat4x3f out);
void hf_mat4x3f_multiply_mat3x4f(HF_Mat4x3f a, HF_Mat3x4f b, HF_Mat4f out);

void hf_mat4f_copy(HF_Mat4f mat, HF_Mat4f out);
void hf_mat4f_identity(HF_Mat4f out);
void hf_mat4f_transpose(HF_Mat4f mat, HF_Mat4f out);
float hf_mat4f_determinant(HF_Mat4f mat);
float hf_mat4f_minor(HF_Mat4f mat, int i, int j);
void hf_mat4f_inverse(HF_Mat4f mat, HF_Mat4f out);
void hf_mat4f_add(HF_Mat4f a, HF_Mat4f b, HF_Mat4f out);
void hf_mat4f_multiply(HF_Mat4f mat, float scalar, HF_Mat4f out);
void hf_mat4f_multiply_mat4x1f(HF_Mat4f a, HF_Mat4x1f b, HF_Mat4x1f out);
void hf_mat4f_multiply_mat4x2f(HF_Mat4f a, HF_Mat4x2f b, HF_Mat4x2f out);
void hf_mat4f_multiply_mat4x3f(HF_Mat4f a, HF_Mat4x3f b, HF_Mat4x3f out);
void hf_mat4f_multiply_mat4f(HF_Mat4f a, HF_Mat4f b, HF_Mat4f out);

#endif//HF_MAT_H
