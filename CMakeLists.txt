project(hf_lib C)

set(hf_lib_sources
    hf_algorithm.c
    hf_intersection.c
    hf_line.c
    hf_path.c
    hf_string.c
    hf_transform.c
    hf_triangle.c
    hf_vec.c
)
list(TRANSFORM hf_lib_sources PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)
add_library(hf_lib ${hf_lib_sources})

option(hf_lib_test "If true, will build the test programs of hf_lib" false)

if(${CMAKE_C_COMPILER_ID} EQUAL MSVC)
    target_compile_options(hf_lib PRIVATE /D_CRT_SECURE_NO_WARNINGS)
else()
	target_compile_options(hf_lib PRIVATE -Wstrict-prototypes -Wconversion -Wall -Wextra -Wpedantic -pedantic -Werror)
endif()

enable_testing()

add_executable(hf_test_string  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_string.c)
target_link_libraries(hf_test_string PUBLIC hf_lib)
add_test(NAME hf_string COMMAND hf_test_string)

add_executable(hf_test_path  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_path.c)
target_link_libraries(hf_test_path PUBLIC hf_lib)
add_test(NAME hf_path COMMAND hf_test_path)
