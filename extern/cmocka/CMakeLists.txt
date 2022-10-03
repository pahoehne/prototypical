include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR})

ExternalProject_Add(cmocka
        GIT_REPOSITORY https://gitlab.com/cmocka/cmocka.git
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        )