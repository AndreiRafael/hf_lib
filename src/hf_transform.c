#include "../include/hf_transform.h"

#include <math.h>

#define HF_TRANSFORM_PI (3.14159265358979323846)
#define HF_TRANSFORM_PI_2 (HF_TRANSFORM_PI / 2.0)

void hf_transform2f_translation(hf_vec2f vec, hf_mat3f out) {
    hf_mat3f_identity(out);
    out[2][0] = vec[0];
    out[2][1] = vec[1];
}

void hf_transform2f_rotation(float rad, hf_mat3f out) {
    hf_transform2f_rotation_cached(sinf(rad), cosf(rad), out);
}

void hf_transform2f_rotation_cached(float sin_rad, float cos_rad, hf_mat3f out) {
    hf_mat3f_identity(out);
    out[0][0] = cos_rad;
    out[0][1] = -sin_rad;

    out[1][0] = sin_rad;
    out[1][1] = cos_rad;
}

void hf_transform2f_scale(hf_vec2f vec, hf_mat3f out) {
    hf_mat3f_identity(out);
    out[0][0] = vec[0];
    out[1][1] = vec[1];
}

void hf_transform2f_apply(hf_vec2f vec, hf_mat3f mat, hf_vec2f out) {
    hf_mat1x3f tmp;
    tmp[0][0] = vec[0];
    tmp[0][1] = vec[1];
    tmp[0][2] = 1.f;
    hf_mat1x3f_multiply_mat3f(mat, tmp, tmp);
    out[0] = tmp[0][0];
    out[1] = tmp[0][1];
}


void hf_transform3f_translation(hf_vec3f vec, hf_mat4f out) {
    hf_mat4f_identity(out);
    out[3][0] = vec[0];
    out[3][1] = vec[1];
    out[3][2] = vec[2];
}

void hf_transform3f_rotation(hf_vec3f vec, float rad, hf_mat4f out) {
    hf_transform3f_rotation_cached(vec, sinf(rad), cosf(rad), out);
}

void hf_transform3f_rotation_cached(hf_vec3f vec, float sin_rad, float cos_rad, hf_mat4f out) {
    float one_minus_cos = 1.f - cos_rad;

    hf_mat4f_identity(out);
    out[0][0] = cos_rad + vec[0] * vec[0] * one_minus_cos;
    out[0][1] = vec[0] * vec[1] * one_minus_cos - vec[2] * sin_rad;
    out[0][2] = vec[0] * vec[2] * one_minus_cos + vec[1] * sin_rad;

    out[1][0] = vec[0] * vec[1] * one_minus_cos + vec[2] * sin_rad;
    out[1][1] = cos_rad + vec[1] * vec[1] * one_minus_cos;
    out[1][2] = vec[1] * vec[2] * one_minus_cos - vec[0] * sin_rad;

    out[2][0] = vec[0] * vec[2] * one_minus_cos - vec[1] * sin_rad;
    out[2][1] = vec[1] * vec[2] * one_minus_cos + vec[0] * sin_rad;
    out[2][2] = cos_rad + vec[2] * vec[2] * one_minus_cos;
}

void hf_transform3f_rotation_x(float rad, hf_mat4f out) {
    hf_transform3f_rotation_x_cached(sinf(rad), cosf(rad), out);
}

void hf_transform3f_rotation_x_cached(float sin_rad, float cos_rad, hf_mat4f out) {
    hf_mat4f_identity(out);

    out[1][1] = cos_rad;
    out[1][2] = -sin_rad;

    out[2][1] = sin_rad;
    out[2][2] = cos_rad;
}

void hf_transform3f_rotation_y(float rad, hf_mat4f out) {
    hf_transform3f_rotation_y_cached(sinf(rad), cosf(rad), out);
}

void hf_transform3f_rotation_y_cached(float sin_rad, float cos_rad, hf_mat4f out) {
    hf_mat4f_identity(out);

    out[0][0] = cos_rad;
    out[0][2] = sin_rad;

    out[2][0] = -sin_rad;
    out[2][2] = cos_rad;
}

void hf_transform3f_rotation_z(float rad, hf_mat4f out) {
    hf_transform3f_rotation_z_cached(sinf(rad), cosf(rad), out);
}

void hf_transform3f_rotation_z_cached(float sin_rad, float cos_rad, hf_mat4f out) {
    hf_mat4f_identity(out);

    out[0][0] = cos_rad;
    out[0][1] = -sin_rad;

    out[1][0] = sin_rad;
    out[1][1] = cos_rad;
}

