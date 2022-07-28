cmake_minimum_required(VERSION 3.0)

project(
    synapse-bootstrapper-shell
    VERSION 0.1.0
    LANGUAGES C
)

file(
    GLOB_RECURSE 
    src_synapse_bootstrapper_shell 
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_library(
    synapse_bootstrapper_shell
    MODULE
    ${src_synapse_bootstrapper_shell}
)

target_include_directories(
    synapse_bootstrapper_shell
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_options(
    synapse_bootstrapper_shell
    PUBLIC
    /Dsynapse_shell_export_mode
)

target_link_libraries(
    synapse_bootstrapper_shell
    synapse_memory_dll
    synapse_component_dll
    synapse_messaging_dll
    synapse_modules_dll
    synapse_structure_dll
)