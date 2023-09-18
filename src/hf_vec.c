#include "../include/hf_vec.h"

#include <string.h>
#include <math.h>

void hf_vec2f_copy(HF_Vec2f vec, HF_Vec2f out) {
	memcpy(out, vec, sizeof(out[0]) * 2);
}

void hf_vec2f_add(HF_Vec2f a, HF_Vec2f b, HF_Vec2f out) {
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
}

void hf_vec2f_subtract(HF_Vec2f a, HF_Vec2f b, HF_Vec2f out) {
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
}

void hf_vec2f_multiply(HF_Vec2f vec, float scalar, HF_Vec2f out) {
	out[0] = vec[0] * scalar;
	out[1] = vec[1] * scalar;
}

void hf_vec2f_divide(HF_Vec2f vec, float scalar, HF_Vec2f out) {
	out[0] = vec[0] / scalar;
	out[1] = vec[1] / scalar;
}

void hf_vec2f_lerp(HF_Vec2f a, HF_Vec2f b, float t, HF_Vec2f out) {
	out[0] = a[0] * (1.f - t) + b[0] * t;
	out[1] = a[1] * (1.f - t) + b[1] * t;
}

float hf_vec2f_square_magnitude(HF_Vec2f vec) {
	return vec[0] * vec[0] + vec[1] * vec[1];
}

float hf_vec2f_magnitude(HF_Vec2f vec) {
	return sqrtf(hf_vec2f_square_magnitude(vec));
}

float hf_vec2f_dot(HF_Vec2f a, HF_Vec2f b) {
	return a[0] * b[0] + a[1] * b[1];
}

void hf_vec2i_copy(HF_Vec2i vec, HF_Vec2i out) {
	memcpy(out, vec, sizeof(out[0]) * 2);
}

void hf_vec2i_add(HF_Vec2i a, HF_Vec2i b, HF_Vec2i out) {
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
}

void hf_vec2i_subtract(HF_Vec2i a, HF_Vec2i b, HF_Vec2i out) {
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
}

void hf_vec2i_multiply(HF_Vec2i vec, int scalar, HF_Vec2i out) {
	out[0] = vec[0] * scalar;
	out[1] = vec[1] * scalar;
}

void hf_vec2i_divide(HF_Vec2i vec, int scalar, HF_Vec2i out) {
	out[0] = vec[0] / scalar;
	out[1] = vec[1] / scalar;
}

int hf_vec2i_square_magnitude(HF_Vec2i vec) {
	return vec[0] * vec[0] + vec[1] * vec[1];
}

float hf_vec2i_magnitude(HF_Vec2i vec) {
	return sqrtf((float)hf_vec2i_square_magnitude(vec));
}

int hf_vec2i_dot(HF_Vec2i a, HF_Vec2i b) {
	return a[0] * b[0] + a[1] * b[1];
}

void hf_vec3f_copy(HF_Vec3f vec, HF_Vec3f out) {
	memcpy(out, vec, sizeof(out[0]) * 3);
}

void hf_vec3f_add(HF_Vec3f a, HF_Vec3f b, HF_Vec3f out) {
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
	out[2] = a[2] + b[2];
}

void hf_vec3f_subtract(HF_Vec3f a, HF_Vec3f b, HF_Vec3f out) {
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
	out[2] = a[2] - b[2];
}

void hf_vec3f_multiply(HF_Vec3f vec, float scalar, HF_Vec3f out) {
	out[0] = vec[0] * scalar;
	out[1] = vec[1] * scalar;
	out[2] = vec[2] * scalar;
}

void hf_vec3f_divide(HF_Vec3f vec, float scalar, HF_Vec3f out) {
	out[0] = vec[0] / scalar;
	out[1] = vec[1] / scalar;
	out[2] = vec[2] / scalar;
}

void hf_vec3f_lerp(HF_Vec3f a, HF_Vec3f b, float t, HF_Vec3f out) {
	out[0] = a[0] * (1.f - t) + b[0] * t;
	out[1] = a[1] * (1.f - t) + b[1] * t;
	out[2] = a[2] * (1.f - t) + b[2] * t;
}

float hf_vec3f_square_magnitude(HF_Vec3f vec) {
	return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
}

float hf_vec3f_magnitude(HF_Vec3f vec) {
	return sqrtf(hf_vec3f_square_magnitude(vec));
}

float hf_vec3f_dot(HF_Vec3f a, HF_Vec3f b) {
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void hf_vec3f_cross(HF_Vec3f a, HF_Vec3f b, HF_Vec3f out) {
	HF_Vec3f tmp;
	tmp[0] = a[1] * b[2] - a[2] * b[1];
	tmp[1] = a[2] * b[0] - a[0] * b[2];
	tmp[2] = a[0] * b[1] - a[1] * b[0];
	memcpy(out, tmp, sizeof(out[0]) * 3);
}

void hf_vec3i_copy(HF_Vec3i vec, HF_Vec3i out) {
	memcpy(out, vec, sizeof(out[0]) * 3);
}

void hf_vec3i_add(HF_Vec3i a, HF_Vec3i b, HF_Vec3i out) {
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
	out[2] = a[2] + b[2];
}

void hf_vec3i_subtract(HF_Vec3i a, HF_Vec3i b, HF_Vec3i out) {
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
	out[2] = a[2] - b[2];
}

void hf_vec3i_multiply(HF_Vec3i vec, int scalar, HF_Vec3i out) {
	out[0] = vec[0] * scalar;
	out[1] = vec[1] * scalar;
	out[2] = vec[2] * scalar;
}

void hf_vec3i_divide(HF_Vec3i vec, int scalar, HF_Vec3i out) {
	out[0] = vec[0] / scalar;
	out[1] = vec[1] / scalar;
	out[2] = vec[2] / scalar;
}

int hf_vec3i_square_magnitude(HF_Vec3i vec) {
	return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
}

float hf_vec3i_magnitude(HF_Vec3i vec) {
	return sqrtf((float)hf_vec3i_square_magnitude(vec));
}

int hf_vec3i_dot(HF_Vec3i a, HF_Vec3i b) {
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void hf_vec3i_cross(HF_Vec3i a, HF_Vec3i b, HF_Vec3i out) {
	HF_Vec3i tmp;
	tmp[0] = a[1] * b[2] - a[2] * b[1];
	tmp[1] = a[2] * b[0] - a[0] * b[2];
	tmp[2] = a[0] * b[1] - a[1] * b[0];
	memcpy(out, tmp, sizeof(out[0]) * 3);
}
