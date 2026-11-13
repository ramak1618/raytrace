macro(add_example SRC_BASE_NAME) 
    set(CMAKE_C_STANDARD 99)
    set(CMAKE_C_EXTENSIONS OFF)

    find_program(VEXPAND vexpand REQUIRED)
    find_library(RAYTRACE_LIB NAMES raytrace REQUIRED)
    find_path(RAYTRACE_HEADERS NAMES raycore/ REQUIRED) 

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

    string(CONCAT XSRC ${SRC_BASE_NAME} ".cx")
    string(CONCAT CSRC ${SRC_BASE_NAME} ".c")
    string(CONCAT OUT  ${SRC_BASE_NAME} ".o")

    add_custom_command(
            OUTPUT ${CSRC}
            COMMAND ${VEXPAND} ${CMAKE_SOURCE_DIR}/${XSRC} ${CSRC}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

    add_executable(${OUT} ${CSRC})
    target_include_directories(${OUT} PRIVATE ${RAYTRACE_HEADERS})
    target_link_libraries(${OUT} ${RAYTRACE_LIB})

    add_custom_target(
            img ALL
            COMMAND ${CMAKE_BINARY_DIR}/${OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endmacro()
