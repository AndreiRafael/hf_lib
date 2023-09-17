#include "../include/hf_line.h"
#include <math.h>

void hf_line2f_closest_point(HF_Line2f line, HF_Vec2f point, HF_Vec2f out) {
    HF_Vec2f line_vec;
    HF_Vec2f point_vec;
    hf_vec2f_subtract(line.end, line.start, line_vec);
    hf_vec2f_subtract(point, line.start, point_vec);

    float dot = hf_vec2f_dot(line_vec, point_vec);
    float lerp = dot / hf_vec2f_square_magnitude(line_vec);

    if(lerp < 0.f) {
        hf_vec2f_copy(line.start, out);
        return;
    }
    else if(lerp > 1.f) {
        hf_vec2f_copy(line.end, out);
        return;
    }
    hf_vec2f_multiply(line_vec, lerp, out);
    hf_vec2f_add(line.start, out, out);
}

bool hf_line2f_intersection(HF_Line2f a, HF_Line2f b, HF_Vec2f out) {
    HF_Vec2f a_vec;
    hf_vec2f_subtract(a.end, a.start, a_vec);
    {//use dot to check if a is between the points of b
        HF_Vec2f a_vec90 = { a_vec[1], -a_vec[0] };//a vector but rotated by 90 degrees

        HF_Vec2f bs_as;
        hf_vec2f_subtract(b.start, a.start, bs_as);
        HF_Vec2f be_as;
        hf_vec2f_subtract(b.end, a.start, bs_as);

        bool dot1 = hf_vec2f_dot(a_vec90, bs_as) > 0.f;
        bool dot2 = hf_vec2f_dot(a_vec90, be_as) > 0.f;

        if(dot1 == dot2) {//it both dot products are the same signal, it means no intersection can occur
            return false;
        }
    }

    HF_Vec2f b_vec;
    hf_vec2f_subtract(b.end, b.start, b_vec);
    {//use dot to check if b is between the points of a
        HF_Vec2f b_vec90 = { b_vec[1], -b_vec[0] };//b vector but rotated by 90 degrees

        HF_Vec2f as_bs;
        hf_vec2f_subtract(b.start, a.start, as_bs);
        HF_Vec2f ae_bs;
        hf_vec2f_subtract(b.end, a.start, ae_bs);

        bool dot1 = hf_vec2f_dot(b_vec90, as_bs) > 0.f;
        bool dot2 = hf_vec2f_dot(b_vec90, ae_bs) > 0.f;

        if(dot1 == dot2) {
            return false;
        }
    }

    if(out) {
        float a_run = (a.end[0] - a.start[0]);
        float b_run = (b.end[0] - b.start[0]);

        if(a_run == 0.f) {//a is straight up
            float b_slope = (b.end[1] - b.start[1]) / b_run;
            float b_start_y = b.start[1] + (b_slope * -b.start[0]);

            out[0] = a.start[0];
            out[1] = b_slope * a.start[0] + b_start_y;
        }
        else if(b_run == 0.f) {//b is straight up
            float a_slope = (a.end[1] - a.start[1]) / a_run;
            float a_start_y = a.start[1] + (a_slope * -a.start[0]);

            out[0] = b.start[0];
            out[1] = a_slope * b.start[0] + a_start_y;
        }
        else {//normal equation
            float a_slope = (a.end[1] - a.start[1]) / a_run;
            float b_slope = (b.end[1] - b.start[1]) / b_run;

            float a_start_y = a.start[1] + (a_slope * -a.start[0]);
            float b_start_y = b.start[1] + (b_slope * -b.start[0]);

            float x = (b_start_y - a_start_y) / (a_slope - b_slope);
            out[0] = x;
            out[0] = a_slope * x + a_start_y;
        }
    }
    return true;
}
