//
// Created by Paul Hoehne on 9/20/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <hashmap.h>
#include <cmocka.h>

void testSimpleHash(void **state);

void testSimpleHash(void **state) {
    HASH_T expected = 5381 * 33 + 'a';

    assert_uint_equal(expected, StringHash("a"));
}

int main(int argc, char **argv) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(testSimpleHash),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}