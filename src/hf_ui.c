#include "../include/hf_ui.h"
#include "../include/hf_transform.h"

#include <stdlib.h>

void hf_ui_element_reset(hf_ui_element* element) {
    element->parent = NULL;
    hf_vec2f_copy((hf_vec2f) { 0.f, 0.f }, element->position);
    hf_vec2f_copy((hf_vec2f) { 1.f, 1.f }, element->size);
    hf_vec2f_copy((hf_vec2f) { 0.5f, 0.5f }, element->pivot);
    hf_vec2f_copy((hf_vec2f) { 0.5f, 0.5f }, element->anchor);
    element->rotation = 0.f;
}

void hf_ui_element_transform(hf_ui_element* element, hf_mat3f out_matrix) {
    hf_transform2f_translation((hf_vec2f) { -element->pivot[0] * element->size[0], -element->pivot[1] * element->size[1] }, out_matrix);//pivot transformation
    hf_mat3f aux;
    hf_transform2f_rotation(element->rotation, aux);
    hf_mat3f_multiply_mat3f(out_matrix, aux, out_matrix);
    hf_transform2f_translation(element->position, aux);//position transformation
    hf_mat3f_multiply_mat3f(out_matrix, aux, out_matrix);
    if(element->parent) {
        hf_transform2f_translation((hf_vec2f) { element->anchor[0] * element->parent->size[0], element->anchor[1] * element->parent->size[1] }, aux);//anchor transformation
        hf_mat3f_multiply_mat3f(out_matrix, aux, out_matrix);
        hf_ui_element_transform(element->parent, aux);//parent based transformation
        hf_mat3f_multiply_mat3f(out_matrix, aux, out_matrix);
    }
}

void hf_ui_canvas_transform(hf_ui_canvas* canvas, hf_mat3f out_matrix) {
    hf_mat3f_identity(out_matrix);
    out_matrix[0][0] = (canvas->right - canvas->left) / canvas->w;
    out_matrix[1][1] = (canvas->top - canvas->bottom) / canvas->h;
    out_matrix[1][1] = canvas->left;
    out_matrix[1][1] = canvas->bottom;
}
