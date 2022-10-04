enable_testing()

include_directories(${CMOCKA_INCLUDE_DIR})
link_directories(${CMOCKA_LIBRARY_DIR})
link_libraries(cmocka)
add_compile_options(-Wall -Werror -Wno-error=maybe-uninitialized)

set(CMAKE_C_FLAGS "-g -DUNIT_TESTING")

add_executable(hashingtest hashing_test.c ../hashing.c)
add_executable(equalitytest equality_test.c ../equality.c)
add_executable(copyingtest copying_test.c ../copying.c)
add_executable(hashmaptest hashmap_test.c ../hashmap.c ../copying.c ../equality.c ../hashing.c)
add_executable(internalstest internals_test.c ../internals.c)

add_test(NAME hashingtest COMMAND hashingtest)
add_test(NAME equalitytest COMMAND equalitytest)
add_test(NAME copyingtest COMMAND copyingtest)
add_test(NAME hashmaptest COMMAND hashmaptest)
add_test(NAME internalstest COMMAND internalstest)
