//
// Created by Paul Hoehne on 9/20/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int SetUp(void **state);
int TearDown(void **state);
void Test0(void **state);

int SetUp(void **state) {
    return 0;
}

int TearDown(void **state) {
    return 0;
}

void Test0(void **state) {

}

int main(int argc, char **argv) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(Test0),
    };

    return cmocka_run_group_tests(tests, SetUp, TearDown);
}