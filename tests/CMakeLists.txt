add_executable(test_quux test_quux.cc)
target_link_libraries(test_quux quux)
add_test(NAME test_quux COMMAND $<TARGET_FILE:test_quux>)
