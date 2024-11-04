project(cipher_tests)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  libs::cipher
)

add_test(cipher_tests ${PROJECT_NAME})
