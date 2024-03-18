cmake_minimum_required(VERSION 3.0.0)
project(project1 VERSION 0.1.0 LANGUAGES C CXX)
file(GLOB SOURCES "*.cpp" "*.h")

include(CTest)
enable_testing()

add_executable(project1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
