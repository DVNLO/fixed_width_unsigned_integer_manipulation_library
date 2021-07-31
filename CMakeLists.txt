cmake_minimum_required(VERSION 3.16.3)

# https://cmake.org/cmake/help/v3.21/command/set.html#command:set
set(FWUIM_LIB_PROJ_NAME "fixed_width_unsigned_integer_manipulation_library")
set(FWUIM_LIB_TARGET "fwuim")

# https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
set(FWUIM_LIB_COMPILE_OPTIONS 
    "-march=native"
    "-pipe"
    "-O3"
    "-fwhole-program"
    "-fgcse-las"
    "-fno-common"
    "-fno-ipa-sra"
    "-fno-merge-constants"
    "-fno-inline-functions-called-once"
    "-funroll-loops"
    "-fstrict-overflow")

set(FWUIM_LIB_COMPILE_WARNINGS 
    "-Wall"
    "-Walloc-zero"
    "-Walloca"
    "-Wattribute-alias=2"
    "-Wc++-compat"
    "-Wcast-align"
    "-Wdouble-promotion"
    "-Wduplicated-branches"
    "-Wduplicated-cond"
    "-Wempty-body"
    "-Werror"
    "-Wexpansion-to-defined"
    "-Wextra"
    "-Wfloat-equal"
    "-Wformat-overflow"
    "-Wformat-security"
    "-Wformat-signedness"
    "-Wformat-truncation"
    "-Winit-self"
    "-Wjump-misses-init"
    "-Wnull-dereference"
    "-Wopenmp-simd"
    "-Woverride-init"
    "-Wpedantic"
    "-Wpointer-arith"
    "-Wshadow"
    "-Wstack-protector"
    "-Wstringop-overflow=2"
    "-Wswitch-default"
    "-Wswitch-enum"
    "-Wundef"
    "-Wunknown-pragmas"
    "-Wunsafe-loop-optimizations"
    "-Wunused"
    "-Wunused-but-set-parameter"
    "-Wunused-but-set-variable"
    "-Wunused-function"
    "-Wunused-label"
    "-Wunused-local-typedefs"
    "-Wunused-macros"
    "-Wunused-parameter"
    "-Wunused-value"
    "-Wunused-variable"
    "-Wunused-variable")

# https://cmake.org/cmake/help/latest/command/project.html#command:project
project(${FWUIM_LIB_PROJ_NAME}
        VERSION 0.0.0.1
        DESCRIPTION "A library for manipulating fixed width unsigned integer types."
        HOMEPAGE_URL "https://github.com/DVNLO/fixed_width_unsigned_integer_manipulation_library"
        LANGUAGES C
)

# https://cmake.org/cmake/help/latest/command/add_library.html
add_library(${FWUIM_LIB_TARGET} 
    STATIC 
        ${PROJECT_SOURCE_DIR}/source/uint8.c
        ${PROJECT_SOURCE_DIR}/source/uint16.c
        ${PROJECT_SOURCE_DIR}/source/uint32.c
        ${PROJECT_SOURCE_DIR}/source/uint64.c
)

# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${FWUIM_LIB_TARGET} 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD.html
set_property(TARGET ${FWUIM_LIB_TARGET} PROPERTY C_STANDARD 11)

# https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD_REQUIRED.html
set_property(TARGET ${FWUIM_LIB_TARGET} PROPERTY C_STANDARD_REQUIRED ON)

# https://cmake.org/cmake/help/latest/command/target_compile_options.html#command:target_compile_options
target_compile_options(${FWUIM_LIB_TARGET} PUBLIC ${FWUIM_LIB_COMPILE_OPTIONS})
target_compile_options(${FWUIM_LIB_TARGET} PUBLIC ${FWUIM_LIB_COMPILE_WARNINGS})
