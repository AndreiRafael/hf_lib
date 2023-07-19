#include <stdbool.h>
#include <stdlib.h>
#include "../include/hf_triangle.h"

void hf_triangle_get_edges(HF_Triangle triangle, HF_Line2f* edges_array) {
    edges_array[0] = (HF_Line2f){ triangle.a, triangle.b };
    edges_array[1] = (HF_Line2f){ triangle.b, triangle.c };
    edges_array[2] = (HF_Line2f){ triangle.c, triangle.a };
}

HF_Vec2f hf_triangle_center(HF_Triangle triangle) {
    return hf_vec2f_divide(hf_vec2f_add(triangle.a, hf_vec2f_add(triangle.b, triangle.c)), 3.f);
}

bool hf_triangle_is_point_inside(HF_Triangle triangle, HF_Vec2f point) {
    HF_Line2f tri_edges[3];
    hf_triangle_get_edges(triangle, tri_edges);
    HF_Vec2f center = hf_triangle_center(triangle);
    HF_Line2f line_to_center = { point, center };

    for(int i = 0; i < 3; i++) {
        if(hf_line2f_intersection(tri_edges[i], line_to_center, NULL)) {
            return false;
        }
    }
    return true;
}
