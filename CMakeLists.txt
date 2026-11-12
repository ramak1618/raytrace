cmake_minimum_required(VERSION 3.30)

project(
    raytrace
    DESCRIPTION "A custom raytracer, that hopefully does raytracing..."
    VERSION 0.1
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)

find_library(FFCODEC_LIB NAMES avcodec REQUIRED)
find_library(FFUTIL_LIB NAMES avutil REQUIRED)
find_library(MATH_LIB NAMES m REQUIRED)

add_compile_options(-Wall -Wextra -Wpedantic) 

if(NOT CMAKE_BUILD_TYPE)
    add_compile_options(-O3)
else()
    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILDTYPE_LOWER)
    if(BUILDTYPE_LOWER STREQUAL "release")
        add_compile_options(-O3)
    elseif(BUILDTYPE_LOWER STREQUAL "debug")
        add_compile_options(-g -O0)
    elseif(BUILDTYPE_LOWER STREQUAL "asan")
        add_compile_options(-g -fsanitize=address -O0)
        add_link_options(-fsanitize=address)
    else()
        message(FATAL_ERROR "Unkown build type!")
    endif()
endif()

add_executable(vexpand src/vexpand.c)

add_custom_target(
        csrc ALL
        COMMAND vexpand ${CMAKE_SOURCE_DIR}/src/raycore/triangle.cx triangle.c
        COMMAND vexpand ${CMAKE_SOURCE_DIR}/src/raycore/camera.cx camera.c
        COMMAND vexpand ${CMAKE_SOURCE_DIR}/src/raycore/bbox.cx bbox.c
        COMMAND vexpand ${CMAKE_SOURCE_DIR}/src/raycore/shapes/icosphere.cx icosphere.c
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_library(raytrace SHARED 
        src/raycore/vecs.c
        src/raycore/utils/array.c
        external/pcg/pcg_basic.c 
        src/raycore/utils/random.c 
        ${CMAKE_BINARY_DIR}/triangle.c
        ${CMAKE_BINARY_DIR}/camera.c
        ${CMAKE_BINARY_DIR}/bbox.c
        ${CMAKE_BINARY_DIR}/icosphere.c
        src/raycore/encoder/ppm.c
        src/raycore/encoder/png.c
)
target_include_directories(raytrace PRIVATE include/ external/)
target_link_libraries(raytrace ${MATH_LIB} ${FFUTIL_LIB} ${FFCODEC_LIB})

target_sources(
        raytrace PUBLIC FILE_SET HEADERS
        BASE_DIRS include/
        FILES
        include/raycore/vecs.h
        include/raycore/utils/array.h
        include/raycore/utils/random.h
        include/raycore/colors.h
        include/raycore/triangle.h
        include/raycore/camera.h
        include/raycore/bbox.h
        include/raycore/shapes/icosphere.h
        include/raycore/encoder/ppm.h
        include/raycore/encoder/png.h
)
install(TARGETS vexpand RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}) 
install(TARGETS raytrace LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS raytrace FILE_SET HEADERS)
