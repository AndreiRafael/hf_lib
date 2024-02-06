#ifndef HF_LINE_H
#define HF_LINE_H

#include <stdbool.h>
#include "hf_vec.h"

float hf_line2f_projection(hf_vec2f start, hf_vec2f end, hf_vec2f point);
void hf_line2f_closest_point(hf_vec2f start, hf_vec2f end, hf_vec2f point, hf_vec2f out);
bool hf_line2f_intersection(hf_vec2f a_start, hf_vec2f a_end, hf_vec2f b_start, hf_vec2f b_end, hf_vec2f out);

#endif//HF_LINE_H