void hf_transform3f_rotation_from_direction(hf_vec3f dir, hf_vec3f up, hf_mat4f out) {
    (void)up;// TODO:
    float x = atan2f(dir[1], dir[0]);
    float y = atan2f(dir[2], dir[0]);

    hf_mat4f rot_x;
    hf_transform3f_rotation_x(x, rot_x);
    hf_mat4f rot_y;
    hf_transform3f_rotation_y(y, rot_y);
    hf_mat4f_multiply_mat4f(rot_x, rot_y, out);
}

void hf_transform3f_rotation_from_quat(hf_quatf quat, hf_mat4f out) {
    hf_mat4f_identity(out);

    out[0][0] = quat[0] * quat[0] - quat[1] * quat[1] - quat[2] * quat[2] + quat[3] * quat[3];
    out[0][1] = 2.f * quat[0] * quat[1] + 2.f * quat[2] * quat[3];
    out[0][2] = 2.f * quat[0] * quat[2] - 2.f * quat[1] * quat[3];

    out[1][0] = 2.f * quat[0] * quat[1] - 2.f * quat[2] * quat[3];
    out[1][1] = -quat[0] * quat[0] + quat[1] * quat[1] - quat[2] * quat[2] + quat[3] * quat[3];
    out[1][2] = 2.f * quat[1] * quat[2] + 2.f * quat[0] * quat[3];

    out[2][0] = 2.f * quat[0] * quat[2] + 2.f * quat[1] * quat[3];
    out[2][1] = 2.f * quat[1] * quat[2] - 2.f * quat[0] * quat[3];
    out[2][2] = -quat[0] * quat[0] - quat[1] * quat[1] + quat[2] * quat[2] + quat[3] * quat[3];
}

void hf_transform3f_scale(hf_vec3f vec, hf_mat4f out) {
    hf_mat4f_identity(out);
    out[0][0] = vec[0];
    out[1][1] = vec[1];
    out[2][2] = vec[2];
}

void hf_transform3f_apply(hf_vec3f vec, hf_mat4f mat, hf_vec3f out) {
    hf_mat1x4f tmp;
    tmp[0][0] = vec[0];
    tmp[0][1] = vec[1];
    tmp[0][2] = vec[2];
    tmp[0][3] = 1.f;
    hf_mat1x4f_multiply_mat4f(tmp, mat, tmp);
    out[0] = tmp[0][0];
    out[1] = tmp[0][1];
    out[2] = tmp[0][2];
}

void hf_transform3f_projection_orthographic_size(float w, float h, float near, float far, hf_mat4f out) {
    hf_mat4f_identity(out);
    out[0][0] = 2.f / w;
    out[1][1] = 2.f / h;
    out[2][2] = -2.f / (far - near);
    out[3][2] = -((far + near) / (far - near));
}

void hf_transform3f_projection_perspective_size(float w, float h, float near, float far, hf_mat4f out) {
    hf_mat4f_identity(out);
    out[0][0] = (2.f * near) / w;
    out[1][1] = (2.f * near) / h;
    out[2][2] = -((far + near) / (far - near));
    out[2][3] = -1.f;
    out[3][2] = -((2.f * far * near) / (far - near));
    out[3][3] = 0.f;
}

void hf_transform3f_projection_perspective_fov(float fov_rad, float aspect_ratio, float near, float far, hf_mat4f out) {
    float h = near / (cosf(fov_rad / 2.f) / sinf(fov_rad / 2.f));
    float w = h * aspect_ratio;
    hf_transform3f_projection_perspective_size(w, h, near, far, out);
}

void hf_transform3f_view(hf_vec3f position, hf_vec3f forward, hf_vec3f up, hf_mat4f out) {
    hf_vec3f pos = { position[0], position[1], position[2] };

    hf_vec3f f;
    hf_vec3f_normalize(forward, f);

    hf_vec3f r;
    hf_vec3f_cross(f, up, r);
    hf_vec3f_normalize(r, r);

    hf_vec3f u;
    hf_vec3f_cross(r, f, u);

    out[0][0] = r[0];
    out[1][0] = r[1];
    out[2][0] = r[2];

    out[0][1] = u[0];
    out[1][1] = u[1];
    out[2][1] = u[2];

    out[0][2] = -f[0];
    out[1][2] = -f[1];
    out[2][2] = -f[2];

    out[3][0] = -hf_vec3f_dot(r, pos);
    out[3][1] = -hf_vec3f_dot(u, pos);
    out[3][2] =  hf_vec3f_dot(f, pos);

    out[0][3] = 0.f;
    out[1][3] = 0.f;
    out[2][3] = 0.f;
    out[3][3] = 1.f;
}
