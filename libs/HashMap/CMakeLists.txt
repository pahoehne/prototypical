add_library(hashmap hashmap.c equality.c hashing.c copying.c internals.c internals.h)

enable_testing()
add_subdirectory(test)