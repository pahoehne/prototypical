//
// Created by Paul Hoehne on 9/24/22.
//

#include <stdlib.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdarg.h>
#include <cmocka.h>

int main(int argc, char **argv) {
    const struct CMUnitTest tests [] = {

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}