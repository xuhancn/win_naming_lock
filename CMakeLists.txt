cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJ_NAME "lib_cnaming_lock")
project (${PROJ_NAME})

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})

set(CNAMING_LOCK_SRCS)
FILE(GLOB_RECURSE CNAMING_LOCK_SRCS ${PROJECT_ROOT_DIR}/srcs/*.cpp)
add_library(${PROJ_NAME} STATIC ${CNAMING_LOCK_SRCS})

set(EXAMPLE_NAME ${PROJ_NAME}_example)
set(CNAMING_LOCK_EXAMPLE)
FILE(GLOB_RECURSE CNAMING_LOCK_EXAMPLE ${PROJECT_ROOT_DIR}/example/*.cpp)
add_executable(${EXAMPLE_NAME} ${CNAMING_LOCK_EXAMPLE})

target_include_directories(${EXAMPLE_NAME} PRIVATE ${PROJECT_ROOT_DIR}/srcs/)
target_link_libraries(${EXAMPLE_NAME} PRIVATE ${PROJ_NAME})