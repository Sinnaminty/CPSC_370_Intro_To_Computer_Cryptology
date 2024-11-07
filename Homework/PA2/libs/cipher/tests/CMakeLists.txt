project(cipher_tests)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  libs::cipher
)

add_test(NAME Pass COMMAND ${PROJECT_NAME} pass)
add_test(NAME Fail COMMAND ${PROJECT_NAME} fail)
