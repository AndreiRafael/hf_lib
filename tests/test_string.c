#include <stdlib.h>
#include <assert.h>

#include "../include/hf_string.h"

int main(int argc, char** argv) {
    assert(hf_string_equal("ascii", "ascii"));
    assert(hf_string_equal("caça", "caça"));
    assert(hf_string_equal("바나나", "바나나"));

    assert(hf_string_length_bytes("ççç") == 6);
    assert(hf_string_length_codepoints("ççç") == 3);

    assert(hf_string_length_bytes("바나나") == 9);
    assert(hf_string_length_codepoints("바나나") == 3);

    {
        char buffer[5];
        assert(!hf_string_copy("caça", buffer, 5));
        assert(hf_string_length_bytes(buffer) == 4);

        assert(!hf_string_copy("바나나", buffer, 5));
        assert(hf_string_length_bytes(buffer) == 3);
    }
    {
        char buffer[10];
        assert(hf_string_copy("바", buffer, 10));
        assert(hf_string_concat("ço", buffer, 10));
        assert(hf_string_equal(buffer, "바ço"));
        assert(hf_string_length_bytes(buffer) == 6);
        assert(hf_string_length_codepoints(buffer) == 3);

        assert(!hf_string_concat("바ço", buffer, 10));
        assert(hf_string_equal(buffer, "바ço바"));
        assert(hf_string_length_bytes(buffer) == 9);
        assert(hf_string_length_codepoints(buffer) == 4);
    }

    return EXIT_SUCCESS;
}