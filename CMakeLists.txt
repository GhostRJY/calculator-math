cmake_minimum_required(VERSION 3.22)

project(calculator_math VERSION 1.0 LANGUAGES CXX)

add_library(calculator_math INTERFACE)
add_library(calculator_math::calculator_math ALIAS calculator_math)

target_include_directories(
    calculator_math
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(
    calculator_math
    INTERFACE
        cxx_std_20
)

find_program(CLANG_FORMAT_PATH NAMES clang-format-21 REQUIRED)

file(
    GLOB_RECURSE FORMAT_FILES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_custom_target(
    format
    COMMAND ${CLANG_FORMAT_PATH} -i ${FORMAT_FILES}
    COMMENT "Running clang-format"
)

install(
    DIRECTORY include/
    DESTINATION include
)

install(
    TARGETS calculator_math
    EXPORT calculator_math_targets
)

install(
    EXPORT calculator_math_targets
    NAMESPACE calculator_math::
    DESTINATION lib/cmake/calculator_math
)
