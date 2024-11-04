project(cipher_tests)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  libs::cipher
)

add_test(NAME Encrypt COMMAND ${PROJECT_NAME} encrypt)
add_test(NAME Decrypt COMMAND ${PROJECT_NAME} decrypt)
