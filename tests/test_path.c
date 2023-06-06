#include <stdlib.h>
#include <assert.h>

#include "../include/hf_path.h"
#include "../include/hf_string.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
    #define SEP "\\"
#elif defined(unix) || defined(__unix) || defined(__unix__)
    #define SEP "/"
#else
    #error "Unknown System"
#endif

int main(int argc, char** argv) {
    {//normalization tests
        char buffer[HF_PATH_MAX_PATH_LENGTH];
        assert(hf_path_normalize("./////fol/../pics/pic.png", buffer, HF_PATH_MAX_PATH_LENGTH));//.. simplification
        assert(hf_string_equal(buffer, "."SEP"pics"SEP"pic.png"));

        assert(hf_path_normalize("./../../pic.png", buffer, HF_PATH_MAX_PATH_LENGTH));//impossible .. simplification
        assert(hf_string_equal(buffer, ".."SEP".."SEP"pic.png"));// TODO: this should be actually normalized to ../../pic.png

        assert(hf_path_normalize("./././pic.png", buffer, HF_PATH_MAX_PATH_LENGTH));//redundant .
        assert(hf_string_equal(buffer, "."SEP"pic.png"));

        assert(hf_path_normalize("./fol/../../pic.png", buffer, HF_PATH_MAX_PATH_LENGTH));//redundant . because of ..
        assert(hf_string_equal(buffer, ".."SEP"pic.png"));
    }
    {
        char buffer[HF_PATH_MAX_PATH_LENGTH];
        assert(hf_path_parent("./fol/pics", buffer, HF_PATH_MAX_PATH_LENGTH));
        assert(hf_string_equal(buffer, "."SEP"fol"));
    }

    assert(hf_path_equal("./pic/pic.png", ".///pic////pic.png"));
    assert(hf_path_equal("./pic/pic.png", ".\\pic\\pic.png"));
    assert(hf_path_equal("./pic/pic.png", "./fol/../pic/pic.png"));
    return EXIT_SUCCESS;
}