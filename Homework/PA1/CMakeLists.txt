cmake_minimum_required(VERSION 3.5)
# PROJECT DESCRIPTION AND META INFO

set(PROJECT_NAME
  "PA1"
)
set(AUTHOR_DOMAIN
  "https://github.com/Sinnaminty/CPSC_370_Intro_To_Computer_Cryptology"
)
set(AUTHOR_MAINTAINER
  "aidenrivera7@gmail.com"
)
set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_PATCH "1")
set(PROJECT_VERSION
  "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
)
set(PROJECT_DESCRIPTION "Programming Assignment 1.")
set(PROJECT_LANGUAGES "CXX")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
# DECLARE PROJECT

project(${PROJECT_NAME})

add_subdirectory(libs)
add_subdirectory(app)
