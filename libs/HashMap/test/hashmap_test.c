//
// Created by Paul Hoehne on 9/23/22.
//

#include <hashmap.h>

#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

void testHashmapNew(void** state) {
    pHashMap map = HashMap_New(StringHash, SimpleEquals, BytewiseCopy);
    assert_non_null(map);

    HashMap_Free(map);
}

int main(int argc, char **argv) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(testHashmapNew),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}