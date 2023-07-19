#ifndef HF_TRIANGLE_H
#define HF_TRIANGLE_H

#include <stdbool.h>
#include "hf_line.h"

typedef struct HF_Triangle_s {
    HF_Vec2f a;
    HF_Vec2f b;
    HF_Vec2f c;
} HF_Triangle;

HF_Vec2f hf_triangle_center(HF_Triangle triangle);
void     hf_triangle_get_edges(HF_Triangle triangle, HF_Line2f* edges_array);
bool     hf_triangle_is_point_inside(HF_Triangle triangle, HF_Vec2f point);
bool     hf_triangle_intersects(HF_Triangle a, HF_Triangle b, HF_Vec2f* hit_point);


#endif//HF_TRIANGLE_H
