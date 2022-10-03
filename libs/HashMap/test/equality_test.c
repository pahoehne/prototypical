//
// Created by Paul Hoehne on 9/22/22.
//

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <hashmap.h>

void stringEqualsTest(void **state);

void stringEqualsTest(void **state) {
    const char* str1 = "foo";
    const char* str2 = "bar";
    const char* str3 = "foo";

    assert_true(SimpleEquals(str1, str3));
    assert_false(SimpleEquals(str1, str2));
}

int main(int argc, char **argv) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(stringEqualsTest),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}