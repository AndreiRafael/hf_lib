#ifndef HF_LINE_H
#define HF_LINE_H

#include <stdbool.h>
#include "hf_vec.h"

void hf_line2f_closest_point(HF_Vec2f start, HF_Vec2f end, HF_Vec2f point, HF_Vec2f out);
bool hf_line2f_intersection(HF_Vec2f a_start, HF_Vec2f a_end, HF_Vec2f b_start, HF_Vec2f b_end, HF_Vec2f out);

#endif//HF_LINE_H
