cmake_minimum_required(VERSION 3.5)
# PROJECT DESCRIPTION AND META INFO

set(PROJECT_NAME
  "S-AES"
)

set(PROJECT_LANGUAGES "CXX")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# DECLARE PROJECT

project(${PROJECT_NAME})

include(CTest)

add_subdirectory(libs)
add_subdirectory(app)
