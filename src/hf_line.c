#include "../include/hf_line.h"
#include <math.h>

float hf_line2f_projection(hf_vec2f start, hf_vec2f end, hf_vec2f point) {
    hf_vec2f line_vec;
    hf_vec2f point_vec;
    hf_vec2f_subtract(end, start, line_vec);
    hf_vec2f_subtract(point, start, point_vec);

    float dot = hf_vec2f_dot(line_vec, point_vec);
    return dot / hf_vec2f_square_magnitude(line_vec);
}

void hf_line2f_closest_point(hf_vec2f start, hf_vec2f end, hf_vec2f point, hf_vec2f out) {
    float lerp = hf_line2f_projection(start, end, point);

    if(lerp < 0.f) {
        hf_vec2f_copy(start, out);
        return;
    }
    else if(lerp > 1.f) {
        hf_vec2f_copy(end, out);
        return;
    }

    hf_vec2f line_vec;
    hf_vec2f_subtract(end, start, line_vec);
    hf_vec2f_multiply(line_vec, lerp, out);
    hf_vec2f_add(start, out, out);
}

bool hf_line2f_intersection(hf_vec2f a_start, hf_vec2f a_end, hf_vec2f b_start, hf_vec2f b_end, hf_vec2f out) {
    hf_vec2f a_vec;
    hf_vec2f_subtract(a_end, a_start, a_vec);
    {//use dot to check if a is between the points of b
        hf_vec2f a_vec90 = { a_vec[1], -a_vec[0] };//a vector but rotated by 90 degrees

        hf_vec2f bs_as;
        hf_vec2f_subtract(b_start, a_start, bs_as);
        hf_vec2f be_as;
        hf_vec2f_subtract(b_end, a_start, be_as);

        bool dot1 = hf_vec2f_dot(a_vec90, bs_as) > 0.f;
        bool dot2 = hf_vec2f_dot(a_vec90, be_as) > 0.f;

        if(dot1 == dot2) {//it both dot products are the same signal, it means no intersection can occur
            return false;
        }
    }

    hf_vec2f b_vec;
    hf_vec2f_subtract(b_end, b_start, b_vec);
    {//use dot to check if b is between the points of a
        hf_vec2f b_vec90 = { b_vec[1], -b_vec[0] };//b vector but rotated by 90 degrees

        hf_vec2f as_bs;
        hf_vec2f_subtract(a_start, b_start, as_bs);
        hf_vec2f ae_bs;
        hf_vec2f_subtract(a_end, b_start, ae_bs);

        bool dot1 = hf_vec2f_dot(b_vec90, as_bs) > 0.f;
        bool dot2 = hf_vec2f_dot(b_vec90, ae_bs) > 0.f;

        if(dot1 == dot2) {
            return false;
        }
    }

    if(out) {
        float a_run = (a_end[0] - a_start[0]);
        float b_run = (b_end[0] - b_start[0]);

        if(a_run == 0.f) {//a is straight up
            float b_slope = (b_end[1] - b_start[1]) / b_run;
            float b_start_y = b_start[1] + (b_slope * -b_start[0]);

            out[0] = a_start[0];
            out[1] = b_slope * a_start[0] + b_start_y;
        }
        else if(b_run == 0.f) {//b is straight up
            float a_slope = (a_end[1] - a_start[1]) / a_run;
            float a_start_y = a_start[1] + (a_slope * -a_start[0]);

            out[0] = b_start[0];
            out[1] = a_slope * b_start[0] + a_start_y;
        }
        else {//normal equation
            float a_slope = (a_end[1] - a_start[1]) / a_run;
            float b_slope = (b_end[1] - b_start[1]) / b_run;

            float a_start_y = a_start[1] + (a_slope * -a_start[0]);
            float b_start_y = b_start[1] + (b_slope * -b_start[0]);

            float x = (b_start_y - a_start_y) / (a_slope - b_slope);
            out[0] = x;
            out[0] = a_slope * x + a_start_y;
        }
    }
    return true;
}
