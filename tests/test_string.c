#include <stdlib.h>

#include "../include/hf_string.h"

int main(int argc, char** argv) {
    if(!hf_string_equal("test_string", "test_string")) {
        return EXIT_FAILURE;
    }
    if(!hf_string_equal("çç", "çç")) {
        return EXIT_FAILURE;
    }

    if(hf_string_length_bytes("ç") != 2) {
        return EXIT_FAILURE;
    }

    char buffer[3];
    hf_string_copy(buffer, 3, "aç");
    if(hf_string_length_bytes(buffer) != 1) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}