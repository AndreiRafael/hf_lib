#include "../include/hf_quat.h"

#include "../include/hf_vec.h"

#include <math.h>

float hf_quatf_square_magnitude(hf_quatf quat) {
    return quat[0] * quat[0] + quat[1] * quat[1] + quat[2] * quat[2] + quat[3] * quat[3];
}

float hf_quatf_magnitude(hf_quatf quat) {
    return sqrtf(hf_quatf_square_magnitude(quat));
}

void hf_quatf_normalize(hf_quatf quat, hf_quatf out) {
    float len = hf_quatf_magnitude(quat);
    out[0] = quat[0] / len;
    out[1] = quat[1] / len;
    out[2] = quat[2] / len;
    out[3] = quat[3] / len;
}

void hf_quatf_conjugate(hf_quatf quat, hf_quatf out) {
    out[0] = -quat[0];
    out[1] = -quat[1];
    out[2] = -quat[2];
    out[3] = quat[3];
}

void hf_quatf_inverse(hf_quatf quat, hf_quatf out) {
    float sqr = hf_quatf_square_magnitude(quat);
    out[0] = -quat[0] / sqr;
    out[1] = -quat[1] / sqr;
    out[2] = -quat[2] / sqr;
    out[3] = quat[3] / sqr;
}

void hf_quatf_add(hf_quatf a, hf_quatf b, hf_quatf out) {
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
    out[3] = a[3] + b[3];
}

void hf_quatf_subtract(hf_quatf a, hf_quatf b, hf_quatf out) {
    out[0] = a[0] - b[0];
    out[1] = a[1] - b[1];
    out[2] = a[2] - b[2];
    out[3] = a[3] - b[3];
}

void hf_quatf_multiply(hf_quatf quat, float scalar, hf_quatf out) {
    out[0] = quat[0] * scalar;
    out[1] = quat[1] * scalar;
    out[2] = quat[2] * scalar;
    out[3] = quat[3] * scalar;
}

void hf_quatf_multiply_quatf(hf_quatf a, hf_quatf b, hf_quatf out) {
    hf_vec3f tmp;

    hf_vec3f av = { a[0], a[1], a[2] };
    hf_vec3f bv = { b[0], b[1], b[2] };

    hf_vec3f aux;
    hf_vec3f_multiply(av, b[3], tmp);
    hf_vec3f_multiply(bv, a[3], aux);
    hf_vec3f_add(tmp, aux, tmp);
    hf_vec3f_cross(av, bv, aux);
    hf_vec3f_add(tmp, aux, tmp);

    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
    out[3] = a[3] * b[3] - hf_vec3f_dot(av, bv);
}
