cmake_minimum_required(VERSION 3.30)
 
project(
    icosphere_example
    DESCRIPTION "Render of icospheres of frequencies 8 and 4"
    LANGUAGES C
)

include(../template.cmake)
add_example(sphere)
