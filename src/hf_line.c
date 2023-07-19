#include "../include/hf_line.h"
#include <math.h>

HF_Vec2f hf_line2f_closest_point(HF_Line2f line, HF_Vec2f point) {
    HF_Vec2f line_vec = hf_vec2f_subtract(line.end, line.start);
    HF_Vec2f point_vec = hf_vec2f_subtract(point, line.start);

    float dot = hf_vec2f_dot(line_vec, point_vec);
    float lerp = dot / hf_vec2f_sqr_magnitude(line_vec);

    if(lerp < 0.f) {
        return line.start;
    }
    else if(lerp > 1.f) {
        return line.end;
    }
    return hf_vec2f_add(line.start, hf_vec2f_multiply(line_vec, lerp));
}

bool hf_line2f_intersection(HF_Line2f a, HF_Line2f b, HF_Vec2f* hit_point) {
    //line overlap algorithm:
    //1. check if lines overlap
    //2. check if second line would intersect an infinite first line
    HF_Vec2f a_vec = hf_vec2f_subtract(a.end, a.start);
    {//use dot to check if a is between the points of b
        HF_Vec2f a_vec90 = { a_vec.y, -a_vec.x };//a vector but rotated by 90 degrees

        bool dot1 = hf_vec2f_dot(a_vec90, hf_vec2f_subtract(b.start, a.start)) > 0.f;
        bool dot2 = hf_vec2f_dot(a_vec90, hf_vec2f_subtract(b.end, a.start)) > 0.f;

        if(dot1 == dot2) {//it both dot products are the same signal, it means no intersection can occur
            return false;
        }
    }

    HF_Vec2f b_vec = hf_vec2f_subtract(b.end, b.start);
    {//use dot to check if b is between the points of a
        HF_Vec2f b_vec90 = { b_vec.y, -b_vec.x };//b vector but rotated by 90 degrees

        bool dot1 = hf_vec2f_dot(b_vec90, hf_vec2f_subtract(a.start, b.start)) > 0.f;
        bool dot2 = hf_vec2f_dot(b_vec90, hf_vec2f_subtract(a.end,   b.start)) > 0.f;

        if(dot1 == dot2) {
            return false;
        }
    }

    if(hit_point) {
        *hit_point = hf_line2f_closest_point(a, b.start);
    }
    return true;
}
