find_package(CMocka REQUIRED PATHS ${CMAKE_SOURCE_DIR}/extern/cmocka)

set(CMOCKA_HOME_DIR ${CMAKE_SOURCE_DIR}/extern/cmocka)
set(CMOCKA_INCLUDE_DIR ${CMOCKA_HOME_DIR}/include)
set(CMOCKA_LIBRARY_DIR ${CMOCKA_HOME_DIR}/lib)

include_directories(inc)
add_subdirectory(HashMap)
