set(hf_lib_sources
    hf_algorithm.c
    hf_intersection.c
    hf_line.c
    hf_path.c
    hf_transform.c
    hf_triangle.c
    hf_vec.c
)
list(TRANSFORM hf_lib_sources PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)
add_library(hf_lib ${hf_lib_sources})

if(${CMAKE_C_COMPILER_ID} EQUAL MSVC)
    target_compile_options(hf_lib PRIVATE /D_CRT_SECURE_NO_WARNINGS)
else()
	target_compile_options(hf_lib PRIVATE -Wstrict-prototypes -Wconversion -Wall -Wextra -Wpedantic -pedantic -Werror)
endif()
