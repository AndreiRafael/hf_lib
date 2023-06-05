#include <stdlib.h>
#include <assert.h>

#include "../include/hf_path.h"
#include "../include/hf_string.h"

int main(int argc, char** argv) {
    char buffer[261];
    assert(hf_path_normalized("./////files/../pictures/picture.png", buffer, 261));

    assert(hf_string_equal(buffer, "./files/../pictures/picture.png"));
    return EXIT_SUCCESS;
}