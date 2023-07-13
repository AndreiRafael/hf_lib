#include "../include/hf_line.h"
#include <math.h>

HF_Vec2f hf_line_closest_point(HF_Line line, HF_Vec2f point) {
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
