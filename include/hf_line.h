#ifndef HF_LINE_H
#define HF_LINE_H

#include <stdbool.h>
#include "hf_vec.h"

typedef struct HF_Line_s {
    HF_Vec2f start;
    HF_Vec2f end;
} HF_Line2f;

HF_Vec2f hf_line2f_closest_point(HF_Line2f line, HF_Vec2f point);
bool hf_line2f_intersection(HF_Line2f a, HF_Line2f b, HF_Vec2f* hit_point);

#endif//HF_LINE_H
